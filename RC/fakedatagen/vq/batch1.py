import sys
from os import listdir
from os.path import isfile, join
import csv
import varqso
import numpy as np
log10 = np.log(10.0)
def fitAllLC(dir,bandname):
    onlyfiles= [ join(dir,f) for f in listdir(dir) if isfile(join(dir,f)) ]
    #loga2s= []
    #logls= []
    #loglikes= []
    
    str1="# Log a^2   Log L    Log a   a   L\n\n"
    o_file.write(str1)
    for filename in onlyfiles:
        print "Working on file %s ..." % filename
        v= varqso.VarQso(filename,band=bandname)
        params= v.fit(bandname,'DRW')
        if len(params['loga2'])!=0:
            str1=str(params['loga2'][0])+" "+str((params['logl'][0]+np.log(365.25))/log10)+" "+str(((0.5*params['loga2'][0])+log10)/log10)+" "+str(np.exp(0.5*params['loga2'][0]))+" "+str(np.exp(params['logl'][0]))+"\n"
            o_file.write(str1)
        #loga2s.append(params['loga2'][0])
        #logls.append(params['logl'][0])
        
        #loglikes.append(params['loglike'])
    #Save output in file
    #csvfile= open(outputfile,'w')
    #writer = csv.writer(csvfile, delimiter=',',
    #                    quotechar='#', quoting=csv.QUOTE_MINIMAL)
    #for ii in range(len(onlyfiles)):
    #    writer.writerow([onlyfiles[ii],loga2s[ii],
    #                     logls[ii]])
    #csvfile.close()

    #outputfile
    return None

if __name__ == '__main__':
    for k in xrange(4):
        #if k!=1:
        dirname=k+1
        str2=str(dirname)+".dat"
        o_file=open(str2,'w')
        if dirname > (2):
	    #o_file=open(str2,'w')
            bandname='r'
            fitAllLC(str(dirname),bandname)
            #o_file.close()
	else:
	    #o_file=open(str2,'w')
	    bandname='z'
	    fitAllLC(str(dirname),bandname)
	o_file.close()
