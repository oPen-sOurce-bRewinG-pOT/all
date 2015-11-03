c	Sunip Kumar Mukherjee, UG 3 Physics 346
c      Linear Fitting (Least Square)	
	program linearfit
	double precision, dimension (1000,5) :: z
	integer m
	double precision a, b, c, d, e, f, g
	z=0.0d0
	m=0
	a=0.0d0
	b=0.0d0
	c=0.0d0
	d=0.0d0
	e=0.0d0
	f=0.0d0
	g=0.0d0
	open(1,FILE='fitinput.dat')
	open(2,FILE='fitoutput.dat')
	print*, "Enter number of data"
	read*, m
	do i=1,m
	read(1,*), (z(i,j),j=1,2) !reads X, Y
	z(i,3)=z(i,1)*z(i,2) ! calculating x_i * y_i
	z(i,4)=(z(i,1))*z(i,1) !calculating x_i ^2
	z(i,5)=z(i,3)*z(i,1) !calculating x_i ^2 y_i
	c=c+z(i,1) !calculating sum x_i
	d=d+z(i,2) !calculating sum y_i
	e=e+z(i,3) !calculating sum x_i * y_i
	f=f+z(i,4)	!calculating sum x_i ^2
	g=g+z(i,5) !calculating sum x_i^2 y_i
	end do
	h=m*f-(c*c)
	a=(m*e-(c*d))/h
	b=(d-a*c)/m
	print*, "The value of m in y=mx+c is:"
	print*, a
	print*, "The value of c in y=mx+c is:"
	print*, b
	write(2,*), "The value of m in y=mx+c is:"
	write(2,*), a
	write(2,*), "The value of c in y=mx+c is:"
	write(2,*), b
	!The following lines will print the entire matrix used
	!do i=1,m
	!print*, (z(i,j),j=1,5)
	!end do
	end program linearfit
	
