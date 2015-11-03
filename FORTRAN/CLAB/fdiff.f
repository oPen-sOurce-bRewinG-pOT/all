	function f(x)
	real, intent (in) :: x
	real f
	f=(x**2)*exp(-x)
	end function
	
	function g(x)
	real, intent (in) :: x
	real g
	g=x*(2-x)*exp(-x) !derivative of f
	end function
	
	program forward
	real, dimension (1000,4) :: z
	real x, h, k
	z=0.0
	print*, "Enter where you need the derivative: "
	read*, x
	print*, "Enter number of sample: "
	read*, n
	open(1,FILE='fdiff.dat')
	do i=1,n
	h=1.0
	k=h/i
	z(i,1)=k
	z(i,2)=(f(x+k)-f(x))/k
	z(i,3)=z(i,2)-g(x)
	z(i,4)=z(i,3)/k
	write(1,*), (z(i,j),j=1,4)
	end do
	print*, "The numerical derivative is: ", g(x)
	end program forward
	
