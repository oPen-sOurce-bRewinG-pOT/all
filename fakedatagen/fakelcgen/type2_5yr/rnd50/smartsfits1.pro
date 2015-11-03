pro smartsfits1

readcol, 'filename',infile,format='A'

for icount=0,n_elements(infile)-1 do begin
;for icount=0,0 do begin
    print, 'Input file#',icount+1,'being converted'
    readcol,infile[icount],mjd_R,R,err_R,J,err_J,format='D3'

;    w=where((R lt 100.0) and (R gt 9))  ; this is to avoid 9999.0s and spurious values under mag=10
;    mjd_R=mjd_R(w)
;        R=R(w)
;    err_R=err_R(w);

;    w=where((J lt 100.0) and (J gt 9))
;    ;mjd_J=mjd_J(w)
;        J=J(w)
;    err_J=err_J(w)

    doneR  = replicate({mjd_R:0., R:0., err_R:0.},n_elements(mjd_R))
    doneJ  = replicate({mjd_Z:0., Z:0., err_Z:0.},n_elements(mjd_R))

    doneR.mjd_R=mjd_R-2400000.0
    doneR.R=R
    doneR.err_R=err_R
    doneJ.mjd_Z=mjd_R-2400000.0
    doneJ.Z=J
    doneJ.err_Z=err_J

;;;;;;  Naming the output   ;;;;;;;;;;;;;
    outfile = strmid(infile[icount],0,strpos(infile[icount],'.dat'))
; the above line removes the string .tab from the input filename.
; the following line adds the string R.fits or J.fits to the corresponding output filenames.
    outfileR = outfile+'R.fits'
    outfileJ = outfile+'J.fits'
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;  Creating header for output fits file   ;;;;;;;;;;;;;
;  In the following line, we are defining the string array hdr. Turns out mwrfits does not take the last element of the string array hdr as part of the header of the fits file. Hence, I'm adding a last element named "garbage" so that mwrfits omits that element but takes everything before that.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
hdr=["COMMENT This file was created by /Desktop/sdss_fermi/blazar_drw/smartsfits.pro **","garbage"]

;;;;;;  Writing the output fits file   ;;;;;;;;;;;;;
    mwrfits, doneR, outfileR, hdr, null = !Values.F_NAN, /create
    mwrfits, doneJ, outfileJ, hdr, null = !Values.F_NAN, /create
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;plot,alog10(exp(sigma2rg/2.)*1.41),alog10(exp(taurg)*365.0),psym=4

endfor

end
