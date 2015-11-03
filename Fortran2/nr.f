	!Sunip Kumar Mukherjee, UG 3, Physics 346, 2015

	!This program computes the root of f(x)=0, provided f(x) 
	!and f'(x) are defined. It relies on the fact that very close 
	!to the root, the position of the root becomes stationary, 
	!and we obtain the root to an accuracy of 1/100000. If that is 
	!not the case, the program accepts the result of the 999998th 
	!iteration as root. It uses Newton-Raphson Method. For multi 
	!root equation, the root depends on the choice of the initial 
	!parameters.
	function f(x)
	real, intent(in) :: x
	real :: f
	f=(x**2)*exp(-x)
	end function

	function g(x)
	real, intent(in) :: x
	real :: g
	g=(2*x-x**2)*exp(-x)
	end function

	program nr
	real x, a, k
	i=1
	print*, "Enter initial guess: "
	read*, x
	print*, "Enter another number: "
	read*, a
1001	x=x-(f(x)/g(x))
	k=(x-a)**2
	a=x
	if ( (k .GE. 0.000001).OR.(f(a).NE.0)) then
	i=i+1
	if (i==999999) then
	goto 1000
	end if
	goto 1001
	else
	goto 1000
	end if
	print*, "No. of iterations:", i
1000	print 900, "The root is =", x
	print 900, "Value of f(x) at", x, "is: ", f(x)
900	format (A,F15.7)
	end program nr	
