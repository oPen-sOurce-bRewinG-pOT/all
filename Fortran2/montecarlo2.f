c	Sunip Kumar Mukherjee, UG 3 Physics 346, 2015
c	Integration using statistical method

	function f(x)
	double precision x
	double precision f
	f=dexp(x)
	end function
	
	program montecarlo
	double precision, dimension(1000000, 5) :: z
	double precision x, f, a, b, fmax, l, y, integral, c, p
	integer n
	print*, "Enter lower limit: "
	read*, a
	print*, "Enter upper limit: "
	read*, b
	!Determination of maxima within the given limits
	fmax=f(a)
	l=a-0.0001
200	l=l+0.0001
	if (l<b) then
	if (f(l)>fmax) then
	fmax=f(l)
	else
	continue
	end if
	else
	goto 210
	end if
	goto 200
210	print*, "Sample size: "
	read*, n
	p=0.0d0
	!Random points generation and counting
	do i=1,n
	x=a+((b-a)*rand())
	y=fmax*rand()
	if (f(x).GE.y) then
	p=p+1
	else
	continue
	end if
	end do
	fmax=(p/n)*(b-a)*fmax
	print*, "The integral with", n,"samples is: ", fmax
	end program montecarlo
c	Results:
c	Number of points	Integral
c	10			1.902797
c	100			1.712517
c	1000			1.777756
c	10000			1.719014
c	100000			1.717919
c	1000000			1.718723
c	10000000		1.718412
c	1000000000		1.718327
c	Actual value: 1.718282	
