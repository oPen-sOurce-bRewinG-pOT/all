	program rpb
	real d 
	integer i, j, k, x, y, c
	d=0
	do i=1,10000
	x=0
	y=0
	c = floor(4*rand())
	!print*, c
	if (c==0) then
	x=x+1
	else if (c==1) then
	y=y+1
	else if (c==2) then
	x=x-1
	else
	y=y-1
	end if
	j=0
10	if ((x.ne.0).or.(y.ne.0)) then
	c=floor(4*rand())
	if (c==0) then
	x=x+1
	else if (c==1) then
	y=y+1
	else if (c==2) then
	x=x-1
	else
	y=y-1
	end if
	j=j+1
	if (j==100000) then
	d=d-1
	goto 11
	end if
	goto 10
	else
	continue
	end if
11	d=d+1
	end do
	d=d/100
	print*, d
	end program rpb
