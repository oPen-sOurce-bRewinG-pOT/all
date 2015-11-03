from math import *
from pylab import *
x = -pi
while x <= pi:
	a = sin(x)
	plot(x, a)
	x+=0.001
show()
