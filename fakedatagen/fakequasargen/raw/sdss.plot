log10 = log(10.0)

set yr [-5:5]

plot "s8250.txt" u ($3+log(365.25))/log10:($2+log10)/log10 w p pt 7 title "SDSS Real Samples"
replot "fits/1.dat" u 3:2 title "BB-F PL-F T1 J"
replot "fits/2.dat" u 3:2 title "BB-F PL-F T2 J"

replot "fits/3.dat" u 3:2 title "BB-F PL-S T1 J"
replot "fits/4.dat" u 3:2 title "BB-F PL-S T2 J"



pause -1
