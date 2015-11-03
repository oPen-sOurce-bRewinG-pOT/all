#!/usr/bin/python
import sys
from os import listdir
from os.path import isfile, join
from random import *

dir1 = sys.argv[1]
dir2 = sys.argv[2]
type = sys.argv[3]

str3 = "./"+dir2+"/filename"
k_file = open(str3,'w')
for count in xrange(50):
    filename = "./"+dir1+"/"+str(count)+"type"+type+".dat"
    print "Working on file %s  ..." % filename
    i_file = open(filename, 'r')
    str1 = "./"+dir2+"/"+str(count)+"type"+type+"_resampled.dat"
    str2 = str(count)+"type"+type+"_resampled.dat"+"\n"
    k_file.write(str2)
    o_file = open(str1, 'w')
    
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
    
    for j in xrange(0,i):
	if (random()<=0.02732):
            str1 = ""
            for k in xrange(len(array[0])):
                str1 += str(array[j][k])+ " "
            str1 += "\n"
            o_file.write(str1)
    o_file.close()
