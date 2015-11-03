	function f(x)
	double precision, intent (in) :: x
	double precision :: f
	f=dexp(x)
	end function
	
	program mc
	double precision x, f, a, b, int
	integer n, p
	p=0
	int=0.0d0
	print*, "Lower limit: "
	read*, a
	print*, "Upper limit: "
	read*, b
	print*, "Sample size: "
	read*, n
	do i=1,n
	x=a+((b-a)*rand())
	int=int+f(x)
	p=p+1
	end do
	print*, "The integral is: ", (b-a)*int/n
	print*, "Actual integral: ", f(b)-f(a)
	end program mc
