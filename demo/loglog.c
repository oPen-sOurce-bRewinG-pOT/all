#include <stdio.h>
#include <math.h>
main()
{
	float a[16][2];
	int i, j;
	FILE *fp;
	fp=fopen("data", "r");
	for (i=0;i<16;i++)
	{	for (j=0;j<2;j++)
		{
			fscanf(fp, "%f", &a[i][j]);
		}
		a[i][1]=log(-log(a[i][1]));
	}
	for (i=0;i<16;i++)
	{
		for (j=0;j<2;j++)
		{
			printf("%f ", a[i][j]);
		}
		printf("\n");
	}
}