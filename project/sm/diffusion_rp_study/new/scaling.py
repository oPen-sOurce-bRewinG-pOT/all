x=0
o2_file=open("all.dat", 'w')
for i in xrange(0,10,1):
    laz=i*1.0/10
    #print laz
    ss=100
    stro="L"+str(laz)+"_sc.dat"
    o_file=open(stro,'w')
    while ss<=100000:
        print "Opened "+str(ss)+".dat"
        stri=str(ss)+".dat"
        i_file=open(stri, 'r')
        for line in i_file:
            if (line[0]!='#'):
                #array.append([])
                word=line.rstrip('\n')
                temp=word.split()
                #for j in xrange(len(temp)):
                #    print float(temp[j]),
                #print "\n"
                #len2=len(temp)
                if float(temp[0])==laz:
                    print laz
                    str1=str(float(temp[3])*(1-laz))+" "+str(temp[1])+"\n"
                    o_file.write(str1)
                    o2_file.write(str1)
        i_file.close()
        ss*=10
    o_file.close()
    #laz+=0.10
o2_file.close()            
