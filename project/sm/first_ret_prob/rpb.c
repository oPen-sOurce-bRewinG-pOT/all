#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ran()
{
	int result;
	float p;
	p = (4.0*rand())/RAND_MAX;
	result = floor(p);
	return result;
}
main()
{
	int i, j, k=0, c, x, y, n=10000, m=10000;
	float d=0;
	for (i=0 ; i < n; i++)
	{
		x=0, y=0;
		c=ran();
		if (c==0)
		{	
			x+=1;
		}
		else if (c==1)
		{
			y+=1;
		}
		else if (c==2)
		{
			x-=1;
		}
		else
		{	
			y-=1;
		}
		j=0;
		do
		{
			c=ran();
			if (c==0)
			{
				x+=1;
			}
			else if (c==1)
			{
				y+=1;
			}
			else if (c==2)
			{
				y-=1;
			}
			else
			{	
				x-=1;
			}
			j+=1;
			if (j==m)
			{
				d-=1;
				k+=1;
				break;
			}
		}while((x!=0)||(y!=0));
		d+=1;
	}
	d=d/n;
	printf("%f %d\n", d, k);
}
