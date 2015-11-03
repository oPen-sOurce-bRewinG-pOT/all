from math import *
from random import *
for l in xrange(100): #no. of steps selector
	d = 0.0 #this is the average distance
	for m in xrange(10000): #ensemble size
		a=[0, 0]
		for k in xrange(l): #do the random walk
			#b = random()
			c = random()
			#d = random()
			
			if c<=0.25:
				a[0]+=1
			elif(c<=0.5):
				a[1]+=1
			elif(c<=0.75):
				a[0]-=1
			else:
				a[1]-=1
		d += a[0]**2.0 + a[1]**2.0
	d=d/10000
	print l, d

