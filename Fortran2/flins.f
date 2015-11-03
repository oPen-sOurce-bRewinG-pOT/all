	program insertion
	integer, dimension (100) :: a
	integer :: n, i, j
	integer :: c
	print*, "Enter the number of elements to be sorted: "
	read*, n
	print*, "Enter the data: "
	read*, a(1)   !We take in the 1st data
	do i=2,n      
	print*, "Enter the data: "
	read*, a(i)   !We take in the next data, and sort at the same time, remember: In insertion sort, the data to the right is already sorted
	do j=i,2,-1
	if (a(j)<a(j-1)) then
	c=a(j)
	a(j)=a(j-1)
	a(j-1)=c
	else
	goto 10       !Since the data to the right is already sorted, the place where there is no swapping, we know that the position for the a(i) is uniquely set.
	end if
	end do
10	continue
	end do
	print*, (a(i),i=1,n)
	end program insertion

