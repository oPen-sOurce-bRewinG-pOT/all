	!Sunip Kumar Mukherjee, UG 3 Physics 346 2015
	!Program to numerically generate solutions of differential
	!equations using modified Euler method.

	function f(m, Q, h)
	double precision m, Q, f, h
	f=-m+dtanh((m+h)/Q)
	end function

	function h(t,g,a)
	double precision h,t,a,g,pi
	pi=4*dasin(1.0d0)
	h=a*dsin(2*pi*g*t)
	end function
	
	program euler
	double precision, dimension (1000000) :: x, y
	double precision f, h, Q, k, p, pi, r, s, g, a
	integer n
	open(1,file='magnet.dat')
	pi=4*dasin(1.0d0)
	print*, "Enter inital conditions in x0, y0 format, separated"
	print*, "by space: "
	read*, x(1), y(1)
	print*, "Enter the separation b/w neighbouring points: "
	read*, r
	print*, "Enter the number of points you want to generate: "
	read*, n
	print*, "Enter Temperature: "
	read*, Q
	print*, "Enter amplitude of external field: "
	read*, a
	print*, "Enter frequency of external field: "
	read*, g
	write(1,*), x(1), y(1), h(x(1), g, a)
	k=r/2.0d0
	do i=2,n
	x(i)=x(i-1)+r
	s=h(x(i-1),g,a)
	p=f(y(i-1),Q,s)
	y(i)=y(i-1)+(k*(f(y(i-1),Q,s)+f((y(i-1)+p*r),Q,s)))
	write(1,*), x(i), y(i), h(x(i),g,a)
	end do
	end program euler
