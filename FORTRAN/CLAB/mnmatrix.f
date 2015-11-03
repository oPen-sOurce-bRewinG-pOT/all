	program mndmatrix
	integer l, m, n, p
	real, dimension (500,500) :: a, b, z
	a=0
	b=0
	z=0
	print*,
	print*, "Dimension can not cross 500x500"
	print*,
	print*, "Enter dimension of first matrix (separated by enter)"
	read*, l
	read*, m
	print*,
	print*, "Enter dimension of second matrix"
	read*, n
	read*, p
	if (m>500 .OR. n>500 .OR. l>500 .OR. p>500) then
	goto 1001
	end if
	if (m==n) then
	goto 11
	else
	goto 1000
	end if
11	print*,
	print*, "The elements should be entered in a row by row basis."
	print*, 
	print*, "Enter the elements of the first matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,l
	read*, (a(i,j),j=1,m)
	end do
	print*,
	print*, "Enter the elements of the second matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,n
	read*, (b(i,j),j=1,p)
	end do
	do i=1,l
	do k=1,p
	do j=1,n
	z(i,k)=z(i,k)+a(i,j)*b(j,k)
	!print*, z(i,k)
	!print*, i, k	
	end do
	end do
	end do
	print*,
	print*, "The product is: "
	print*,
	do i=1,l 
	print*,(z(i,j),j=1,p)
	print*,
	end do
900	format(A,F16.3)
	goto 1001
1000	print*, "These matrices can not be multiplied."
1001	continue
	end program mndmatrix
