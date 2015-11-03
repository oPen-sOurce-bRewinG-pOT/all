	program ndmatrix
	integer n
	real, dimension (1000,1000) :: a, b, z
	a=0
	b=0
	z=0
	print*, "Enter dimension of square matrix"
	read*, n
	print*,
	print*, "The elements should be entered in a row by row basis."
	print*, 
	print*, "Enter the elements of the first matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,n
	read*, (a(i,j),j=1,n)
	end do
	print*,
	print*, "Enter the elements of the second matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,n
	read*, (b(i,j),j=1,n)
	end do
	do i=1,n
	do k=1,n
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
	do i=1,n 
	print*,(z(i,j),j=1,n)
	print*,
	end do
900	format(A,F16.3)
	end program ndmatrix
