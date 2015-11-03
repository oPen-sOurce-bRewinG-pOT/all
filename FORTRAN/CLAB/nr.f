	!This program computes the root of f(x)=0, provided f(x) and f'(x) are defined. It relies on the fact that very close to the root, the position of the root becomes stationary, and we obtain the root to an accuracy of 1/100000. If that is not the case, the program accepts the result of the 99999998th iteration as root. It uses Newton-Raphson Method. For multi root equation, the root depends on the choice of the initial parameters.
	function f(x)
	real, intent(in) :: x
	real :: f
	f=((0.5/p)*sqrt((1/(l*c))-((x**2)/(l**2))))-h
	!f=tan(x)
	!f=cos(x)-sqrt(3.0)*sin(x)
	!f=x**3-x**2
	!f=x**3-3*sin(x)
	!f=x**2
	end function

	function g(x)
	real, intent(in) :: x
	real :: g
	g=-(8*p*p)*2*x/(l*l*f(x))
	!g=(cos(x))**(-2.0)
	!g=-sin(x)-sqrt(3.0)*cos(x)
	!g=3*(x**2)-2*x
	!g=3*(x**2)-3*cos(x)
	!g=2*x
	end function

	program nr
	real x, a, k, pi, l, c, h
      p=2*asin(1.0)
      l=30*(10**(-3))
      c=97.8E-9
      h=2.89E3
	i=1
	print*, "Enter initial guess: "
	read*, x
	print*, "Enter another number: "
	read*, a
1001	x=x-(f(x)/g(x))
	k=(x-a)**2
	a=x
	!z=f(x)
	!print*, z
	if ( (k .GE. 0.000001).OR.(f(a).NE.0)) then
	i=i+1
	if (i==99999) then
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
