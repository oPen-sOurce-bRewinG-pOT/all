#This code opens two files provided in the arguments.


import sys
import numpy as np
from random import *

#this part of code opens the file supplied in the argument
print "Input file is argument 1 and output file is argument 2."
i_file=open(sys.argv[1], 'r')
#o_file=open(sys.argv[2], 'w')
dir = sys.argv[2]
type = str(sys.argv[3])
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
i_file.close()
#print array

#this part of the code writes the array back to the second file provided in the argument

val = np.log(10)
print val
k_file_str= "./"+dir+type+"/filename"
k_file=open(k_file_str, 'w')
j = 1
while j+1 < len(array[0]):
    str1 = "./"+dir+type+"/"+str(j/2)+"type"+type+".dat"
    str5 = str(j/2)+"type"+type+".dat"
    k_file.write(str5)
    k_file.write("\n")
    o_file = open(str1, 'w')
    #str2 = "# date    r   j\n"
    #o_file.write(str2)
    for i in xrange(len(array)):
        if array[i][j]<=0 or array[i][j+1]<=0 :
            print "Exception here!", i, j, j+1, str5
        #else:
	str2 = str(array[i][0]) + " " + str((array[i][j])) + " " + str(0.2*random()) +" " + str((array[i][j+1])) + " " +str(0.2*random()) + "\n"
        #str2 = str(array[i][0]) + " " + str((array[i][j])) + " " + str(0) +" " + str((array[i][j+1])) + " " +str(0) + "\n"
        o_file.write(str2)
    o_file.close()
    j += 2
k_file.close()

