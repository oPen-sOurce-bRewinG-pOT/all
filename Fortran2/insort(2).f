	!Insertion sorting algorithm
	!function insert
	
	program insort
	real, dimension (100,1) :: Z
	real a
	integer n
	print*, "Enter the length of unsorted data:"
	read*, n
	print*, "Enter the unsorted data:"
	print*,
	read*, (Z(i,1),i=1,n)
      	k=n-1
	do i=1,k
	l=i+1
	do 10 j=l,2,-1
102	if(Z(j,1)<Z(j-1,1)) then
	a=Z(j-1,1)
	Z(j-1,1)=Z(j,1)
	Z(j,1)=a
	a=0.0
	else
	continue
	end if
10	continue
	end do
	print*,
	print*, "The sorted data is: "
	print*,
	print*, (Z(i,1),i=1,n)
	end program insort
	
	
	
