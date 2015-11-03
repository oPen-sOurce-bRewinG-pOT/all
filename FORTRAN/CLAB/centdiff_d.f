	!Sunip Kumar Mukherjee, UG 3 Physics 346 (2015)
	!This program calculates the value of the derivative of a function
	!at a specified point, and also calculates the actual derivative,
	!provided the expression is included in te program.

	function f(x)
	double precision, intent (in) :: x
	double precision f
	f= (x**2)*dexp(-x)	!Function
	end function

	function g(x)
	double precision, intent (in) :: x
	double precision g
	g= x*(2-x)*dexp(-x) 	!derivative
	end function

	program centdiff
	double precision, dimension (10000,4) :: z
	double precision x, h, k
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
	z(i,3)=z(i,2)-g(x)
	z(i,4)=z(i,3)/(k**2.0d0)
	end do
	open(1,FILE='centdiff.dat')
	do i=1,n
	write(1,*),(z(i,j),j=1,4)
	end do
	print*, "The numerical derivative is: ", z(n,4)
	print*,
	print*, "The actual derivative is: ", g(x)
	end program centdiff
	
