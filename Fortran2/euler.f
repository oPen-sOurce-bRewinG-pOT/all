	!Sunip Kumar Mukherjee, UG 3 Physics 346 2015
	!Program to numerically generate solutions of differential
	!equations using Euler method.

	function f(x,y)
	double precision x, y, f
	f=x+y
	end function

	function g(x)
	double precision x, g
	g=2*dexp(x)-x-1
	end function

	program euler
	double precision, dimension (1000000) :: x, y
	double precision f, h, g
	integer n
	open(1,file='euler.dat')
	print*, "Enter inital conditions in x0, y0 format, separated"
	print*, "by space: "
	read*, x(1), y(1)
	print*, "Enter the separation b/w neighbouring points: "
	read*, h
	print*, "Enter the number of points you want to generate: "
	read*, n
	write(1,*), x(1), y(1)
	do i=2,n
	x(i)=x(i-1)+h
	y(i)=y(i-1)+(h*f(x(i-1),y(i-1)))
	write(1,*), x(i), y(i), g(x(i)), -(y(i)-g(x(i)))/g(x(i))
	end do
	end program euler

c             X                           Y (solved)           Actual Y                    Error 
c       0.0000000000000000         1.0000000000000000     
c       0.10000000000000001        1.1000000000000001        1.1103418361512953        9.3141011304612928E-003
c       0.20000000000000001        1.2200000000000002        1.2428055163203395        1.8350028239222185E-002
c       0.30000000000000004        1.3620000000000001        1.3997176151520065        2.6946588900297854E-002
c       0.40000000000000002        1.5282000000000000        1.5836493952825408        3.5013681341158211E-002
c       0.50000000000000000        1.7210200000000000        1.7974425414002564        4.2517376572561348E-002
c       0.59999999999999998        1.9431220000000000        2.0442376007810177        4.9463722192755688E-002
c       0.69999999999999996        2.1974342000000000        2.3275054149409531        5.5884387682188438E-002
c       0.79999999999999993        2.4871776200000002        2.6510818569849350        6.1825415368857183E-002
c       0.89999999999999991        2.8158953820000003        3.0192062223138993        6.7339169749750627E-002
c       0.99999999999999989        3.1874849202000002        3.4365636569180902        7.2479011473183003E-002
