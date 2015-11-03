c	Sunip Ku7mar Mukherjee, UG 3 Physics 346, 2015
c	This program calculates derivative using central difference.

	function f(x)
	double precision, intent (in) :: x
	double precision f
	f= (x**2)*dexp(-x)!Function
	end function

	function g(x)
	double precision, intent (in) :: x
	double precision g
	g= x*(2-x)*dexp(-x) !derivative
	end function

	program centdiff
	double precision, dimension (1000,4) :: z
	double precision x, h, k, f, g
	integer n
	print*, "Enter where you want to determine derivative: "
	read*, x
	print*, "Enter number of iterations: "
	read*, n
	do i=1,n
	h=1.0d0
	k=h/i
	z(i,1)=k
	z(i,2)=(f(x+k)-f(x-k))/(2.0d0*k)
	z(i,3)=g(x)-z(i,2)
	z(i,4)=z(i,3)/(k)
	end do
	open(1,FILE='centdiff.dat')
	do i=1,n
	write(1,*),(z(i,j),j=1,4)
	end do
	print 900, "The numerical derivative is: ", z(n,2)
	print*,
	print 900, "The actual derivative is: ", g(x)
900	format (A,F15.7)
	end program centdiff


	!Result:
	 
	!The numerical derivative is:       0.3678733

	!The actual derivative is:       0.3678794
	
