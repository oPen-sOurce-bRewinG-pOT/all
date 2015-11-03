	!This program computes the integral of a function whose 1st and second derivatives are given, in a region where only one maxima or minima is present and the function is positive everywhere in that zone. You'll obtain an error if you neglect my advice. The method is unweighed Monte-Carlo method, and incorporates Newton-Raphson method to determine whether there is a maxima or a minima of the function in the region of interest.
	function f(x)
	real, intent(in) :: x
	real f
	!f=x*exp(-x)
	!f=2*sin(x)
	f=exp(x)
	!f=sin(2*x)
	end function

	function g(x)
	!derivative
	real, intent (in) :: x
	real g
	!g=(-x+1)*exp(-x)
	!g=2*cos(x)
	g=exp(x)
	!g=2*cos(2*x)
	end function

	function h(x)
	!double derivative
	real, intent (in) :: x
	real h
	!h=(x-2)*exp(x)
	!h=-2*sin(x)
	h=exp(x)
	!h=-4*sin(4*x)
	end function

	program montecarlo
	real a, b, l, x, c	!lower limit, upper limit, height of rectange from 0, middle region, second number for newton raphson
	real, dimension (1000000,2) :: Y	!generator of points
	integer n, p	!number of sample points, number of accepted points
	
	print*, "The function should not have more than one max min"
	print*, "in the region of interest"
	print*, "Please enter the lower limit of integration: "
	read*, a
	print*, "Please enter the upper limit of integration: "
	read*, b
	!b=4*asin(1.0) !in case you need to enter some strange constant.
	x=(a+b)/2
	!print*, f(a), f(b), f(x) !in case you really want to see the values do not run negative.
	if ((f(a)<0).OR.(f(b)<0).OR.(f(x)<0)) then
	goto 5001 !5001 is the error message
	else
	continue
	end if
	c=x+0.1
1001	x=x-(g(x)/h(x))
	k=(x-c)**2
	c=x
	!z=f(x)
	!print*, z
	if ( (k .GE. 0.000001).OR.(f(c).NE.0)) then
	i=i+1
	if(i==99999999) then
	goto 1000
	else
	continue
	end if
	goto 1001
	else
	goto 1000
	end if
1000	continue
      	!print*, c !in ase you want the location of maxima minima
	if ((c<a).OR.(c>b).OR.c/=c) then !maxima-minima outside range of interest or does not exist, we simply make the rectangle bu taking end points.
	if (f(a)>f(b)) then
	Z=(b-a)*f(a)
	print*, "Lower limit rectangle"
	else
	Z=(b-a)*f(b)
	print*, "Upper limit rectangle"
	end if
	else 	
	if ((h(c)<0).AND.(f(c)>0).AND.((c>a).AND.(c<b))) then !maxima in the region
	Z=(b-a)*f(c)
	print*, "The function has a maxima."
	else if ((h(c)<0).AND.(f(c)<0) .AND.((c>a).AND.(c<b))) then 
	print*, "Negative local maxima! Bad function!"
	print*, c
	goto 5001
	else if ((h(c)>0).AND.(f(c)<0) .AND.((c>a).AND.(c<b))) then
	print*, "Negative local minima! Bad function!"
	print*, c
	goto 5001
	else if ((h(c).GE.0).AND.(f(c).GE.0)) then !local minima, but positive! Again we take end points.
	if (f(a)>f(b)) then
	Z=(b-a)*f(a)
	print*, "Lower limit rectangle"
	else
	Z=(b-a)*f(b)
	print*, "Upper limit rectangle"
	end if
	end if
	end if
	print*, "Area of the rectange is:", Z
	!print*, c
	!print*,f(c)
	l=Z/(b-a) !Determining the range of Y values.
	p=0 !counter of points initialized
	!print*, l
	print*, "Enter number of sample points: "
	read*, n
	do i=1,n
	Y(i,1)=a+((b-a)*rand()) !X coordinate generated between (a,b) randomly.
	Y(i,2)=l*rand() !Y coordinates generated between (0,l) randomly.
	end do
	do i=1,n
	if ((f(Y(i,1))).GE.Y(i,2)) then !checking if the random point lies in the function or out of it.
	p=p+1 !counting how many points went in
	else
	continue
	end if
	end do
	!q=0
	!do i=1,n
	!if (Y(i,2) .GE. 1) then
	!q=q+1
	!else
	!continue
	!end if
	!end do
	!print*, q
	open(1,FILE='mcout.dat') !in case you want the randomly generated co-ordinates.
	do i=1,n
	write(1,*), (Y(i,j),j=1,2)
	end do
	print*, "The integral is: ", (p*Z/n)
      	print*, "Number of accepted samples: ", p
	goto 5000
5001	print*, "Error in function!"
5000	continue
	end program montecarlo
	
	
