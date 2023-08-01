import libyang as ly
import syslog
import os

import click
from json import dump
from glob import glob
from sonic_yang_ext import SonicYangExtMixin, SonicYangException

from libyang import (
    Context,
    Extension,
    IfFeature,
    IfOrFeatures,
    IOType,
    LibyangError,
    Module,
    Revision,
    SContainer,
    SLeaf,
    SLeafList,
    SList,
    SNode,
    SRpc,
    Type,
)

"""
Yang schema and data tree python APIs based on libyang python
Here, sonic_yang_ext_mixin extends funtionality of sonic_yang,
i.e. it is mixin not parent class.
"""
class SonicYang(SonicYangExtMixin):

    def __init__(self, yang_dir, debug=False, print_log_enabled=True, sonic_yang_options=0):
        self.yang_dir = yang_dir
        self.ctx = None
        self.module = None
        self.root = None
        self.backlinks = dict()

        # logging vars
        self.SYSLOG_IDENTIFIER = "sonic_yang"
        self.DEBUG = debug
        self.print_log_enabled = print_log_enabled

        self.ctx = ly.Context(yang_dir)

        if not print_log_enabled:
            # The default libyang log options are ly.LY_LOLOG|ly.LY_LOSTORE_LAST.
            # Removing ly.LY_LOLOG will stop libyang from printing the logs.
            ly.set_log_options(ly.LY_LOSTORE_LAST)

        # yang model files, need this map it to module
        self.yangFiles = list()
        # map from TABLE in config DB to container and module
        self.confDbYangMap = dict()
        # JSON format of yang model [similar to pyang conversion]
        self.yJson = list()
        # config DB json input, will be cropped as yang models
        self.jIn = dict()
        # YANG JSON, this is traslated from config DB json
        self.xlateJson = dict()
        # reverse translation from yang JSON, == config db json
        self.revXlateJson = dict()
        # below dict store the input config tables which have no YANG models
        self.tablesWithOutYang = dict()
        # below dict will store preProcessed yang objects, which may be needed by
        # all yang modules, such as grouping.
        self.preProcessedYang = dict()
        # element path for CONFIG DB. An example for this list could be:
        # ['PORT', 'Ethernet0', 'speed']
        self.elementPath = []
        try:
            self.ctx = ly.Context(yang_dir)
        except Exception as e:
            self.fail(e)

        return

    def __del__(self):
        pass

    def sysLog(self, debug=syslog.LOG_INFO, msg=None, doPrint=False):
        # log debug only if enabled
        if self.DEBUG == False and debug == syslog.LOG_DEBUG:
            return
        if doPrint and self.print_log_enabled:
            print("{}({}):{}".format(self.SYSLOG_IDENTIFIER, debug, msg))
        syslog.openlog(self.SYSLOG_IDENTIFIER)
        syslog.syslog(debug, msg)
        syslog.closelog()

        return

    def fail(self, e):
        self.sysLog(msg=e, debug=syslog.LOG_ERR, doPrint=True)
        raise e

    """
    load_schema_module(): load a Yang model file
    input:    yang_file - full path of a Yang model file
    returns:  Exception if error
    """
    def _load_schema_module(self, yang_file):
        module_name = os.path.splitext(yang_file.split('/')[-1])[0]
        try:
            return self.ctx.load_module(module_name)
        except Exception as e:
            self.sysLog(msg="Failed to load yang module file: " + yang_file, debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)

    """
    load_schema_module_list(): load all Yang model files in the list
    input:    yang_files - a list of Yang model file full path
    returns:  Exception if error
    """
    def _load_schema_module_list(self, yang_files):
        for file in yang_files:
             try:
                 self._load_schema_module(file)
             except Exception as e:
                 self.fail(e)

    """
    load_schema_modules(): load all Yang model files in the directory
    input:    yang_dir - the directory of the yang model files to be loaded
    returns:  Exception if error
    """
    def _load_schema_modules(self, yang_dir):
        py = glob(yang_dir+"/*.yang")
        for fullname in py:
            file = os.path.basename(fullname)
            try:
                self._load_schema_module(file)
            except Exception as e:
                self.fail(e)

    """
    load_schema_modules_ctx(): load all Yang model files in the directory to context: ctx
    input:    yang_dir,  context
    returns:  Exception if error, returrns context object if no error
    """
    def _load_schema_modules_ctx(self, yang_dir=None):
        if not yang_dir:
            yang_dir = self.yang_dir

        ctx = ly.Context(yang_dir)

        py = glob(yang_dir+"/*.yang")
        for file in py:
            try:
                module_name = os.path.splitext(file.split('/')[-1])[0]
                ctx.load_module(str(module_name))
            except Exception as e:
                self.sysLog(msg="Failed to parse yang module file: " + file, debug=syslog.LOG_ERR, doPrint=True)
                self.fail(e)

        return ctx

    """
    load_data_file(): load a Yang data json file
    input:    data_file - the full path of the yang json data file to be loaded
    returns:  Exception if error
    """
    def _load_data_file(self, data_file):
       try:
            with open(data_file, encoding="utf-8") as f:
                data_node = self.ctx.parse_data_file(f, "json", no_state=True)
       except Exception as e:
           self.sysLog(msg="Failed to load data file: " + str(data_file), debug=syslog.LOG_ERR, doPrint=True)
           self.fail(e)
       else:
           self.root = data_node

    """
    get module name from xpath
    input:    path
    returns:  module name
    """
    def _get_module_name(self, schema_xpath):
        module_name = schema_xpath.split(':')[0].strip('/')
        return module_name

    """
    get_module(): get module object from Yang module name
    input:   yang module name
    returns: Schema_Node object
    """
    def _get_module(self, module_name):
        mod = self.ctx.get_module(module_name)
        return mod

    """
    load_data_model(): load both Yang module fileis and data json files
    input:   yang directory, list of yang files and list of data files (full path)
    returns: returns (context, root) if no error,  or Exception if failed
    """
    def _load_data_model(self, yang_dir, yang_files, data_files, output=None):
        if (self.ctx is None):
            self.ctx = ly.Context(yang_dir)

        try:
            self._load_schema_module_list(yang_files)
            if len(data_files) == 0:
                return (self.ctx, self.root)

            self._load_data_file(data_files[0])

            for i in range(1, len(data_files)):
                self._merge_data(data_files[i])
        except Exception as e:
            self.sysLog(msg="Failed to load data files", debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
            return

        output = 1
        if output is not None:
            self._print_data_mem(output)

        return (self.ctx, self.root)

    """
    print_data_mem():  print the data tree
    input:  option:  "JSON" or "XML"
    """
    def _print_data_mem(self, option):
        if self.root is not None:
            if (option == "JSON"):
                mem = slef.root.print_mem("json", with_siblings=True)
            else:
                mem = slef.root.print_mem("xml", with_siblings=True)
        return mem

    """
    save_data_file_json(): save the data tree in memory into json file
    input: outfile - full path of the file to save the data tree to
    """
    def _save_data_file_json(self, outfile):
        mem = self.root.print_mem(ly.LYD_JSON, ly.LYP_FORMAT)
        with open(outfile, 'w') as out:
            dump(mem, out, indent=4)

    """
    get_module_tree(): get yang module tree in JSON or XMAL format
    input:   module name
    returns: JSON or XML format of the input yang module schema tree
    """
    def _get_module_tree(self, module_name, format):
        result = None

        try:
            module = self.ctx.get_module(str(module_name))
        except Exception as e:
            self.sysLog(msg="Cound not get module: " + str(module_name), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
        else:
            if (module is not None):
                if (format == "XML"):
                    #libyang bug with format
                    result = module.print_mem(ly.LYD_JSON, ly.LYP_FORMAT)
                else:
                    result = module.print_mem(ly.LYD_XML, ly.LYP_FORMAT)

        return result

    """
    validate_data(): validate data tree
    input:
           node:   root of the data tree
           ctx:    context
    returns:  Exception if failed
    """
    def _validate_data(self, node=None, ctx=None):
        if not node:
            node = self.root

        if not ctx:
            ctx = self.ctx

        try:
            node.validate(validate_present=True)
        except Exception as e:
            self.fail(e)

    """
    validate_data_tree(): validate the data tree. (Public)
    returns: Exception if failed
    """
    def validate_data_tree(self):
        try:
            self._validate_data(self.root, self.ctx)
        except Exception as e:
            self.sysLog(msg="Failed to validate data tree\n{", debug=syslog.LOG_ERR, doPrint=True)
            raise SonicYangException("Failed to validate data tree\n{}".\
                format(str(e)))

    """
    find_parent_data_node():  find the parent node object
    input:    data_xpath - xpath of the data node
    returns:  parent node
    """
    def _find_parent_data_node(self, data_xpath):
        if (self.root is None):
            self.sysLog(msg="data not loaded", debug=syslog.LOG_ERR, doPrint=True)
            return None
        try:
            data_node = self._find_data_node(data_xpath)
        except Exception as e:
            self.sysLog(msg="Failed to find data node from xpath: " + str(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
        else:
            if data_node is not None:
                return data_node.parent()

        return None

    """
    get_parent_data_xpath():  find the parent data node's xpath
    input:    data_xpath - xpathof the data node
    returns:  - xpath of parent data node
              - Exception if error
    """
    def _get_parent_data_xpath(self, data_xpath):
        path=""
        try:
            data_node = self._find_parent_data_node(data_xpath)
        except Exception as e:
            self.sysLog(msg="Failed to find parent node from xpath: " + str(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
        else:
            if  data_node is not None:
                path = data_node.path()
        return path

    """
    new_data_node(): create a new data node in the data tree
    input:
           xpath: xpath of the new node
           value: value of the new node
    returns:  new Data_Node object if success,  Exception if falied
    """
    def _new_data_node(self, xpath, value):
        val = str(value)
        try:
            data_node = self.root.new_path(xpath, val, True, 0)
        except Exception as e:
            self.sysLog(msg="Failed to add data node for path: " + str(xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
        else:
            return data_node

    """
    find_data_node():  find the data node from xpath
    input:    data_xpath: xpath of the data node
    returns   - Data_Node object if found
              - None if not exist
              - Exception if there is error
    """
    def _find_data_node(self, data_xpath):
        try:
            set = self.root.find_path(data_xpath)
        except Exception as e:
            self.sysLog(msg="Failed to find data node from xpath: " + str(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
        else:
            if set is not None:
                return set 
            return None

    """
    find_schema_node(): find the schema node from schema xpath
        example schema xpath:
        "/sonic-port:sonic-port/sonic-port:PORT/sonic-port:PORT_LIST/sonic-port:port_name"
    input:    xpath of the node
    returns:  Schema_Node oject or None if not found
    """
    def _find_schema_node(self, schema_xpath):
        try:
            schemas = self.ctx.find_path(schema_xpath) #, True)

            for schema_node in schemas:
                if schema_xpath == schema_node.schema_path():
                    return schema_node

        except Exception as e:
             self.fail(e)
             return None
        return None

    """
    find_data_node_schema_xpath(): find the xpath of the schema node from data xpath
      data xpath example:
      "/sonic-port:sonic-port/PORT/PORT_LIST[port_name='Ethernet0']/port_name"
    input:    data_xpath - xpath of the data node
    returns:  - xpath of the schema node if success
              - Exception if error
    """
    def _find_data_node_schema_xpath(self, data_xpath):
        path = ""
        try:
            data_node = self._find_data_node(data_xpath)
            if data_node != None:
                path = data_node.schema().schema_path()

            return path
        except Exception as e:
            self.fail(e)
            return None
    """
    add_node(): add a node to Yang schema or data tree
    input:    xpath and value of the node to be added
    returns:  Exception if failed
    """
    def _add_data_node(self, data_xpath, value):
        try:
            self._new_data_node(data_xpath, value)
            #check if the node added to the data tree
            self._find_data_node(data_xpath)
        except Exception as e:
            self.sysLog(msg="add_node(): Failed to add data node for xpath: " + str(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)

    """
    merge_data(): merge a data file to the existing data tree
    input:    yang model directory and full path of the data json file to be merged
    returns:  Exception if failed
    """
    def _merge_data(self, data_file, yang_dir=None):
        #load all yang models to ctx
        if not yang_dir:
            yang_dir = self.yang_dir

        ctx = self.ctx
        #source data node
        with open(data_file, encoding="utf-8") as f:
            source_node = ctx.parse_data_file(f,  "json") #, ly.LYD_JSON, ly.LYD_OPT_CONFIG | ly.LYD_OPT_STRICT)

        #merge
        #self.root.merge(source_node, 0)

    """
    _deleteNode(): delete a node from the schema/data tree, internal function
    input:    xpath of the schema/data node
    returns:  True - success   False - failed
    """
    def _deleteNode(self, xpath=None, node=None):
        if node is None:
            node = self._find_data_node(xpath)

        if (node):
            #node.free()
            dnode = self._find_data_node(xpath)
            if (dnode is None):
                #deleted node not found
                return True
            else:
                self.sysLog(msg='Could not delete Node', debug=syslog.LOG_ERR, doPrint=True)
                return False
        else:
            self.sysLog(msg="failed to find node, xpath: " + xpath, debug=syslog.LOG_ERR, doPrint=True)

        return False

    """
    find_data_node_value():  find the value of a node from the data tree
    input:    data_xpath of the data node
    returns:  value string of the node
    """
    def _find_data_node_value(self, data_xpath):
        output = ""
        try:
            data_node = self._find_data_node(data_xpath)
        except Exception as e:
            self.sysLog(msg="find_data_node_value(): Failed to find data node from xpath: {}".format(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
        else:
            if (data_node is not None):
                return data_node.value()
            return output

    """
    set the value of a node in the data tree
    input:    xpath of the data node
    returns:  Exception if failed
    """
    def _set_data_node_value(self, data_xpath, value):
        try:
            self.root.new_path(data_xpath, str(value), opt_canon_value=True) #, ly.LYD_ANYDATA_STRING, ly.LYD_PATH_OPT_UPDATE)
        except Exception as e:
            self.sysLog(msg="set data node value failed for xpath: " + str(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)

    """
    find_data_nodes(): find the set of data nodes for a schema xpath
    input:    xpath of the data node
    returns:  list of xpath of the dataset
    """
    def _find_data_nodes(self, data_xpath):
        list = []

        try:
            node_set = self.root.find_one(data_xpath)
            if node_set is None:
                raise Exception('data node not found')

            for data_set in node_set:
                data_set.schema()
                list.append(data_set.path())

        except Exception as e:
            self.fail(e)
            return None

        return list

    """
    find_schema_dependencies():  find the schema dependencies from schema xpath
    input:    schema_xpath of the schema node
    returns:  - list of xpath of the dependencies
              - Exception if schema node not found
    """
    def _find_schema_dependencies(self, schema_xpath):
        # To be implemented
        return None

    """
    find_data_dependencies():   find the data dependencies from data xpath
    input:    data_xpath - xpath of data node. (Public)
    returns:  - list of xpath
              - Exception if error
    """
    def find_data_dependencies(self, data_xpath):
        # To be implemented
        return None

    """
    get_module_prefix:   get the prefix of a Yang module
    input:    name of the Yang module
    output:   prefix of the Yang module
    """
    def _get_module_prefix(self, module_name):
        prefix = ""
        try:
            module = self._get_module(module_name)
        except Exception as e:
            self.fail(e)
            return prefix
        else:
            return module.prefix()

    """
    str_to_type:   map string to type of node
    input:    string
    output:   type
    """
    def _str_to_type(self, type_str):
           mapped_type = {
                "LY_TYPE_BINARY":Type.BINARY,
                "LY_TYPE_BITS":Type.BITS,
                "LY_TYPE_BOOL":Type.BOOL,
                "LY_TYPE_DEC64":Type.DEC64,
                "LY_TYPE_EMPTY":Type.EMPTY,
                "LY_TYPE_ENUM":Type.ENUM,
                "LY_TYPE_IDENT":Type.IDENT,
                "LY_TYPE_INST":Type.INST,
                "LY_TYPE_LEAFREF":Type.LEAFREF,
                "LY_TYPE_STRING":Type.STRING,
                "LY_TYPE_UNION":Type.UNION,
                "LY_TYPE_INT8":Type.INT8,
                "LY_TYPE_UINT8":Type.UINT8,
                "LY_TYPE_INT16":Type.INT16,
                "LY_TYPE_UINT16":Type.UINT16,
                "LY_TYPE_INT32":Type.INT32,
                "LY_TYPE_UINT32":Type.UINT32,
                "LY_TYPE_INT64":Type.INT64,
                "LY_TYPE_UINT64":Type.UINT64,
                "LY_TYPE_UNKNOWN":Type.UNKNOWN
           }

           if type_str not in mapped_type:
               return Type.UNKNOWN

           return mapped_type[type_str]

    def _get_data_type(self, schema_xpath):
        try:
            schema_node = self._find_schema_node(schema_xpath)
        except Exception as e:
            self.sysLog(msg="get_data_type(): Failed to find schema node from xpath: {}".format(schema_xpath), debug=syslog.LOG_ERR, doPrint=True)
            self.fail(e)
            return None

        if (schema_node is not None):
            return schema_node.type()

        return None

    """
    get_leafref_type:   find the type of node that leafref references to
    input:    data_xpath - xpath of a data node
    output:   type of the node this leafref references to
    """
    def _get_leafref_type(self, data_xpath):
        data_node = self._find_data_node(data_xpath)
        if (data_node is not None):
            if (data_node.schema() is not None):
                    if data_node.schema().type().base() != Type.LEAFREF:
                        self.sysLog(msg="get_leafref_type() node type for data xpath: {} is not LEAFREF".format(data_xpath), debug=syslog.LOG_ERR, doPrint=True)
                        return Type.UNKNOWN
                    else:
                        return data_node.schema().type().leafref_type()

        return Type.UNKNOWN

    """
    get_leafref_path():   find the leafref path
    input:    schema_xpath - xpath of a schema node
    output:   path value of the leafref node
    """
    def _get_leafref_path(self, schema_xpath):
        try:
            schemas = self.ctx.find_path(schema_xpath, True)

            for schema_node in schemas:
                if schema_node.type().base() == Type.LEAFREF:
                    leafref_path = schema_node.type().leafref_path()
                    return leafref_path
        except Exception as e:
             self.fail(e)
             return None

    """
    get_leafref_type_schema:   find the type of node that leafref references to
    input:    schema_xpath - xpath of a schema node
    output:   type of the node this leafref references to
    """
    def _get_leafref_schema_type(self, schema_xpath):
        '''
        try:
            schemas = self.ctx.find_path(schema_xpath, True)

            for schema_node in schemas:
                if schema_node.type() == Type.LEAFREF:
                    leafref_type = schema_node.type().leafref_type()
                    return leafref_type.basename() #__repr__ #module().path()
        except Exception as e:
             self.fail(e)
             return None
        '''
        schema_node = self._find_schema_node(schema_xpath)
        if schema_node is not None:
            return schema_node.type().leafref_type()
        else:
            return None

    """
    get_leafref_type_schema:   find the type of node that leafref references to
    input:    schema_xpath - xpath of a schema node
    output:   type of the node this leafref references to
    """
    def _get_leafref_type_schema(self, schema_xpath):
        schema_node = self._find_schema_node(schema_xpath)
        if (schema_node is not None):
            subtype = schema_node.type()
            if (subtype is not None):
                if subtype.base() != Type.LEAFREF:
                    return None 
                else:
                    return subtype.leafref_type()

        return None
