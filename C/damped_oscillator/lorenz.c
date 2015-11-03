#include <stdio.h>
#include <math.h>
// x -> time, y -> velocity, z -> displacement
/* the differential eqn function */
double f1(double x, double y)
{
	//float k=1;
	return (10*(y-x));
}
double f2(double x, double y, double z)
{
	return (x*(27-z)-y);
}
double f3(double x, double y, double z)
{
	return (x*y - (8.0*z/3.0));
}

/* main */
main()
{
	double t0=0, x0=0.2001, y0=0, z0=-0.02, h=0.005, t1, x1, y1, z1, x11, y11, z11;
	int i, n=100000;
	for (i=0;i<n;i++)
	{
		printf("%lf %lf %lf %lf\n", t0, x0, y0, z0);
		t1=t0+h;
		x1=x0+f1(x0,y0)*h; //euler
		y1=y0+f2(x0, y0, z0)*h; //euler
		z1=z0+f3(x0, y0, z0)*h; //euler
		x11=x0+((h*0.50)*(f1(x0, y0)+f1(x1, y1))); //modified euler
		y11=y0+((h*0.50)*(f2(x0, y0, z0)+f2(x1, y1, z1))); //modified euler
		z11=z0+((h*0.50)*(f3(x0, y0, z0)+f3(x1, y1, z1))); //modified euler
		t0=t1;
		x0=x11;
		y0=y11;
		z0=z11;
	}
	printf("%lf %lf %lf %lf\n", t0, x0, y0, z0);
}
