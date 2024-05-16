import ctypes
import platform

mode = dict(winmode=0) if platform.python_version() >= '3.8' else dict() 
lib = ctypes.CDLL('./libtest.dylib', **mode)

# Define argument and return types for functions
lib.init.argtypes = (ctypes.c_int, ctypes.c_int)
lib.init.restype = ctypes.c_void_p
lib.printGrid.argtypes = (ctypes.c_void_p,)
lib.printGrid.restype = ctypes.c_void_p
lib.destroyGrid.argtypes = (ctypes.c_void_p,)
lib.destroyGrid.restype = None

# Usage example
grid = lib.init(5, 5)
lib.printGrid(grid)
lib.destroyGrid(grid)


