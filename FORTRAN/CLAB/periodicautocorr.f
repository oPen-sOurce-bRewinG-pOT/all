	program autocorr
	real, dimension (1000000,3) :: z
	integer n
	real x,l
	z=0.0
	x=0.0
	y=0.0
	open (1,FILE='pautocorr.txt')
	open (2,FILE='pautocorr.dat')
	print*, "Enter sample number"
	read*, n
	print*, "Enter noise width, amplitude, freq: "
	read*, l, amp, freq
	z(1,1)=0
	call cpu_time (t1)
	do i=2,n+1
	z(i,1)=i-1
	z(i,2)=amp*sin(freq*360.0*(i-1)/asin(1.0))+(-l+(2*l*rand()))
	x=x+z(i,2)
	end do
	x=x/n
	call cpu_time (t2)
	tx=t2-t1
	print*, "Time to generate number and mean:", tx
	write(1,*), "Time to generate number and mean:", tx
	write(1,*),
	!write(2,*), "Time to generate number and mean:", tx
	!write(2,*),
	do i=2,n+1
	y=y+(z(i,2)**2)
	end do
	y=y/n
	y=y-(x**2)
	!x=0.5
	call cpu_time (t1)
	do j=1,n+1
	do i=2,(n-j+1)
	z(j,3)=(z(j,3)+((z(i+j-1,2)-x)*(z(i,2)-x)))
	end do
	z(j,3)=z(j,3)/(y*(n-j))
	end do
	call cpu_time (t2)
	ty=t2-t1
	print*, "Time to generate autocorrelation: ", ty
	write(1,*), "Time to generate autocorrelation:", ty
	write(1,*),
	!write(2,*), "Time to generate autocorrelation:", ty
	!write(2,*),
	write(1,*), "The mean is:", x
	write(1,*),
	!write(2,*), "The mean is:", x
	!write(2,*),
	call cpu_time (t1)
	do i=1,n+1
	write(1,*), z(i,1), z(i,3)
	write(2,*), (z(i,j),j=1,3)
	end do
	call cpu_time (t2)
	print*, "The average is: ", x
	print*, y
	print*, "The time to write file is:", t2-t1	
	end program autocorr
