	implicit none
	real lag,x(100),y(100),prod,a,b 
	integer n,i,j
	write(*,*)"enter the number of data points"
	read(*,*)n
	do 10 i=1,n
	write(*,*)"enter x "
	read(*,*)x(i)
	write(*,*)"enter y "
	read(*,*)y(i)
10	continue
	write(*,*)"enter x where value is needed "
	read(*,*)a
c lagrange
	do 11 i=1,n
	prod=1.0
	do 12 j=1,n		
	if (j.eq.i) then
	prod=prod
	else 
	prod=prod*(a-x(j))/(x(i)-x(j))
	end if
12 	continue
	lag=lag+prod*y(i)
11 	continue
	write(*,*)"value of y is",b
	end
