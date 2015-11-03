#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int rnd()
{	
	int result;
	result = floor(2.0*rand()/RAND_MAX);
	return result;
}
main()
{	
	int i, j, k=0, c, n=10000, m=100000, x;
	float d=0;
	for (i = 0; i < n ; i++)
	{
		x=0;
		c = rnd();
		if (c==0)
		{
			x+=1;
		}
		else
		{
			x-=1;
		}
		for ( j = 0; j < m; j++)
		{
			if (x==0)
			{
				d+=1;
				break;
			}
			c = rnd();
			if (c==0)
			{
				x+=1;
			}
			else
			{
				x-=1;
			}
		}
	}
	d=d/n;
	printf("%f\n", d);
}
