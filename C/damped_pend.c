#include <stdio.h>
#include <math.h>
// x -> time, y -> velocity, z -> displacement
/* the differential eqn function */
double f(double z, double y)
{
	float k=1;
	return (-(z)-k*y*y);
}

/* main */
main()
{
	double x0=0, y0=0, z0=1, h=0.001, x1, y1, z1;
	int i, n=100000;
	for (i=0;i<n;i++)
	{
		printf("%lf %lf %lf\n", x0, y0, z0);
		x1=x0+h;
		y1=y0+f(z0, y0)*h; //euler
		z1=z0+y1*h; //euler
		y1=y0+((h*0.50)*(f(z0, y0)+f(z1, y1))); //modified euler
		z1=z0+((y1+y0)*(h*0.5));
		x0=x1;
		y0=y1;
		z0=z1;
	}
	printf("%lf %lf %lf\n", x0, y0, z0);
}
