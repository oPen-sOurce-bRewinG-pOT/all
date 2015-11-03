	!Sunip Kumar Mukherjee, UG 3 Physics 346 2015
	!Program to numerically generate solutions of differential
	!equations using Taylor's method.

	function f1(x,y)		!First derivative
	double precision f1, x, y
	f1=x+y
	end function

	function f2(x,y)		!2nd Derivative
	double precision f2, x, y
	f2=1+x+y
	end function

	function f3(x,y)		!3rd Derivative
	double precision f3, x, y
	f3=1+x+y
	end function

	function f4(x,y)		!4th Derivative
	double precision f4, x, y
	f4=1+x+y
	end function

	function fac(r)			!Factorial calculator
	double precision fac
	integer r
	if (r==0) then
	fac=1
	else
	fac=1
	do i=1,r
	fac=i*fac
	end do
	end if
	fac=fac
	end function

	function ero(actual,obtained)      !Error calculator
	double precision ero, actual, obtained
	ero=(actual-obtained)/actual
	end function

	function g(x)                      !Actual solution
	double precision x, g
	g=2*dexp(x)-x-1
	end function

	program taylor
	double precision, dimension (50000) :: x, y
	double precision fac, f1, f2, f3, f4, h, k, l, ero, g
	integer n
	open(1,file='taylor.dat')
	print*, "Enter x0, y0: "
	read*, x(1), y(1)
	print*, "Enter the separation between points to be generated:"
	read*, h
	print*, "Enter number of points to be generated: "
	read*, n
	write(1,*), x(1), y(1), g(x(1)), ero(g(x(1)),y(1))
	do i=2,n
	x(i)=x(i-1)+h
	k=x(i-1)
	l=y(i-1)
	y(i)=l+(f1(k,l)*h)+(f2(k,l)*(h**2)/fac(2))
     >	+(f3(k,l)*(h**3)/fac(3))+(f4(k,l)*(h**4)/fac(4))
	write(1,*), x(i), y(i), g(x(i)), ero(g(x(i)),y(i)) 
	end do
	print*, "Success!"
	end program taylor

c             X                           Y (solved)           Actual Y                    Error 
c       0.0000000000000000        1.0000000000000000        1.0000000000000000        0.0000000000000000     
c       0.10000000000000001        1.1103416666666668        1.1103418361512953        1.5264184689400791E-007
c       0.20000000000000001        1.2428051417013890        1.2428055163203395        3.0143006738199110E-007
c       0.30000000000000004        1.3997169941250756        1.3997176151520065        4.4368015681790025E-007
c       0.40000000000000002        1.5836484801613715        1.5836493952825408        5.7785591432867606E-007
c       0.50000000000000000        1.7974412771936767        1.7974425414002564        7.0333629616791534E-007
c       0.59999999999999998        2.0442359241838668        2.0442376007810177        8.2015767161789050E-007
c       0.69999999999999996        2.3275032531935547        2.3275054149409531        9.2878297276756110E-007
c       0.79999999999999993        2.6510791265846319        2.6510818569849350        1.0299192746508043E-006
c       0.89999999999999991        3.0192028275601430        3.0192062223138993        1.1243861817836723E-006
c       0.99999999999999989        3.4365594882703330        3.4365636569180902        1.2130279469190058E-006
	
