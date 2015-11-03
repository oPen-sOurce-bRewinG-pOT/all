	program bm
	double precision x, y, a, b, pi, m_1, m_2, t1, t2
	open(1,file='data1.dat')
	open(2,file='data2.dat')
	pi=4.0d0*dasin(1.0d0)
	m_1=0.0d0
	m_2=0.0d0
	n=1000000
	m=n
	do i=1,n
	x=rand()
	y=rand()
	a=sqrt(-2.0d0*dlog(x))*dcos(pi*y)
	b=sqrt(-2.0d0*dlog(y))*dsin(pi*x)
	if (rand()>0.3d0) then
	!write(1,*), a
	!b=0.0d0
	m=m-1
	else
	!write(1,*), a
	write(2,*), b
	end if
	write(1,*), a
	m_1=m_1+a
	m_2=m_2+b
	!print*, a, b
	end do
	m_1=m_1/n
	m_2=m_2/m
	print*, m_1, m_2
	print*, n, m
	t1=-4.5d0
	t2=2.7d0
	close(1)
	close(2)
	open(1,file='data1.dat')
	open(2,file='data2.dat')
	do i=1,n
	read(1,*), x
	x=x-(m_1-t1)
	print*, x
	end do
	do i=1,m
	read(2,*), x
	x=x-(m_2-t2)
	print*, x
	end do
	end program
