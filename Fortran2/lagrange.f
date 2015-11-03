	!SKM, Lagrange interpolation using data from a 10000x2 matrix (max)
	program lagrange
	double precision, dimension (10000, 8) :: raw
	double precision, dimension (10000, 3) :: indat
	double precision, dimension (10000,1) :: outdat
	double precision, dimension (10000, 8) :: outz
	double precision, dimension (10000,1) :: cof
	double precision, dimension (10000) :: x
	double precision f
	integer a, b, c
	open(1,FILE='in1.dat')	!source of data for interpolation basis
	open(2,FILE='in2.dat')	!points to be interpolated
	open(3,FILE='out1.dat')	!output
	open(4,FILE='1.dat')
	print*, "Enter length of data: "
	read*, a
	print*, "Enter columns: "
	read*, b
	do i=1,a
	read(1,*), (raw(i,j),j=1,b)
	end do
	print*, "Enter number of points to be interpolated: "
	read*, c
	read(2,*), (x(i),i=1,c)
	do i=1,c
	outz(i,1)=x(i)	!output matrix now contains "x" as first column
	end do

	do l=1,c
	z=x(l)
	do i=1,a
	f=1
	do j=1,a
	if (j.NE.i) then
	f=f*(z-raw(j,1))
	f=f/(raw(i,1)-raw(j,1))
	print*, i, j, ((z-raw(j,1))/(raw(j,1)-raw(i,1)))
c	print*, f
c	read*,
	else
	continue
	end if
	end do
	do m=2,b
	!print*, (f*raw(i,m))
	outz(l,m)=outz(l,m)+(f*raw(i,m))
	end do
	end do
	end do
	do i=1,c
	write(3,*),(outz(i,j),j=1,b)
	end do
	end program lagrange
	
	
	
