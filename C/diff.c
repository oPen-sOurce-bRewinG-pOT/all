#include <stdio.h>
#include <math.h>
/* the differential eqn function */
double f(double x, double y)
{
	return (x+y);
}

/* main */
main()
{
	double x0=0, y0=1, h=0.1, x1, y1;
	int i, n=10;
	for (i=0;i<n;i++)
	{
		printf("%lf %lf\n", x0, y0);
		x1=x0+h;
		y1=y0+f(x0,y0)*h; //euler
		y1=y0+((h*0.50)*(f(x0,y0)+f(x1,y1))); //modified euler
		x0=x1;
		y0=y1;
	}
	printf("%lf %lf\n", x0, y0);
}
