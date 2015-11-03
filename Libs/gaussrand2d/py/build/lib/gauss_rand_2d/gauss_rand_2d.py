import os, os.path, platform
import ctypes
import ctypes.util
from numpy.ctypeslib import ndpointer
import numpy as np
#Find and load the library
_lib = None
if platform.system()=='Darwin':
    _libraryname= 'libgaussrand2d.dylib'
else:
    _libraryname= 'libgaussrand2d.so'
_libname = ctypes.util.find_library(_libraryname)
#if _libname:
#    _lib = ctypes.cdll.LoadLibrary(_libname)
if _libname:
    _lib = ctypes.CDLL(_libname)
if _lib is None: #Hack
    p = os.path.join('/usr/local/lib/',_libraryname)
    if os.path.exists(p):
        _lib = ctypes.CDLL(p)
if _lib is None:
        raise IOError(_libraryname+' library not found')


c_gauss_rand_2d = _lib.gaussrand2d

def gauss_rand_2d ( nx , ny , variance , power ):
	outdata = np.zeros ( ( nx , ny ) , dtype = np.double )
	c_gauss_rand_2d ( ctypes.c_void_p ( outdata.ctypes.data ) , ctypes.c_int ( nx ) , ctypes.c_int ( ny ) , ctypes.c_double ( variance ) , ctypes.c_double ( power ) )
	return outdata
	
if __name__ == '__main__' :
	p = gauss_rand_2d ( 20 , 20 , 0.5 , -4 )
	print p  
	
