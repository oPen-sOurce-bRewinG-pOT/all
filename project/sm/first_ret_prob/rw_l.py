#!$HOME/anaconda/bin/python
from math import *
from random import *
from matplotlib import *
fig, ax = pyplot.subplots()
a=[0, 0]
grid(True)
print a[0], a[1]
laziness = 0.5
for i in xrange(10000):
	b = random()
	c = random()
	d = random()
	if b>laziness:
		if c<=0.25:
			a[0]+=1
		elif(c<=0.5):
			a[1]+=1
		elif(c<=0.75):
			a[0]-=1
		else:
			a[1]-=1
	for j in xrange(10):
		b=10		
#	grid(True)
	ani = animation.FuncAnimation(fig, a[1])
	pyplot.show()
	



