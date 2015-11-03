import varqso
v=varqso.VarQso('SDSSJ000051.56+001202.5.fit', band='r')
v.fit('r',type='DRW',loglike=True) 
v.sampleGP('r')
