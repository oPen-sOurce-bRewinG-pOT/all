	program bubble
	real, dimension (100) :: a
	real z
	integer n, m, i, j, k
	print*, "Enter the number of data to be sorted: "
	read*, n
	m=n-1
	k=1
	print*, "Enter the data to be sorted: "
	read*, (a(l),l=1,n)
	do j=1,m
	do i=1,(n-k)
	!print*, a
	if (a(i).LE.a(i+1)) then
	goto 1001
	else
	z=a(i)
	a(i)=a(i+1)
	a(i+1)=z
	goto 1001
	end if
1001	continue
	end do
	k=k+1
	end do
	print*,
	do i=1,n
	print 900, a(i)
	print*,
	end do
900	format (F10.4)	 
	end program bubble
	
