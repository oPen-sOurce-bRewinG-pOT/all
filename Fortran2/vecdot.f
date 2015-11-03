	program vecdot
	double precision, dimension (1,1000) :: a,b
	double precision c
	integer n
	a=0
	b=0
	c=0.0
	print*,
	print*, "The dimension of the vector should not be above 1000."
	print*,
	print*, "Enter the dimension of the vectors: "
	read*, n
	print*,
	print*, "Enter the first vector, components separated by space."
	read*, (a(1,i),i=1,n)
	print*,
	print*, "Enter the second vector, components separated by space."
	read*, (b(1,i),i=1,n)
	do i=1,n
	c=c+a(1,i)*b(1,i)
	end do
	print 900, "The dot product is =", c
900	format (A,F10.3)
	end program vecdot
	
	
