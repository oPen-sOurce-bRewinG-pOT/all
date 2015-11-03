#Transient study
from random import *
from math import *
stepsizelimit=100000 	#should be 100000, I am intending to observe non transient behaviour.
stepsize=100#00000	#modifying the start to 1000000 for further points. Should start from 100
laziness=0.0
ensemble=1000000
while stepsize<=stepsizelimit:
    str1=str(stepsize)+'.dat'
    f=open(str1, 'w')
    f.write("#LP <d^2> P_r rettime mean sqr disp.\n")
    print "#LP <d^2> P_r rettime mean sqr disp.\n"
    laziness=0.1
    while laziness < 1:
        meansqdist=0
        frp=0
        rettime=0.0
        m2sqden=0
        for i in xrange(ensemble):
            position=0
            posmax=0
            m2sqd=0
            checker=0
            for j in xrange(stepsize):
                if random()>laziness:
                    checker=1
                    if random()>0.5:
                        position+=1
                    else:
                        position-=1
                m2sqd+=position**2
                if (position**2)>posmax:
                    posmax=position**2
                if (position ==0) and (checker==1):
                    frp+=1
                    rettime+=j+1
                    m2sqd=(1.0*m2sqd)/(j+1)
                    break
            #print posmax
            meansqdist+=posmax
            m2sqden+=m2sqd
        frp=(frp*1.0)/ensemble
        meansqdist=(meansqdist*1.0)/ensemble
        m2sqden=(1.0*m2sqden)/ensemble
        rettime=(1.0)*rettime/ensemble
        str1=str(laziness)+" "+str(meansqdist)+" "+str(frp)+" "+str(rettime)+" "+str(m2sqden)+"\n"
        print str1
        f.write(str1)
        laziness+=0.2
    f.close()
    stepsize=stepsize*10
    
        
                
    
