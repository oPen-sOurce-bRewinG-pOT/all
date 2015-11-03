log10 = log(10.0)

set yr [-2:2.5]

plot "s8250.txt" u ($3+log(365.25))/log10:($2+log10)/log10 w p pt 7 title "SDSS Real Samples"
replot "fits/1.dat" u 3:2 title "BB-F PL-F T1 J"
replot "fits/2.dat" u 3:2 title "BB-F PL-F T2 J"

#replot "fits/3.dat" u 3:2 title "BB-F PL-S T1 J"
#replot "fits/4.dat" u 3:2 title "BB-F PL-S T2 J"

#replot "fits/5.dat" u 3:2 title "BB-S PL-F T1 J"
#replot "fits/6.dat" u 3:2 title "BB-S PL-F T2 J"

replot "fits/7.dat" u 3:2 title "BB-S PL-S T1 J"
replot "fits/8.dat" u 3:2 title "BB-S PL-S T2 J"


#replot "fits/9.dat" u 3:2 title "BB-F PL-F T1 R"
#replot "fits/10.dat" u 3:2 title "BB-F PL-F T2 R"

#replot "fits/11.dat" u 3:2 title "BB-F PL-S T1 R"
#replot "fits/12.dat" u 3:2 title "BB-F PL-S T2 R"

#replot "fits/13.dat" u 3:2 title "BB-S PL-F T1 R"
#replot "fits/14.dat" u 3:2 title "BB-S PL-F T2 R"

#replot "fits/15.dat" u 3:2 title "BB-S PL-S T1 R"
#replot "fits/16.dat" u 3:2 title "BB-S PL-S T2 R"

#pause -1

#replot

pause -1
