	program sum2
	integer :: i, c
	c=0
	i=1
101	if (i .le. 10) then
	c=c+(i*i)
	i=i+1
	goto 101
	end if
	print*, c
	end program sum2
