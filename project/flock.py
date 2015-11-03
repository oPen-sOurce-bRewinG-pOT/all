#!/usr/bin/python
from random import *
from math import *
#This code is aiming to simulate flock motion (sigh)
xxx = x = 100 #x direction limit
yyy = y = 100 #y direction limit, i.e. the checker board to fly in
dim = 10 #number of birds
ran = 1 #how far away birds can affect?
noise = 0.1 #noise parameter
dt = 0.05 #time parameter
trange = 1000000 #max time
aList = [] #the mother of all birds
bList = []
fname = "flock"
fnum = 0
str1 = fname+str(fnum)+".dat"
for count in xrange(dim): #initialization
	#aList.append([]) #the bird is born
	i=int(floor(x*random())) # x co ordinate of the bird
	j=int(floor(x*random())) # y coordinate of the bird
	theta = 2*pi*random() # random angle
	v1 = 2*cos(theta)
	v2= 2*sin(theta) # y velocity such that modulus is 1
	aList.append(i)
	aList.append(j)
	aList.append(v1)
	aList.append(v2)
o_file = open(str1, 'w')
for count in xrange(dim):#printing the initial random situation
    str2 = ''
    for count2 in xrange(4):
	str2 += str(aList[4*count+count2])+" "
    str2+="\n"
    o_file.write(str2)
o_file.close
fnum+=1
for time in xrange(trange):#master loop
    for count in xrange(dim): #updating the velocities by using the flocking pattern
        x = aList[count*4]
        #xx = aList[count*4]
        y = aList[count*4+1]
        #yy = aList[count*4+1]
        vx = aList[count*4+2]
        vy = aList[count*4+3]
        vxx = aList[count*4+2]
        vyy = aList[count*4+3]
        for othercount in xrange(dim):
            if (othercount != count):
                intermedcount = 0
                if (x-ran < aList[othercount*4] < x+ran) and (y-ran < aList[othercount*4+1] < y+ran):
                    vxx += aList[othercount*4+2]
                    vyy += aList[othercount*4+3]
                    intermedcount += 1
        if (intermedcount != 0):
            vxx /= intermedcount
            vyy /= intermedcount
            newangle = atan(vyy/vxx) + noise*random()
            #newmod = sqrt(vxx*vxx+vyy*vyy)
            vxx = 2*cos(newangle)
            vyy = 2*sin(newangle)
        #bList.append(x)
        #bList.append(y)
        bList.append(vxx)
        bList.append(vyy)
    for count in xrange(dim):#movement
        aList[4*count] += bList[2*count]*dt
        aList[4*count+1] +=bList[2*count + 1]*dt
        aList[4*count+2] = bList[2*count]
        aList[4*count+3] = bList[2*count+1]
        if (aList[4*count] < 0):
            #aList[4*count]=-aList[4*count]
	    #vxx=-vxx
	    aList[4*count]+=100
        elif (aList[4*count] > xxx):
            #aList[4*count]=2*xxx-aList[4*count]
	    #vxx=-vxx
	    aList[4*count]-=100
        if (aList[4*count+1] < 0):
            #aList[4*count+1]=-aList[4*count+1]
	    #vyy=-vyy
	    aList[4*count+1]+=yyy
        elif (aList[4*count+1] > yyy):
            #aList[4*count+1]=2*yyy-aList[4*count+1]
	    #vyy=-vyy
	    aList[4*count+1]-=yyy
    if (time % (trange/10) == 0):
		#fnum+=1
		print "Output!\n"
		str1 = fname + str(fnum) + ".dat"
		o_file = open(str1, 'w')
		for count in xrange(dim):#printing the initial random situation
    			str2 = ''
			for count2 in xrange(4):
				str2 += str(aList[4*count+count2])+" "
    			str2+="\n"
    			o_file.write(str2)
		o_file.close
		fnum+=1
    
