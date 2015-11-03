import random as r
import numpy as n
x=[0,0,0]
k=0
while x[0]<=3:
    x[1]=0
    while x[1]<=3:
        x[2]=0
        while x[2]<=3:
            str1=str(x[0])+' '+str(x[1])+' '+str(x[2])
            for i in xrange(3):
                str1+=' '+str(n.exp(-x[0]**2-x[1]**2-x[2]**2))
                #k+=0.1
                #str1+='\n'
            print str1
            x[2]+=0.1
        x[1]+=0.1
    x[0]+=0.1
        
