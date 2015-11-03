#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float rnd()
{
	float result;
	result = rand()/(1.0*RAND_MAX);
	return result;
}

float f(float x)
{
	float result;
	result = sin(x);
	return result;
}

main()
{
	int j, n, p = 0;
	float fmax, i , a, b, x, y, res;
	printf("Enter lower limit: ");
	scanf("%f", &a);
	printf("Enter upper limit: ");
	scanf("%f", &b);
	//b = 2.0*asin(1.0);
	fmax = f(a);
	for ( i = a ; i <= b ; i += 0.0001 )
	{
		if ( fmax < f(i) )
		{
			fmax = f(i);
		}
	}
	printf("The maxima of the function in the specified interval is: %f.\n", fmax);
	printf("Enter how many random points you want to generate: ");
	scanf("%d", &n);
	for ( j = 0 ; j < n ; j++ )
	{
		x = a + (b-a)*rnd();
		y = fmax * rnd();
		if ( y <= f(x) )
		{
			p+=1;
		}
	}
	res = (p*1.0/n)*(b-a)*fmax;
	printf("The integral is %f.\n", res);
}

