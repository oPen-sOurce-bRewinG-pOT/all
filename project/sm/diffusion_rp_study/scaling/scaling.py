#!/Users/sunip/anaconda/bin/python
#This program scales X and Y axis of a given data set according to a power law specified by the user.
#import sys
fnamenum=100
#for count in xrange (0,5):
while fnamenum<=100000:
    #activity=1-(count*0.2)
    #laziness=count*0.2
    fname1=str(fnamenum)+".dat"
    fname2=str(fnamenum)+"sc1.dat"
    i_file=open(fname1, 'r')
    o_file=open(fname2, 'w')
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
    for i in xrange(len(array)):
        #array[i][0]*=1.68347/activity
        #array[i][3]*=(1-array[i][0])/fnamenum**0.5
        activity=1-array[i][0]
        array[i][3]*=activity
        str1=str(array[i][3])+" "+str(array[i][1])+"\n"#+" "+str(array[i][3])+"\n"
        o_file.write(str1)
    o_file.close()
    fnamenum*=10
print "Success!"
