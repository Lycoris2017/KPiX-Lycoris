#!/usr/bin/env python

import MySQLdb
import datetime
import time
import threading
import socket
import errno
import xml.dom.minidom
import re
from xml.dom.minidom import parseString

__version__ = "1.0"

class DaqClientException(Exception):
    pass

class DaqClient(threading.Thread):
    """Class to handle daq updates and queries."""

    def __init__(self, dhost, dport):
        """ Create daq class.  """
        threading.Thread.__init__(self)

        self._host    = dhost
        self._port    = dport
        self._sLock   = threading.Lock()
        self._cbLock  = threading.Lock()
        self._sock    = None
        self._sready  = False
        self._tEn     = False
        self._cbacks  = {}
        self._ctime   = {}

        for cb in ["config","status","structure","error"]:
            self._cbacks[cb] = []
            self._ctime[cb]  = None

    def __del__(self):
        self.disable()

    def enable(self):
        self._tEn = True
        self.start()

    def disable(self):
        if self._tEn :
            self._tEn = False
            self.join()

    # Register a structure callback
    def addStuctureCallback (self, function):
        self._cbLock.acquire()
        self._cbacks['structure'].append(function)
        self._cbLock.release()

    # Register a command callback
    def addStatusCallback (self, function):
        self._cbLock.acquire()
        self._cbacks['status'].append(function)
        self._cbLock.release()

    # Register a configuration callback
    def addConfigurationCallback (self, function):
        self._cbLock.acquire()
        self._cbacks['config'].append(function)
        self._cbLock.release()

    # Register an error callback
    def addErrorCallback (self, function):
        self._cbLock.acquire()
        self._cbacks['error'].append(function)
        self._cbLock.release()

    # Update a configuration
    def sendConfig (self, path, value):
        xmlStart="<system><config>"
        xmlEnd="</config></system>"

        subs = path.split(":")
        
        for sub in subs:
            flds = re.split('\(|\)',sub)

            xmlEnd = "</%s>%s" % (flds[0],xmlEnd)

            if len(flds) > 1:
                xmlStart = "%s<%s index=\"%s\">" % (xmlStart,flds[0],flds[1])
            else:
                xmlStart = "%s<%s>" % (xmlStart,flds[0])

        # Put value here
        xmlOut = xmlStart + str(value) + xmlEnd + "\n\f"

        self._sLock.acquire()
        self._sock.send(xmlOut)
        self._sLock.release()

    # Send a command
    def sendCommand (self, path, arg):
        xmlStart="<system><command>"
        xmlEnd="</command></system>"

        subs = path.split(":")
        
        for sub in subs:
            flds = re.split('\(|\)',sub)

            xmlEnd = "</%s>%s" % (flds[0],xmlEnd)

            if len(flds) > 1:
                xmlStart = "%s<%s index=\"%s\">" % (xmlStart,flds[0],flds[1])
            else:
                xmlStart = "%s<%s>" % (xmlStart,flds[0])

        # Put value here
        xmlOut = xmlStart + str(arg) + xmlEnd + "\n\f"

        self._sLock.acquire()
        self._sock.send(xmlOut)
        self._sLock.release()

    def findConfigStatus (self,xmlType,pathIn,node):
        cnt = 0

        local = node.localName

        if local == "config" or local == "status":
            path = ""
        elif pathIn != "":
           path = pathIn + ":" + node.localName
        else:
           path = node.localName

        attr = node.getAttribute("index")

        if attr != "":
           path = path + "(" + attr + ")"

        for item in node.childNodes:
            if item.nodeType == item.ELEMENT_NODE:
                cnt = cnt + 1
                self.findConfigStatus(xmlType,path,item)

        if cnt == 0:
            if len(node.childNodes) == 1:

                # Execute callbacks
                self._cbLock.acquire()
                for cb in self._cbacks[xmlType]:
                    try:
                        cb(path,node.childNodes[0].nodeValue)
                    except Exception,msg:
                        print("Callback exception: " + str(msg) + " in " + str(path))
                    except :
                        print("Unknown callback exception!")
                self._cbLock.release()

    # Process structure
    def rxStructureDevice ( self, pathIn, node):
        index = None
        for item in node.childNodes:
            if item.nodeType == item.ELEMENT_NODE:
                if item.localName == "index":
                    index = item.childNodes[0].nodeValue
                elif item.localName == "name":
                    path = pathIn + item.childNodes[0].nodeValue

                    if index:
                        path = path + "(%s):" % (index)
                    else:
                        path = path + ":"

                elif item.localName == "variable":
                    self.rxStructureVariable(path,item)
                elif item.localName == "command":
                    self.rxStructureCommand(path,item)
                elif item.localName == "device":
                    self.rxStructureDevice(path,item)

    # Process Variable
    def rxStructureVariable ( self, path, node):
        varData = {}
        varData['name']        = ""
        varData['type']        = ""
        varData['enum']        = ""
        varData['compA']       = ""
        varData['compB']       = ""
        varData['compC']       = ""
        varData['compUnits']   = ""
        varData['min']         = ""
        varData['max']         = ""
        varData['perInstance'] = "False"
        varData['hidden']      = "False"
        varData['description'] = ""

        for item in node.childNodes:
            if item.nodeType == item.ELEMENT_NODE:

                if len(item.childNodes) != 0:
                    val = item.childNodes[0].nodeValue
                else:
                    val = ""

                if item.localName == "name":
                    varData['name'] = path + val
                elif item.localName == "type":
                    varData['type'] = val
                elif item.localName == "enum":
                    if varData['enum'] != "":
                        varData['enum'] += ","
                    varData['enum'] += val
                elif item.localName == "compA":
                    varData['compA'] = val
                elif item.localName == "compB":
                    varData['compB'] = val
                elif item.localName == "compC":
                    varData['compC'] = val
                elif item.localName == "compUnits":
                    varData['compUnits'] = val
                elif item.localName == "min":
                    varData['min'] = val
                elif item.localName == "max":
                    varData['max'] = val
                elif item.localName == "perInstance":
                    varData['perInst'] = "True"
                elif item.localName == "hidden":
                    varData['hidden'] = "True"
                elif item.localName == "description":
                    varData['description'] = val

        if varData['type'] == "Status":
            xmlType = 'status'
        else:
            xmlType = 'config'

        # Execute callbacks
        self._cbLock.acquire()
        for cb in self._cbacks['structure']:
            try:
                cb(xmlType,varData)
            except Exception,msg:
                print("Callback exception: " + str(msg) + " in " + str(varData))
            except :
                print("Unknown callback exception!")
        self._cbLock.release()

    # Process structure
    def rxStructureCommand ( self, path, node):
        cmdData = {}
        cmdData['name']        = ""
        cmdData['hasArg']      = "False"
        cmdData['hidden']      = "False"
        cmdData['description'] = ""

        for item in node.childNodes:
            if item.nodeType == item.ELEMENT_NODE:

                if len(item.childNodes) != 0:
                    val = item.childNodes[0].nodeValue
                else:
                    val = ""

                if item.localName == "name":
                    cmdData['name'] = path + val
                elif item.localName == "hidden":
                    cmdData['hidden'] = "True"
                elif item.localName == "hasArg":
                    cmdData['hasArg'] = "True"
                elif item.localName == "description":
                    cmdData['description'] = val

        # Execute callbacks
        self._cbLock.acquire()
        for cb in self._cbacks['structure']:
            try:
                cb('command',cmdData)
            except Exception,msg:
                print("Callback exception: " + str(msg) + " in " + str(cmdData))
            except :
                print("Unknown callback exception!")
        self._cbLock.release()

    # Process structure
    def rxStructure ( self, node):
        for item in node.childNodes:
            if item.nodeType == item.ELEMENT_NODE:
                if item.localName == "device":
                    self.rxStructureDevice("",item)
                elif item.localName == "variable":
                    self.rxStructureVariable("",item)
                elif item.localName == "command":
                    self.rxStructureCommand("",item)

    # Process error
    def rxError ( self, node):
        val = node.childNodes[0].nodeValue

        self._cbLock.acquire()
        for cb in self._cbacks['error']:
            try:
                cb(val)
            except Exception,msg:
                print("Callback exception: " + str(val))
            except:
                print("Unknown callback exception!")
        self._cbLock.release()

    # Process a received message
    def rxMessage(self,msg):
        try:
            dom = parseString(msg)
            node = dom.documentElement

            for item in node.childNodes:
                if item.nodeType == item.ELEMENT_NODE:
                    if item.localName == "status":
                        self.findConfigStatus("status","",item)
                    elif item.localName == "config":
                        self.findConfigStatus("config","",item)
                    elif item.localName == "structure":
                        self.rxStructure(item)
                    elif item.localName == "error":
                        self.rxError(item)

        except:
            print "Error parsing XML"

    # Connect to the socket
    def connect(self):

        self._sLock.acquire()

        if self._sready:
            self._sLock.release()
            return True

        port = self._port

        while (not self._sready) and port < (self._port+10):
            try: 
                self._sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                self._sock.settimeout(.1)
                self._sock.connect((self._host, port))
                self._sready = True
            except Exception, e: 
                print "Cannot establish a connectioan to " + self._host + ":" + str(port)
                port = port + 1 

        self._sLock.release()

        if not self._sready:
            print "Failed to connect"
            time.sleep(1)
            return False

        print "Connected to " + self._host + ":" + str(port)
        return True

    # Polling thread
    def run(self):
        data = ""
        last = time.time()

        # Loop while thread is enabled
        while self._tEn == True:
            self.connect()

            pos = data.find("\f")
            while pos < 0 and self._sready:
                try:
                    self._sLock.acquire()
                    data += self._sock.recv(65536)
                    self._sLock.release()
                except socket.error,e:
                    self._sLock.release()
                pos = data.find("\f")

                if pos < 0 and (time.time() - last) > 5:
                    print "Message timeout"
                    self._sLock.acquire()
                    self._sready = False
                    last = time.time()
                    self._sLock.release()

            if pos >= 0:
                xml = data[0:pos-1]
                data = data[pos+1:]

                print "Processing %i bytes. Backlog = %i" % (len(xml),len(data))
                self.rxMessage(xml)
                last = time.time()

