#!/usr/bin/env python

import xmlrpclib
import time

from SimpleXMLRPCServer import SimpleXMLRPCServer

def is_even(n):
	return n%2 == 0

def get_date():
	localtime = time.asctime(time.localtime(time.time()))
	print localtime
	return localtime

server = SimpleXMLRPCServer(("localhost", 8000))
print "Listening on port 8000..."
server.register_function(is_even, "is_even")
server.register_function(get_date, "get_date")
server.serve_forever()

