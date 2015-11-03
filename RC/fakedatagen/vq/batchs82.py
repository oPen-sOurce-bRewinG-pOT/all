import sys
from os import listdir
from os.path import isfile, join
import csv
import varqso
import random as r
import numpy as np

def fitAllLC(dir,outputfile):
    kounterr=0
    onlyfiles= [ join(dir,f) for f in listdir(dir) if isfile(join(dir,f)) ]
    loga2s= []
    logls= []
    loglikes= []
    o_file=open(outputfile,'w')
    str1="# Log a^2   Log L    Log a   a   L\n\n"
    o_file.write(str1)
    for filename in onlyfiles:
        if (1>0):
            print "Working on file %s ..." % filename
            v= varqso.VarQso(filename,band='r')
            params= v.fit(band='r',type='DRW',loglike=True)
            if len(params['loga2'])>=0:
                str1=str(params['loga2'][0])+" "+str(params['logl'][0])+" "+str(0.5*params['loga2'][0])+" "+str(np.exp(0.5*params['loga2'][0]))+" "+str(np.exp(params['logl'][0]))+"\n"
                print str1
                o_file.write(str1)
            
            kounterr+=1
            #loglikes.append(params['loglike'])
    #Save output in file
    #csvfile= open(outputfile,'w')
    #writer = csv.writer(csvfile, delimiter=',',
    #                    quotechar='#', quoting=csv.QUOTE_MINIMAL)
    #for ii in range(len(onlyfiles)):
    #    writer.writerow([onlyfiles[ii],loga2s[ii],
                         #logls[ii],loglikes[ii]])
    #csvfile.close()
    print kounterr
    
        
    o_file.close()
    return None

if __name__ == '__main__':
    fitAllLC(sys.argv[1],sys.argv[2])
