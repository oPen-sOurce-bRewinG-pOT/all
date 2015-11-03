#include <stdio.h>

int main()
{
	int i, j, k, temp ;
	for ( i = 1 ; i < 10 ; i++ )
	{
		for ( j = 0 ; j < 10 ; j++ )
		{
			for ( k = 0 ; k < 10 ; k++ )
			{
				if ( i*100+j*10+k == i*i*i + j*j*j + 
k*k*k )
				{ printf("This is an armstrong number: %d%d%d.\n", i, j, k ) ; }
			}
		}
	}
}
