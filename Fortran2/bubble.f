	program bubble
	integer, dimension (100) :: a
	integer :: i, j, k, n, c
	print*, "Enter the number of data to be sorted: "
	read*, n
	print*, "Enter the data: "
	read*, (a(i),i=1,n)	!reading the data
10	k=0	!we set k=0, i.e. there is no swapping when we begin
	do j=1,n-1	!The loop where swapping is done, and k is set if there is swap.
	if (a(j)>a(j+1)) then
	c=a(j)
	a(j)=a(j+1)
	a(j+1)=c
	k=1
	end if
	end do
	if (k==0) then	!If there was no need of swapping, the array is sorted. So we move over to print. If there was swap, we again set k=0 and check if further swapping is necessary.
	goto 11
	else
	goto 10
	end if
11	print*, "The sorted data are: "
	print*, (a(i), i=1,n)
	end program bubble



