	function f(x)
	real x, f
	f=x**2
	end function

	program gen
	real x, f
	open(1,FILE='indat.dat')
	do i=1,5
	write(1,*), x, f(x)
	x=x+0.3
	end do
	end program gen
