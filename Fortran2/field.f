	function h(t,g,a)
	double precision h,t,a,g,pi
	pi=4*dasin(1.0d0)
	h=a*dcos(2*pi*g*t)
	end function

	program field
	double precision h, t, a, g, pi
	t=0
	a=1
	g=1
	pi=4*dasin(1.0d0)
	open(1,file='demo.dat')
	do i=1,101
	write(1,*), t, 2*pi*g*t, h(t,g,a)
	t=t+0.01
	end do
	end program field
	
