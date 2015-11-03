#include <stdio.h>
main()
{
	float b, a[10][2];
	int i, j;
	FILE *fp;
	fp = fopen( "data5", "r" );
	for ( i = 0 ; i < 10 ; i++ )
	{	
		for ( j = 0 ; j < 2 ; j++ )
		{
			fscanf(fp,"%f",&a[i][j]);
			//printf("%f ", b);
			//printf("%d ", j);

		}
//		printf("\n");
	}
	for ( i = 0 ; i < 10 ; i++ )
	{
		for ( j = 0 ; j < 2 ; j++ )
		{
			printf( "%f " , a[i][j] );
		}
		printf( "\n" );
	} 
	fclose(fp);
}
