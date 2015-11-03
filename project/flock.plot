set xr [0:100]
set yr [0:100]
plot "flock0.dat" u 1:2:3:4 w vec lc 0 title "Snapshot 1"
pause -1
replot
pause -1
plot "flock2.dat" u 1:2:3:4 w vec lc 0 title "Snapshot 2"
pause -1
plot "flock4.dat" u 1:2:3:4 w vec lc 0 title "Snapshot 3"
pause -1
plot "flock6.dat" u 1:2:3:4 w vec lc 0 title "Snapshot 4"
pause -1
plot "flock8.dat" u 1:2:3:4 w vec lc 0 title "Snapshot 5"
pause -1
plot "flock10.dat" u 1:2:3:4 w vec lc 0 title "Snapshot 6"
#replot "flock0.dat" u 1:2:3:4 w vec title "Snapshot 1"
#replot "flock0.dat" u 1:2:3:4 w vec title "Snapshot 1"
#pause -1
#replot
pause -1
