	program vecdot
	!This program computes the dot product of any
	! 2 n dimensional vectors
	integer n !dimension
	real s, a, b !result variable, two vector components
	n=0
	s=0.0
	print*, "Enter the dimension of the vectors: "
	read*, n
	do i=1,n
	print*, "Enter component of first vector: "
	read*, a
	print*, "Enter component of second vector: "
	read*, b
	s=s+a*b !two components are multiplied and added to the sum
	k=2*(n-i)
	if (k==0) then	!checks if you have any more components to enter
	goto 200
	else
	print*,
	print*, k, "components remaining to enter" !prints how many more you have to enter
	print*,
	print*,
	end if
200	continue
	end do
	print*,
	print*,	
	write(*,900), "The dot product of the two vectors is:", s
900	format (A,F16.3) !formatting, the output can have 16 places before decimal and 3 after it.
	end program vecdot
	
	
	
