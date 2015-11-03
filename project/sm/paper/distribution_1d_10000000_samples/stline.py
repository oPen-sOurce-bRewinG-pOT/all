import sys
import numpy as np
i_file=open(sys.argv[1], 'r')
o_file=open(sys.argv[2], 'w')
#N=float(input("Enter the normalizer: "))
N=float(100000000)
a1=[]
a2=[]
for line in i_file:
    word=line.rstrip('\n')
    temp=word.split()
    p=float(temp[1])#/N
    #p=np.log(p)
    q=float(temp[0])**2.0
    if p != 0:
    	p=np.log(p)
    	a1.append(q)
    	a2.append(p)
    #str2=str(q)+" "+str(p)+"\n"
    #o_file.write(str2)
b1=[]
b2=[]
for i in xrange(int(len(a1)/2)):
    temp=a2[i]
    k=0
    for j in xrange(i+1,len(a1)):
    	if a1[j]==a1[i]:
    	    temp+=a2[j]
    	    k+=1
    temp=temp/k
    p=a1[i]
    b1.append(a1[i])
    b2.append(temp)
for i in xrange(len(b1)):
    str2=str(b1[i])+" "+str(b2[i])+"\n"
    o_file.write(str2)
    	
i_file.close()
o_file.close()
print "Success!!"
