#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int rnd()
{	
	int result;
	result = floor(4.0*rand()/RAND_MAX);
	return result;
}
main()
{	
	int i, j, k=0, c, n=1000, m=1000000, x, y;
	float d=0;
	for (i = 0; i < n ; i++)
	{
		x=0;
		y=0;
		c = rnd();
		if (c==0)
		{
			x+=1;
		}
		else if (c==2)
		{
			y+=1;
		}
		else if (c==3)
		{
			x-=1;
		}
		else
		{
			y-=1;
		}
		for ( j = 0; j < m; j++)
		{
			if ((x==0)&&(y==0))
			{
				d+=1;
				break;
			}
			c = rnd();
			if (c==0)
			{
				x+=1;
			}
			else if (c==1)
			{
				y-=1;
			}
			else if (c==2)
			{
				x-=1;
			}
			else
			{
				y+=1;
			}
		}
	}
	d=d/n;
	printf("%f\n", d);
}
