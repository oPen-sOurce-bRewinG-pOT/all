#This code generates a histogram for its argument, which is expected to be a single column file


import sys
from math import *

#this part of code opens the file supplied in the argument
i_file=open(sys.argv[1], 'r')
o_file=open(sys.argv[2], 'w')
#this part of code first reads the entire thing into memory. Redundant and a memory hog.
#array=[]
#i=0
#for line in i_file:
#    array.append([])
#    word=line.rstrip('\n')
#    temp=word.split()
#    len2=len(temp)
#    for j in xrange(len2):
#        array[i].append(float(temp[j]))
#    i+=1
#i_file.close()

#ask for lowest value, highest value and difference:
#a=float(input("Enter lower limit of data: "))
a=float(-100)
#b=input(float("Enter upper limit of data (upper limit is excluded): "))
b=float(100)
#h=float(input("Enter bin width: "))
h=float(5)
N=int((b-a)/h)
print "Number of bins used: "+str(N)+"."
#Creating the bins
data=[]
for i in xrange(N):
    data.append([])
    data[i]=0
#generating the histogram
for line in i_file:
    word=line.rstrip('\n')
    temp=word.split()
    p=float(temp[0])
    p=p-a
    p=p/h
    j=int(floor(p))
    if j<N:
        data[j]+=1
i_file.close()
#writing the histogram to file:
for i in xrange(N):
    temp=a+(i*(h))+(h/2.0)
    str1=str(temp)+" "+str(data[i])+"\n"
    o_file.write(str1)
o_file.close()
print "Success!"
    
