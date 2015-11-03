	program sh
	integer :: a, b
	print*, "Enter an integer: "
	read*, a
	print*, "Enter another integer: "
	read*, b
	if (a==b) then
	print*, "You have entered the same number", a, "twice."
	else
	print*, "You have entered", a, b, "."
	end if
	end program sh
