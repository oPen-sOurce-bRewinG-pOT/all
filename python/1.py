#numerical derivative
#import matplotlib
from pylab import *
#from matplotlib import pyplot
import math as m
#%matplotlib inline
x=0.0
#hP=[]
#cdP=[]
#cfP=[]
#function
def f(x):
    result=m.exp(x)
    return result
f(x)
#derivative
def f1(x):
    result=m.exp(x)
    return result
f1(x)
x=input("Enter where you want the derivative to be calculated: ")
print
#calculation
for i in range(10):
    h=0.001
    h-=i*0.0001
    fd=(f(x+h)-f(x))/h
    cd=(f(x+h)-f(x-h))/(2.0*h)
    ec=1000*(cd-f1(x))/f1(x)
    ef=1000*(fd-f1(x))/f1(x)
    print "The forward and central derivatives are", fd, "&", cd, "respectively for h=",h ,".\n"
    #hP.append(h)
    #cdP.append(cd)
    #cfP.append(fd)
    plot(h, ec)
    plot(h, ef)
print "The actual derivative is: ", f1(x),"."
grid(True)
xlabel("Increment (h)")
ylabel("Error")
title('Error vs. Increment Plot')
#savefig("derp2.png")
show()
