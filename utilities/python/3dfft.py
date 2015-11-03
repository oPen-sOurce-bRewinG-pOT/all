#!/Users/sunip/anaconda/bin
#Code for calculating 3D FT.
#data format: x, y, z, A_x, A_y, A_z
import sys as s
#import numpy as m
import math as m
i_file=open(s.argv[1],'r')
o_file=open(s.argv[2], 'w')
array=[]
i=0
for line in i_file:
    if line[0]!='#':
        array.append([])
        word=line.rstrip('\n')
        temp=word.split()
        len2=len(temp)
        for j in xrange(len2):
            array[i].append(float(temp[j]))
        i+=1
#print array
i_file.close()
k1_low=k2_low=k3_low=0
k1_max=k2_max=k3_max=input("Enter k_max: ")
#x1_h=float(-array[0][0]+array[1][0])
#x2_h=float(-array[0][1]+array[1][1])
#x3_h=float(-array[0][2]+array[1][2])
x1_h=input("Enter h_x: ")
k1_h=0.1#1.0/(-array[0][0]+array[1][0])
k2_h=0.1#1.0/(-array[0][1]+array[1][1])
k3_h=0.1#1.0/(-array[0][2]+array[1][2])
rtemp=[0,0,0]
itempo=[0,0,0]
k=[0,0,0]
while k[0]<=k1_max:
    k[1]=0
    while k[1]<=k2_max:
        k[2]=0
        while k[2]<=k3_max:
            str1=str(k[0])+' '+str(k[1])+' '+str(k[2])
            for j in xrange(3,6):
                rtemp[j-3]=0
                itempo[j-3]=0
                for i in xrange(len(array)-1):
                    kr=0
                    kr1=0
                    for counter in xrange(3):
                        kr-=k[counter]*array[i][counter]
                        kr1-=k[counter]*array[i+1][counter]
                    rtemp[j-3]+=(array[i][j]*m.cos(kr)+array[i+1][j]*m.cos(kr1))*0.5*x1_h*x1_h*x1_h
                    itempo[j-3]+=((array[i][j]*m.sin(kr))+(array[i+1][j]*m.sin(kr1)))*0.5*x1_h*x1_h*x1_h
                    #print m.sin(kr), m.cos(kr)
                    #print (array[i][j]*m.cos(kr)+array[i+1][j]*m.cos(kr1)), ((array[i][j]*m.sin(kr))+(array[i+1][j]*m.sin(kr1)))
                    #print rtemp[j-3], itempo[j-3]
                str1+=' '+str(rtemp[j-3])+' '+str(itempo[j-3])
            #str1+='\n'
            #o_file.write(str1)
            print str1
            k[2]+=k3_h
        k[1]+=k2_h
    k[0]+=k1_h
o_file.close()

