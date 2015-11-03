	!Sunip Kumar Mukherjee, UG3- Physics 346, 2015
	!Integration using Simpson's 1/3rd rule.

	function f(x)
	double precision, intent (in) :: x
	double precision f
	f=dexp(x)
	end function 
	
	program simpson
	double precision x, f, a, b, int, h, k
	integer n
	print*, "Lower limit: "
	read*, a
	print*, "Upper limit: "
	read*, b
101	print*, "Enter sample size (an even integer): "
	read*, n
	if (mod(n,2) .NE. 0) then
	print*, "Please enter an even integer: "
	goto 101
	else
	continue
	end if
	h=(b-a)/n
	do i=0,n,2
	int=int+((h*(f(a+i*h)+4*f(a+(i+1)*h)+f(a+(i+2)*h)))/3)
	end do
	print 900, "The integral is: ", int
900	format (A,F10.6)
	end program simpson

c	Results:
c	Number of divisions	Integral
c	10			2.320118	
c	100			1.773195
c	1000			1.723724
c	10000			1.718826
c	100000			1.718336
c	1000000			1.718287
c	10000000		1.718282
c
c	Actual value: 1.718282
	
