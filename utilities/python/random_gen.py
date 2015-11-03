from random import *
o_file=open('random.dat', 'w')
for i in xrange(1000000):
     str1=str(random())+'\n'
     o_file.write(str1)
o_file.close()
