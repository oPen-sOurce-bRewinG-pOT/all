	program oddsum
	integer :: i, c   !This is a comment, ignored by compiler.
	c=0 !integer c set to be zero
	do i=1,100 !do loop started, step 1.
	if (mod(i,2)==1) then !checking if i is odd, as odd=2*n+1
	c=c+(i*i)
	end if
	end do
	print*, c
	end program oddsum
