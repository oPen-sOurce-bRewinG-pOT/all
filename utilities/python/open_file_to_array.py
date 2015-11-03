#This code opens two files provided in the arguments.


import sys

#this part of code opens the file supplied in the argument
print "Input file is argument 1 and output file is argument 2."
i_file=open(sys.argv[1], 'r')
o_file=open(sys.argv[2], 'w')
array=[]
i=0
for line in i_file:
    array.append([])
    word=line.rstrip('\n')
    temp=word.split()
    len2=len(temp)
    for j in xrange(len2):
        array[i].append(float(temp[j]))
    i+=1
i_file.close()
print array
'''
#this part of the code writes the array back to the second file provided in the argument
j=len(array)
for i in xrange(j):
    len2=len(array[i])
    for k in xrange(len2):
        o_file.write(str(array[i][k]))
        o_file.write(" ")
    o_file.write('\n')
o_file.close()
''''
