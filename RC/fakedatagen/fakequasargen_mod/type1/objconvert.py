#This code opens two files provided in the arguments.


import sys
import numpy as np

#this part of code opens the file supplied in the argument
print "Input file is argument 1 and output file is argument 2."
i_file=open(sys.argv[1], 'r')
#o_file=open(sys.argv[2], 'w')
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

j = 1
while j+1 < len(array[0]):
    str1 = str(j/2)+"type1.dat"
    o_file = open(str1, 'w')
    #str2 = "# date    r   j\n"
    #o_file.write(str2)
    for i in xrange(len(array)):
        str2 = str(array[i][0]) + " " + str(-2.5*np.log(array[i][j])/val) + " " + str(-2.5*np.log(array[i][j])/val) + "\n"
        o_file.write(str2)
    o_file.close()
    j += 2

