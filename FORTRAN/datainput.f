	program linearfit
	real, dimension (1000,5) :: z
	integer m, reason
	real a, b, c, d, e, f, g
	z=0.0
	m=0
	a=0.0
	b=0.0
	c=0.0
	d=0.0
	e=0.0
	f=0.0
	g=0.0
	open(1,FILE='fitinput.dat')
	!open(2,FILE='fitoutput.dat')
	do
	read(1,*,IOSTAT=Reason) z(i,1)
	if (reason==0) then
	m=m+1
	else
        continue
        end if
        end do
        do i=1,m
        print*,(z(i,j),j=1,2)
        end do
        print*, m
        end program linearfit

