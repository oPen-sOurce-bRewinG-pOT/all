import numpy as np
from random import *

#parameters
h = 6.626E-34
c = 3E8
k = 1.38E-23
T_avg = 1e7

#variation guides
def bb_var_period():   #the day bb parameters suffer an abrupt large change
    result = 19 + (-5+2.5*np.floor(random()))
    return result


def pl_var_period():    #the day pl parameters suffer an abrupt large change
    result = 4 + (-1+0.5*np.floor(random()))
    return result

T_avg = 1e7
b_avg = 0.85

b_var = b_avg*(3.0/100)
T_var_small = T_avg*0.04
T_var_large = T_avg*0.5

def tempgen(oldval, tvar):
     result = oldval + (-tvar + 2*tvar*random())
     return result

def plawexp(oldval, condition):
    if condition == 0:
        return (oldval+=-bvar+2*bvar*random())
    else:
        return (0.7+0.3*random())



#Freq Ranges
rmin = 3.77E14
rmax = 5.77E14
jmin = 2.98E14
jmax = 2.09E14

t = 2457258.5 #Julian date

f = 10.0 #Hz random initialization
T = 3000 #K

#Random power law coefficients
a = 1.0
b = 0.7


def bb(f):
	return ((2*h*(f**3)/(c*c))*(1/(np.exp(h*f/(k*T))-1)))
	
def pl(f):
	return ((a*f**-b))
	
def pl1(f):
	return (f**-b)

#limits of frequency for obtaining totflux
limlowf = 100e6    #these limits signify the range where bb() exists for temperature range 10^7 +/- 50%
limhighf = 6e18

def totflux(limlowf,limhighf):
	stepsize = 100000000
	commdiff = (limhighf - limlowf)/stepsize
	totflux = 0.0
	for counter in xrange(stepsize):
		totflux += (bb(limlowf+counter*commdiff) + bb(limlowf+(counter+1)*commdiff))*(h*0.5)
	return totflux
	
def powerlawint(limlowf,limhighf):
	stepsize = 1000000
	commdiff = (limhighf - limlowf)/stepsize
	totflux = 0.0
	for counter in xrange(stepsize):
		totflux += (pl1(limlowf+counter*commdiff) + pl1(limlowf+(counter+1)*commdiff))*(h*0.5)
	return totflux

def plawint(limlowf,limhighf):
	stepsize = 10000000
	commdiff = (limhighf - limlowf)/stepsize
	totflux = 0.0
	for counter in xrange(stepsize):
		totflux += (pl1(limlowf+counter*commdiff) + pl1(limlowf+(counter+1)*commdiff))*(h*0.5)
	return totflux



#determine a using the total flux:
totflux_c = totflux(limlowf,limhighf)	
#determining a
a = totflux_c/powerlawint(limlowf,limhighf)

	



	


