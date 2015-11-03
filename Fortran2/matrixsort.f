	!Sunip Mukherjee, program for sorting data in matrix form using insertion sort
	!Insertion sorting algorithm
	program insort
	double precision, dimension (1000,1000) :: zdata
	double precision a
	integer n, l, m, p, q
	print*, "Enter the length of unsorted data:"
	read*, n
	print*, "Enter column number: "
	read*, m
	print*, "Enter 1 if data is in file 'sortdata.dat' else 0: "
	read*, b
	if (b==1) then
	open(1,FILE='sortdata.dat')
	do i=1,n
	read(1,*), (zdata(i,j),j=1,m)
	end do
	goto 102
	else
	continue
	end if
	print*, "Enter the unsorted data:"
	print*,
	do i=1,n
	read*, (zdata(i,j),j=1,m)
	end do
102	print*, "Enter reference coulumn number using which"
	print*, " data will be sorted"
	read*, p
        k=n-1
	do i=1,k
	!i=i+1
	l=i+1
	do 10 j=l,2,-1
	if(zdata(j,p)<zdata(j-1,p)) then
	do q=1,m
	a=zdata(j-1,q)
	zdata(j-1,q)=zdata(j,q)
	zdata(j,q)=a
	a=0.0
	end do
	else
	continue
	end if
10	continue
	end do
	if (b==1) then
	do i=1,n
	write(1,*), (zdata(i,j),j=1,m)
	end do
	goto 103
	else
	continue
	end if
	print*,
	print*, "The sorted data is: "
	print*,
	do i=1,n
	print*, (zdata(i,j),j=1,m)
	end do
103	continue
	end program insort
	
	
	
