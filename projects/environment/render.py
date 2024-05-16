import ctypes
import platform

mode = dict(winmode=0) if platform.python_version() >= '3.8' else dict() 
lib = ctypes.CDLL('./libtest.dylib', **mode)