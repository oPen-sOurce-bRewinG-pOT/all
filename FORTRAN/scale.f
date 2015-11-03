	program scaler
	!This program scales data in X Y format. The data file needs to be created in the following
	!manner: First column will contain X data and Y column will contain Y data, separated
	!by a tab. No heading is allowed. The file should bear the name input.dat, and scaled
	!output will be produced in output.dat. Note that the binary and input.dat must be in the 
	!same directory.
	real, dimension (1000,4) :: z
	integer m
	real a, b, c, d
	z=0.0
	m=0
	a=0.0
	b=0.0
	open(1,FILE='input.dat')
	open(2,FILE='output.dat')
	print*, "Enter X axis unit (physical)"
	read*, a
	print*, "Enter equivalent graph squares"
	read*, b
	print*, "Enter Y axis unit (physical)"
	read*, c
	print*, "Enter equivalent graph squares"
	read*, d
	e=b/a
	f=d/c
	print*, "Enter no of iterations"
	read*, m
	do i=1,m
	read(1,*), (z(i,j),j=1,2)
	z(i,3)=e*z(i,1)
	z(i,4)=f*z(i,2)
	write(2,*), (z(i,j),j=3,4)
	end do
	end program scaler
