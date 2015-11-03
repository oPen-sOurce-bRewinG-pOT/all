	program code
	real, dimension (100,5) :: z
	integer m
	z=0.0
	m=0
	open(1,FILE='vr.dat')
	!open(2,FILE='vc.dat')
	open(3,FILE='vi.dat')
	open(4,FILE='scale.dat')
	print*, "No. of iterations"
	read*, m
	do i=1,m
	read(1,*), z(i,1)
	end do
	!do i=1,m
	!read(2,*), z(i,2)
	!end do
	do i=1,m
	read(3,*), z(i,3)
	end do
	do i=1,m
	z(i,4)=z(i,1)/z(i,3)
	!z(i,5)=z(i,2)/z(i,3)
	end do
	do i=1,m
	write(4,*), z(i,4)
	end do
	end program code
