	program array
	integer, dimension (3,2) :: a
	integer :: i, j
	do i=1,3
	do j=1,2
	print*, "Enter", i, ",", j,"th element."
	read*, a(i,j)
	end do
	end do
	do i=1,3
	print*, (a(i,j),j=1,2)
	end do
	end program array
