       program ndmatrix
	real, dimension (100,100) :: a, b, z
	integer :: m, n, p
	a=0
	b=0
	z=0
	print*, "Enter the dimension of the first matrix:"
	read*, m, n
	print*,
	print*, "The elements should be entered in a row by row basis."
	print*, 
	print*, "Enter the elements of the first matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,m
	read*, (a(i,j),j=1,n)
	end do
	print*,
	print*, "Enter the dimensions of the second matrix:"
	read*, k, p
	if (k.ne.n) then
	print*, "Can not be multiplied!"
	goto 10
	end if
	print*, "Enter the elements of the second matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,n
	read*, (b(i,j),j=1,p)
	end do
	do i=1,m
	do k=1,p
	do j=1,n
	z(i,k)=z(i,k)+a(i,j)*b(j,k)
	end do
	end do
	end do
	print*,
	print*, "The product is: "
	print*,
	do i=1,m
       	print*,(z(i,j),j=1,p)
	print*,
	end do
10     continue
	end program ndmatrix
