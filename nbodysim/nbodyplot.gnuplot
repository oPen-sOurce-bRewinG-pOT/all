#set xr[-1.5e11:1.5e11]
#set yr[-1.5e11:1.5e11]
plot 0*x
pause -1
do for [ii=1:5201:100]{splot "posl.dat" u 2:3:4 every ::1::ii w l ls 1 title "Sun Orbit", "posl.dat" u 2:3:4 every ::ii::ii w p pt 7 ps 3 lc 0 title "Sun", "posl.dat" u 8:9:10 every ::1::ii w l title "Venus Orbit", "posl.dat" u 8:9:10 every ::ii::ii w p pt 7 ps 1.5 title "Venus","posl.dat" u 11:12:13 every ::1::ii w l title "Earth Orbit", "posl.dat" u 8:9:10 every ::ii::ii w p pt 7 ps 1.5 title "Earth","posl.dat" u 14:15:16 every ::1::ii w l title "Mars Orbit", "posl.dat" u 14:15:16 every ::ii::ii w p pt 7 ps 1.5 title "Mars","posl.dat" u 17:18:19 every ::1::ii w l title "Jupiter Orbit", "posl.dat" u 17:18:19 every ::ii::ii w p pt 7 ps 1.5 title "Jupiter", "posl.dat" u 20:21:22 every ::1::ii w l title "Saturn Orbit", "posl.dat" u 20:21:22 every ::ii::ii w p pt 7 ps 1.5 title "Saturn","posl.dat" u 23:24:25 every ::1::ii w l title "Uranus Orbit", "posl.dat" u 23:24:25 every ::ii::ii w p pt 7 ps 1.5 title "Uranus","posl.dat" u 26:27:28 every ::1::ii w l title "Neptune Orbit", "posl.dat" u 26:27:28 every ::ii::ii w p pt 7 ps 1.5 title "Neptune"}
pause -1

