#!/Users/sunip/anaconda/bin/python
import sys
i_file=open(sys.argv[1], 'r')
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
str1="This file has "+str(len(array[1]))+" columns."
print str1
k=input("Enter the column you want to use as the X axis: ")
k=k-1
l=input("Enter the column you want to use as the Y axis: ")
l=l-1
if input("Enter 1 for slope fitting and 2 for linear fitting: ")==1:
    #slope fitting algorithm starts
    x=0.0
    y=0.0
    for i in xrange(len(array)):
        x+=array[i][k]
        y+=array[i][l]
    slope=y/x
    str1="The slope is: "+str(slope)+".\n"
    print str1
else:
    #linear best fitting algorithm starts
    sumx=0.0
    sumy=0.0
    sumxy=0.0
    sumx2=0.0
    count=len(array)
    for i in xrange(count):
        sumx+=array[i][k]
        sumy+=array[i][l]
        sumxy+=array[i][k]*array[i][l]
        sumx2+=array[i][k]*array[i][k]
    xmean=sumx/count
    ymean=sumy/count
    slope = (sumxy - sumx * ymean) / (sumx2 - sumx * xmean)
    intercept=ymean-slope*xmean
    str1="The slope is: "+str(slope)+".\nThe intercept is: "+str(intercept)+".\n"
    print str1
    
