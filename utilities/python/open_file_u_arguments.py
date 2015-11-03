#This code opens a file given as the terminal argument of it at runtime and outputs its contents.

import sys

my_file=open(sys.argv[1], 'r')
print(my_file.read())
