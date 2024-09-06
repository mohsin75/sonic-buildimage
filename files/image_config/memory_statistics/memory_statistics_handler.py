import gzip
import psutil
import os
import sys
import signal
import time
import threading
import configparser
import logging
from swsscommon.swsscommon import ConfigDBConnector

class Logger:
    """
    A simple logging utility class for handling log messages.

    This class provides a flexible logging setup with options to log messages
    to a file and/or to the console. It supports various logging levels and
    formats for log messages.
    """

    def __init__(self, log_file, log_level=logging.INFO, log_console=False):
        """
        Initializes the Logger instance.

        Args:
            log_file (str): Path to the log file.
            log_level (int): Logging level (default is logging.INFO).
            log_console (bool): Whether to log messages to the console (default is False).
        """
        self.log_file = log_file
        self.log_level = log_level
        self.log_console = log_console
        self.logger = logging.getLogger(__name__)
        self.logger.setLevel(log_level)

        # Create file handler
        file_handler = logging.FileHandler(self.log_file)
        file_handler.setLevel(log_level)

        # Create console handler if needed
        if log_console:
            console_handler = logging.StreamHandler()
            console_handler.setLevel(log_level)
            self.logger.addHandler(console_handler)

        # Create formatter and set it for handlers
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        file_handler.setFormatter(formatter)
        if log_console:
            console_handler.setFormatter(formatter)

        # Add handlers to the logger
        self.logger.addHandler(file_handler)

    def log(self, message, level=logging.INFO):
        """
        Logs a message with the specified severity level.

        Args:
            message (str): The message to log.
            level (int): The severity level of the log message. Default is logging.INFO.
        """
        {
            logging.DEBUG: self.logger.debug,
            logging.INFO: self.logger.info,
            logging.WARNING: self.logger.warning,
            logging.ERROR: self.logger.error,
            logging.CRITICAL: self.logger.critical,
        }.get(level, self.logger.info)(message)

