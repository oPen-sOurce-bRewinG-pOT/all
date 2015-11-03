fnamenum=0.0
o_file=open("all2.dat", 'w')
i=0
#for count in xrange (0,5):
while fnamenum<1:
    #activity=1-(count*0.2)
    #laziness=count*0.2
    #fname1=str(fnamenum)+".dat"
    fname2="L"+str(fnamenum)+"sc.dat"
    i_file=open(fname2, 'r')
    #o_file=open(fname2, 'w')
    array=[]
    #i=0
    for line in i_file:
       if line[0]!='#':
        array.append([])
        word=line.rstrip('\n')
        temp=word.split()
        len2=len(temp)
        for j in xrange(len2):
            array[i].append(float(temp[j]))
        i+=1
    print i
    i_file.close()
    fnamenum+=0.2
for i in xrange(len(array)):
    str1=str(array[i][0])+" "+str(array[i][1])+"\n"
    o_file.write(str1)
o_file.close()
