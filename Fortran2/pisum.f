	program pisum
	integer :: i
	real :: c
	c=0.0
	do i=1,100000
	c=c+(i**(-2.0)) !summing forward
	end do
	c=c*6.0
	c=sqrt(c) !obtaining pi using sum=pi^2/6
	print*, "Forward summing produces pi=", c
	c=0.0 !we again reset c to zero to go backward
	do i=100000,1,-1
	c=c+(i**(-2.0)) !summing
	end do
	c=c*6.0
	c=sqrt(c)
	print*, "Backward summing produces: ", c
	c=2.0*asin(1.0)
	print*, "Pi using functions:", c
	end program pisum
