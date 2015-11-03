	program generator
	double precision, dimension (1000,3) :: x
	double precision a
	open(1,FILE='3c279_fermi1')
	open(2,FILE='raw_x.dat')
	print*, "Data length: "
	read*, n
	do i=1,n
	read(1,*), (x(i,j),j=1,3)
	end do
	a=x(1,1)
	a=a+1
	do i=1,n
10	continue
	if ((a/=x(i+1,1)).AND.(i+1.LE.n)) then
	!y(j)=a
	!j=j+1
	write(2,*), a
	a=a+1
	goto 10
	else
	a=a+1
	continue
	end if
	end do
	end program generator
	
