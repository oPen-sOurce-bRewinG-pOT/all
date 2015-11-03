	program lagrange
	double precision, dimension (10000,8) :: x
	double precision, dimension (10000,8) :: z
	double precision f
	integer a, b, c, i, j, k, l
	z=0
	open(1,FILE='3c279_fermi1')
	open(2,FILE='raw_x.dat')
	open(3,FILE='output.dat')
	print*, "Enter data length: "
	read*, a
	print*, "Enter data width: "
	read*, b
	do i=1,a
	read(1,*), (x(i,j),j=1,b)
	end do
	print*, "Enter number of interpolations: "
	read*, c
	do i=1,c
	read(2,*), z(i,1)
	end do
	do j=1,c
	do k=1,a
	f=1
	do i=1,a
	if (i.NE.k) then
	f=f*(z(j,1)-x(i,1))/(x(k,1)-x(i,1))
	else
	continue
	end if
	end do
	do l=2,b
	z(j,l)=z(j,l)+(f*y(k,l))
	end do
	end do
	end do
	do i=1,c
	write(3,*), (z(i,j),j=1,b)
	end do
	end program lagrange
