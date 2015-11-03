# Random walk 1D first return probability
from math import *
from random import *
laziness=0.0 #starting value of laziness
ensemble=1000000 #use larger ensemble
stepsizelimit=100000000 # max step size
position = 0 # position variable, origin
while laziness < 1.0:
    print "Laziness: ", laziness, "\n"
    str1="Laziness_"+str(laziness)+".dat"
    f=open(str1,'w')
    f.write("# Stepsize FRP\n")
    #for stepsize in xrange(1000000, stepsizelimit, 1000000):
    stepsize = 10 #initialize
    while stepsize <= stepsizelimit:
        print "Stepsize: ",stepsize,"\n"
        probability=0
        for i in xrange(ensemble):
	    #if (i%1000)==0:
		#print i
            position=0 #initialize
            checker=0
            for j in xrange(stepsize):
                if random()>laziness:
                    checker=1
                    if random()>0.5:
                        position+=1
                    else:
                        position-=1
                if (position==0) and ():
                    probability+=1
                    break
        probability=(1.0*probability)/ensemble
        str2=str(stepsize)+" "+str(probability)
        f.write(str2)
        f.write("\n")
	print "Probability: ", probability
	stepsize=stepsize*10
    f.close()
    laziness+=0.2

