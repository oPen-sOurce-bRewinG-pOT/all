import sys
i_file=open(sys.argv[1], 'r')
o_file=open(sys.argv[2], 'w')
#N=float(input("Enter the normalizer: "))
N=float(100000000)
for line in i_file:
    word=line.rstrip('\n')
    temp=word.split()
    p=float(temp[1])/N
    str2=str(temp[0])+" "+str(p)+"\n"
    o_file.write(str2)
i_file.close()
o_file.close()
print "Success!!"
