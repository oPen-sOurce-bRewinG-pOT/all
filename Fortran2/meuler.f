	!Sunip Kumar Mukherjee, UG 3 Physics 346 2015
	!Program to numerically generate solutions of differential
	!equations using modified Euler method.
	
	function f(x,y)
	double precision f, x, y
	f=1+((-y+x)/(y**3 - 4*x))
	end function

	function g(x)
	double precision x, g
	g=2*dexp(x)-x-1
	end function

	program euler
	double precision, dimension (1000000) :: x, y
	double precision f, h, g, k, p, xp, yp, xpp, ypp
	integer n
	open(1,file='meuler.dat')
	!print*, "Enter inital conditions in x0, y0 format, separated"
	!print*, "by space: "
	!read*, x(1), y(1)
	!print*, "Enter the separation b/w neighbouring points: "
	!read*, h
	!print*, "Enter the number of points you want to generate: "
	!read*, n
	h=0.01
	n=3000
	x(1)=-15
11	continue
	if (x(1)<10) then
	y(1)=-15
12	continue
	if (y(1)<10) then
	xp=x(1)
	yp=y(1)
	write(1,*), x(1), y(1)
	k=h/2.0d0
	do i=2,n
	x(i)=x(i-1)+h
	p=f(x(i-1),y(i-1))
	y(i)=y(i-1)+(k*(f(x(i-1),y(i-1))+f(x(i),(y(i-1)+p*h))))
	write(1,*), x(i), y(i)!, g(x(i)), -(y(i)-g(x(i)))/g(x(i))
	end do
!101	if (xp<10 .and. xp>-15) then
!	xpp=xp-h
!	p=f(xp,yp)
!	ypp=yp-(k*(f(xp,yp-f(xpp,yp-p*h))))
!	write(1,*), xpp, ypp
!	xp=xpp
!	yp=ypp
!	goto 101
!	end if
	y(1)=y(1)+1
	goto 12
	end if
	x(1)=x(1)+1
	goto 11
	end if
!	y(1)=-15
!10	continue
!	if (y(1)<10) then
!	x(1)=-15
!	write(1,*), x(1), y(1)
!	k=h/2.0d0
!	do i=2,n
!	x(i)=x(i-1)+h
!	p=f(x(i-1),y(i-1))
!	y(i)=y(i-1)+(k*(f(x(i-1),y(i-1))+f(x(i),(y(i-1)+p*h))))
!	write(1,*), x(i), y(i)!, g(x(i)), -(y(i)-g(x(i)))/g(x(i))
!	end do
!	y(1)=y(1)+0.5
!	goto 10
!	end if
	end program euler

c             X                           Y (solved)           Actual Y                    Error 
c         0.0000000000000000        1.0000000000000000     
c        0.10000000000000001        1.1100000000000001        1.1103418361512953        3.0786568619275165E-004
c        0.20000000000000001        1.2420500000000001        1.2428055163203395        6.0791194633279613E-004
c        0.30000000000000004        1.3984652500000001        1.3997176151520065        8.9472700668301308E-004
c        0.40000000000000002        1.5818041012500001        1.5836493952825408        1.1652162644316946E-003
c        0.50000000000000000        1.7948935318812502        1.7974425414002564        1.4181312950456903E-003
c        0.59999999999999998        2.0408573527287817        2.0442376007810177        1.6535494949043946E-003
c        0.69999999999999996        2.3231473747653038        2.3275054149409531        1.8724081790202391E-003
c        0.79999999999999993        2.6455778491156607        2.6510818569849350        2.0761365231981117E-003
c        0.89999999999999991        3.0123635232728052        3.0192062223138993        2.2663900831026828E-003
c        0.99999999999999989        3.4281616932164498        3.4365636569180902        2.4448735831581392E-003

