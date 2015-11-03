from math import *
from random import *
#for l in xrange(1000): #no. of steps selector
d = 0 #this is the return number
for m in xrange(100): #ensemble size
	a=[0, 0]
	c = floor(4*random())
	#d = random()
	if c==0:
		a[0]+=1
	elif(c==1):
		a[1]+=1
	elif(c==2):
		a[0]-=1
	else:
		a[1]-=1
	i=0
	
	while ((a[0]!=0) or (a[1]!=0)): #do the random walk
		#b = random()
		c = floor(4*random())
		#d = random()
		if c==0:
			a[0]+=1
		elif(c==1):
			a[1]+=1
		elif(c==2):
			a[0]-=1
		else:
			a[1]-=1
		i+=1
		#print a
		if i==100000000:
			d-=1
			break
	print i
	d += 1
d=(d*1.0)/100
print d