class MemoryStatisticsDaemon:
    """
    Memory Statistics Daemon
    Responsible for collecting and storing memory usage statistics.
    1) Handle enabling or disabling the daemon via ConfigDB.
    2) Collect memory statistics at a configurable sampling interval.
    3) Handle retention of memory logs, deleting old logs when necessary.
    4) Respond to signals for reloading config (SIGHUP) and shutdown (SIGTERM).
    """

    def __init__(self):
        """git
        Initialize the MemoryStatisticsDaemon.
        Sets up directories, log files, and loads default settings.
        Also sets up signal handling for reloading and shutdown events.
        """
        self.hdir = "/var/log/memory_statistics"
        self.filename = os.path.join(self.hdir, "memory-statistics.log.gz")
        self.log_file = "/var/log/memory_statistics_daemon.log"
        self.initial_enable_state = False  # Initial enable state (default: disabled)
        self.logger = Logger(self.log_file, log_console=False)  # Initialize logger
        os.makedirs(self.hdir, exist_ok=True)  # Ensure memory statistics directory exists

        # Set up threading events to control running, reloading, and shutdown behavior
        self.running = threading.Event()
        self.reloading = threading.Event()
        self.shutdown_event = threading.Event()

        # Setup signal handlers for SIGHUP (reload) and SIGTERM (shutdown)
        signal.signal(signal.SIGHUP, self.handle_sighup)
        signal.signal(signal.SIGTERM, self.handle_sigterm)

    def load_default_settings(self):
        """
        Load default settings from the config file.
        If no config file is found, fallback values are used.
        """
        config = configparser.ConfigParser()
        config.read('/etc/memory_statistics.conf')  # Read configuration from the config file
        self.retention_period = config.getint('default', 'retention_period', fallback=15)  # Default retention period
        self.sampling_interval = config.getint('default', 'sampling_interval', fallback=5)  # Default sampling interval

    def load_config_from_db(self):
        """
        Load runtime configuration from the ConfigDB.
        Retrieves enable/disable state, retention period, and sampling interval.
        """
        self.config_db = ConfigDBConnector()
        self.config_db.connect()  # Connect to ConfigDB

        try:
            config = self.config_db.get_table('MEMORY_STATISTICS_TABLE')  # Get memory statistics config table

            # Update retention period and sampling interval with values from the database
            self.retention_period = int(config.get('retention-period', self.retention_period))
            self.sampling_interval = int(config.get('sampling-interval', self.sampling_interval))

            # Check if the daemon should be enabled or disabled
            enable_state = config.get('enable', 'false').lower() == 'true'
            if not enable_state:
                self.logger.log("Received disable command, shutting down daemon.", logging.INFO)
                self.handle_sigterm(None, None)

            self.logger.log("Configuration reloaded from ConfigDB.", logging.INFO)
        except Exception as e:
            self.logger.log(f"Error loading configuration from ConfigDB: {e}", logging.ERROR)
            raise

    def handle_sighup(self, signum, frame):
        """
        Handle the SIGHUP signal for reloading configuration.
        This sets the reloading flag to reload settings from the ConfigDB.
        """
        self.logger.log("Received SIGHUP, reloading configuration.", logging.INFO)
        self.reloading.set()  # Trigger reload

    def handle_sigterm(self, signum, frame):
        """
        Handle the SIGTERM signal for graceful shutdown.
        This sets the shutdown event to stop the daemon's operation cleanly.
        """
        self.logger.log("Received SIGTERM, shutting down gracefully.", logging.INFO)
        self.shutdown_event.set()  # Trigger shutdown

    def cleanup_old_files(self):
        """
        Clean up old memory statistics log files.
        Removes the current log file if it exists.
        """
        if os.path.exists(self.filename):  # Check if the log file exists
            try:
                os.remove(self.filename)  # Remove the log file
                self.logger.log(f"Deleted old log file: {self.filename}", logging.INFO)
            except Exception as e:
                # Log any errors that occur during file deletion
                self.logger.log(f"Error deleting old log file: {e}", logging.ERROR)

    def collect_and_store_memory_statistics(self):
        """
        Main function for collecting and storing memory statistics.
        Runs periodically based on the sampling interval and handles reloading config if needed.
        """
        while not self.shutdown_event.is_set():  # Run loop until shutdown event is triggered
            if self.reloading.is_set():  # If reloading is requested
                self.reloading.clear()  # Clear the reload flag
                self.cleanup_old_files()  # Clean up old logs
                self.load_config_from_db()  # Reload configuration from ConfigDB
                continue  # Skip to the next loop iteration
            
            try:
                # Collect and store memory statistics
                memory_statistics = self.get_memory_statistics()  # Fetch memory statistics
                self.store_memory_statistics(memory_statistics)  # Save memory statistics to file
            except Exception as e:
                # Log any errors during the collection or storage process
                self.logger.log(f"Error collecting or storing memory statistics: {e}", logging.ERROR)

            # Wait for the sampling interval before collecting statistics again
            self.shutdown_event.wait(self.sampling_interval)

    def get_memory_statistics(self):
        """
        Collect the system memory statistics using psutil.
        Returns a dictionary with various memory statistics.
        """
        memdict = psutil.virtual_memory() # Collect system memory information
        memory_statistics = {
            'total_memory': memdict.total,
            'used_memory': memdict.used,
            'free_memory': memdict.free,
            'available_memory': memdict.available,
            'cached_memory': memdict.cached,
            'buffer_memory': memdict.buffers,
            'shared_memory': memdict.shared
        }
        return memory_statistics

    def store_memory_statistics(self, memory_statistics):
        """
        Store the collected memory statistics in the log file.
        Logs any errors if file writing fails.
        """
        try:
            with gzip.open(self.filename, 'at') as f:  # Open the log file in append mode with gzip compression
                f.write(f"{memory_statistics}\n")  # Write the memory statistics to the log
            self.logger.log(f"Stored memory statistics: {memory_statistics}", logging.INFO)  # Log successful write
        except Exception as e:
            # Log any errors that occur while writing to the log file
            self.logger.log(f"Error writing memory statistics to log file: {e}", logging.ERROR)

    def run(self):
        """
        Start the MemoryStatisticsDaemon.
        Initiates the memory collection process if enabled and waits for shutdown or reload events.
        """
        self.logger.log("Memory statistics daemon started.", logging.INFO)

        if self.initial_enable_state:  # Check if the daemon is initially enabled
            # Start the memory statistics collection in a separate thread
            memory_thread = threading.Thread(target=self.collect_and_store_memory_statistics)
            memory_thread.daemon = True  # Make thread a daemon so it exits when main thread exits
            memory_thread.start()

            # Main thread loop: Wait for shutdown event, running at 1-second intervals
            while not self.shutdown_event.is_set():
                time.sleep(1)

            memory_thread.join()  # Wait for memory collection thread to finish

        self.logger.log("Memory statistics daemon stopped.", logging.INFO)  # Log shutdown