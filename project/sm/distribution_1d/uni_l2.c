#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int rnd()
{
	int result;
	result = floor(2.0*rand()/RAND_MAX);
	return result;
}
main()
{
	int x, i, j, k, p, q, a[2001];
	float z, y;
	for (i=0;i<2001;i++)
	{
		a[i]=0;
	}
	for (i=0;i<1000000;i++)
	{
		x=0;
		for (j=0;j<1000;j++)
		{	
			p=rnd();
			y=rand()*1.0/RAND_MAX;
			if (y>0.5) //laziness
			{
				if (p==0)
				{
					x+=1;
				}
				else
				{	
					x-=1;
				}
			}
		}
		x=x+1000;
		a[x]+=1;
	}
	p=a[0];
	for (i=0;i<2001;i++)
	{
		if (p<a[i])
		{
			p=a[i];
			q=i;
		}
	}

	for (i=0;i<2001;i++)
	{
		if ((i%2)==0)
		{
			z=a[i]*1.0/p;
			k=i-1000;
			printf("%d %f\n", k, z);
		}
	}
}

