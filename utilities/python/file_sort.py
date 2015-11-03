#This code opens two files provided in the arguments.
#!/usr/local/bin/python


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
#print array

for i in xrange(len(array)):
    j=i
    while j>0:
        if array[j][0]<array[j-1][0]:
            array[j][0],array[j-1][0]=array[j-1][0],array[j][0]
            j-=1
        else:
            break


#o_file=open(sys.argv[1], 'w')
#this part of the code writes the array back to the second file provided in the argument
j=len(array)
jar = array[1][0]
print jar
for i in xrange(j):
    len2=len(array[i])
    for k in xrange(len2):
        o_file.write(str(array[i][k]-jar+119))
        o_file.write(" ")
    o_file.write('\n')
o_file.close()
