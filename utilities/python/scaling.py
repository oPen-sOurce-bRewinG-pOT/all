#!/Users/sunip/anaconda/bin/python
#This program scales X and Y axis of a given data set according to a power law specified by the user.
import sys
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
while 1:
    xpar=input("Enter X axis scaling parameter: ")
    ypar=input("Enter Y axis scaling parameter: ")
    xpow=input("Enter the power to which you want to scale the X axis: ")
    ypow=input("Enter the power to which you want to scale the Y axis: ")
    str1="The scaling behavior wanted is thus: \n X axis: X*X_parameter^"+str(xpow)+"\nY axis: Y*Y_parameter^"+str(ypow)+"\n"
    print str1
    str1=raw_input("Enter Y to confirm: ")
    if str1=="Y":
        break
for i in xrange(len(array)):
    array[i][0]*=(xpar**xpow)
    array[i][1]*=ypar**ypow
    str1=str(array[i][0])+" "+str(array[i][1])+"\n"
    o_file.write(str1)
o_file.close()
print "Success!"
