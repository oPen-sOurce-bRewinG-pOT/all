	!Sunip Kumar Mukherjee, UG 3 Physics 346, 2015
	!Newton divided difference interpolation technique
	program newton
	double precision, dimension (1000, 1010) :: z
	double precision, dimension (2000) :: x
	double precision, dimension (1000, 4) :: tmp
	double precision, dimension (2000) :: yx 
	double precision w, y
	integer a, b, c, i, j, k, l
	open(1,FILE='indat.dat')
	open(2,FILE='inx.dat')
	open(3,FILE='difftbl.dat')
	open(4,FILE='outdat.dat')
	z=0.0d0
	x=0.0d0
	tmp=0.0d0
	print*, "Enter dimension of data matrix: "
	read*, a, b
	do i=1,a
	read(1,*), (tmp(i,j),j=1,b)
	end do
	print*, "Select Y column from the data matrix: "
	read*, b
	print*, "Enter number of points to be interpolated: "
	read*, c
	do i=1,c
	read(2,*), x(i)
	end do
	do i=1,a
	z(i,1)=tmp(i,1)	!taking x and y in calculation matrix
	z(i,2)=tmp(i,b)
	end do
	!Calculating the difference table
	j=1
	do k=2,a+1
	do i=1,a
	if (i+j .LE. a) then
	z(i,k+1)=(z(i+1,k)-z(i,k))/((z(i+j,1)-z(i,1)))
	else
	continue
	end if
	end do
	j=j+1
	end do
	do i=1,a
	write(3,*), (z(i,j),j=1,a+1)
	end do
	j=1
	do i=1,c
	print*, x(i), tmp(j,1)
10	if (x(i)>tmp(j,1)) then
	j=j+1
	else
	goto 11
	end if
	goto 10
11	continue
	print*, tmp(j,1)	
	y=tmp(j,2)
	l=1
	do k=0,j-1
	w=1
	do m=1,l
	w=w*(x(i)-tmp(j+m-1,1))
	end do
	l=l+1
	y=y+(w*z(j-k,3+k))
	end do
	yx(i)=y
	print*, i
	end do
	do i=1,c
	write(4,*), x(i), yx(i), (x(i)**2)
	end do
	end program newton
	
