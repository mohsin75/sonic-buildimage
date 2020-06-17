from .health_checker import HealthChecker
from .utils import run_command


class ExternalChecker(HealthChecker):
    def __init__(self, cmd):
        HealthChecker.__init__(self)
        self._cmd = cmd
        self._category = None

    def reset(self):
        self._category = 'External'
        self._info = {}

    def get_category(self):
        return self._category

    def check(self, config):
        self.reset()

        output = run_command(self._cmd)
        if not output:
            self.set_object_not_ok('External', str(self), 'Failed to get output of command \"{}\"'.format(self._cmd))
            return

        lines = output.splitlines()
        if not lines:
            self.set_object_not_ok('External', str(self), 'Invalid output of command \"{}\"'.format(self._cmd))
            return

        self._category = lines[0]
        if len(lines) > 1:
            for line in lines[1:]:
                line = line.strip()
                if not line:
                    continue
                pos = line.find(':')
                if pos == -1:
                    continue
                obj_name = line[:pos]
                msg = line[pos+1:]
                if msg != 'OK':
                    self.set_object_not_ok('External', obj_name, msg)
                else:
                    self.set_object_ok('External', obj_name)
        return

    def __str__(self):
        return 'ExternalChecker - {}'.format(self._cmd)
