	!Sunip Kumar Mukherjee, UG 3 Physics 346 2015
	!Program to numerically generate solutions of differential
	!equations using modified Euler method.

	!t=0, m=0 to 1, Q=anything non zero, Q=1 is the Curie point, m usually takes 1 unit time to stabilize, 
	!so it is recommended to choose the frequency of the varying field in such a way that the time taken to
	!complete one cycle of the varying field is too large compared to 1.
	!m=1 is not sustainable at Q>0, i.e. at non zero temperature. Usually it takes 1 unit time tor Q>0 for m
	!to decrease and stabilize.

	!Possible choices:
	!t=0, m= 0 to 1
	!Q>0
	!separation=0.01
	!Number of points=100001 (will give t=100 as final)
	!amplitude of h can be anything, but >1 is not very interesting as m .LE. 1
	!frequency (g) 0.001, for 1 complete cycle at t=100

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
