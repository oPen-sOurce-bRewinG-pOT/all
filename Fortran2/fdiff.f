	function f(x)
	double precision, intent (in) :: x
	double precision f
	f=(x**2)*dexp(-x)
	end function
	
	function g(x)
	double precision, intent (in) :: x
	double precision g
	g=x*(2.0d0-x)*dexp(-x) !derivative of f
	end function
	
	program forward
	double precision, dimension (1000,4) :: z
	double precision x, h, k, f, g
	z=0.0d0
	print*, "Enter where you need the derivative: "
	read*, x
	print*, "Enter number of sample: "
	read*, n
	open(1,FILE='fdiff.dat')
	k=1.0
	do i=1,n
	!if (k>0) then
	z(i,1)=k
	z(i,2)=(f(x+k)-f(x))/k
	z(i,3)=g(x)-(z(i,2))
	z(i,4)=z(i,3)/k
	write(1,*), (z(i,j),j=1,4)
	k=k-0.1
	!else
	!goto 10
	!end if
	end do
10	continue
	print*, "The numerical derivative is: ", z(n,2)
	print*, "Actual derivative: ", g(x)
	end program forward
	
