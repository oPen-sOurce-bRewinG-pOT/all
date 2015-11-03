#include<stdio.h>
#include<math.h>
float f(float x)
{
	float result;
	result=exp(-x*x);
	return result;
}
main()
{
	float a, b;
	for ( a = -5; a<=5; a+=0.1)
	{
		b=f(a);
		printf("%f %f\n", a, b);
	}
}
