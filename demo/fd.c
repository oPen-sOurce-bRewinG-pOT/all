#include <stdio.h>
#include <math.h>
float f( float x )
{
	float result ;
	result = x * exp(x) ;
	return result ;
}

main()
{
	float act, x, err, h;
	printf("#Enter where you want to calculate the derivative:\n");
	scanf("%f", &x);
	act = ( x + 1 ) * exp ( x ) ; // Actual derivative
	FILE *fp;
	fp = fopen("data5", "w+");
	for ( h = 0.1 ; h >= 0.01 ; h -= 0.01 )
	{
		err = f ( x + h ) - f ( x - h ) ;
		err = err / ( 2 * h ) ;
		err = act - err ;
		err = err / h ;
		fprintf ( fp, "%f %f\n", h, err ) ;
	}
	fclose(fp);
}
