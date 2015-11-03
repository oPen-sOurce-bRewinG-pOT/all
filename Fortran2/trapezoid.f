c	Sunip Kumar Mukherjee, UG3 Physics 346
c	Computation of definite integral using trapezoidal method

	function f(x)
	double precision, intent (in) :: x
	double precision f
	f=dexp(x)
	end function 
	
	program trapezoidal
	double precision x, f, a, b, int, h, k
	integer n
	print*, "Lower limit: "
	read*, a
	print*, "Upper limit: "
	read*, b
	print*, "Enter sample size: "
	read*, n
	h=(b-a)/n
	k=f(a)
	do i=1,n
	k=k+f(a+(i*h))
	end do
	int=(h/2)*(f(a)+f(b)+(2*k))
	print 900, "The integral is: ", int
900	format (A,F10.6)
	end program trapezoidal

c	Results:
c	Number of divisions	Integral
c	10			2.091542
c	100			1.755479
c	1000			1.722000
c	10000			1.718654
c	100000			1.718319
c	1000000			1.718286

c	Actual value: 1.718282
	
		
	
