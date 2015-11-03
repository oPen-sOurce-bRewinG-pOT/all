	program 3dmatrix
	real, dimension (3,3) :: a, b, z
	a=0
	b=0
	z=0
	print*,
	print*, "The elements should be entered in a row by row basis."
	print*, 
	print*, "Enter the elements of the first matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,3
	read*, (a(i,j),j=1,3)
	end do
	print*,
	print*, "Enter the elements of the second matrix, row by row. "
	print*, "i.e. write the matrix on screen as you usually do."
	print*,
	do i=1,3
	read*, (b(i,j),j=1,3)
	end do
	do i=1,3
	do k=1,3
	do j=1,3
	z(i,k)=z(i,k)+a(i,j)*b(j,k)
	!print*, z(i,k)
	!print*, i, k	
	end do
	end do
	end do
	print*,
	print*, "The product is: "
	print*,
	do i=1,3 
	print*,(z(i,j),j=1,3)
	print*,
	end do
900	format(A,F16.3)
	end program 3dmatrix
