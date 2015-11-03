from math import *
from random import *
#for l in xrange(1000): #no. of steps selector
d = 0 #this is the return number
c = 0.0
for m in xrange(100000): #ensemble size
	a=[0, 0, 0]
	i=0
	c = random()
	#d = random()
		
	if c<=(1/6.0):
		a[0]+=1
	elif(c<=(2/6.0)):
		a[1]+=1
	elif(c<=(3/6.0)):
		a[0]-=1
	elif (c<=(4/6.0)):
		a[1]-=1
	elif (c<=(5/6.0)):
		a[2]+=1
	else:
		a[2]-=1
	while (((a[0]!=0) or (a[1]!=0)) or (a[2]!=0)): #do the random walk
		#b = random()
		c = random()
		#d = random()
		
		if c<=(1/6.0):
			a[0]+=1
		elif(c<=(2/6.0)):
			a[1]+=1
		elif(c<=(3/6.0)):
			a[0]-=1
		elif (c<=(4/6.0)):
			a[1]-=1
		elif (c<=(5/6.0)):
			a[2]+=1
		else:
			a[2]-=1
		i+=1
		if i==10000000:
			d-=1
			#print "Fail"
			break
	d += 1
	#print m
d=(d*1.0)/100000
print d

