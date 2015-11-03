#!/Users/sunip/anaconda/bin/python
#This program scales X and Y axis of a given data set according to a power law specified by the user.
#import sys
for count in xrange (0,5):
    activity=1-(count*0.2)
    laziness=count*0.2
    fname1="Laziness_"+str(laziness)+".dat"
    fname2="Laziness_"+str(laziness)+"sc.dat"
    i_file=open(fname1, 'r')
    o_file=open(fname2, 'w')
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
    for i in xrange(len(array)):
        array[i][0]*=1.68347/activity
        #array[i][1]*=ypar**ypow
        str1=str(array[i][0])+" "+str(array[i][1])+"\n"
        o_file.write(str1)
    o_file.close()
print "Success!"
