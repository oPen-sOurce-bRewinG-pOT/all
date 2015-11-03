import os, os.path, platform
import ctypes
import ctypes.util
import numpy as nu
from numpy.ctypeslib import ndpointer
import numpy as np

cmd_folder = os.path.abspath(os.path.split(inspect.getfile( inspect.currentframe() ))[0])
_lib = load_library('_gauss_rand_2d',cmd_folder)


c_gauss_rand_2d = _lib.gaussrand2d

def gauss_rand_2d ( nx , ny , variance , power ):
	outdata = np.zeros ( ( nx , ny ) , dtype = np.double )
	c_gauss_rand_2d ( ctypes.c_void_p ( outdata.ctypes.data ) , ctypes.c_int ( nx ) , ctypes.c_int ( ny ) , ctypes.c_double ( variance ) , ctypes.c_double ( power ) )
	return outdata
	
if __name__ == '__main__' :
	p = gauss_rand_2d ( 10 , 10 , 0.5 , -4 )
	print p  
	
