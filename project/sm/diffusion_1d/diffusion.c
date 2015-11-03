#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int rnd()
{
	int result;
	result = floor(2.0*rand()/RAND_MAX);
	return result;
}
main()
{
	int x, i, j, k, p, q, a[200001], n=100, check;
	float z, /*final[2000001][2],*/ r1, r2, r, laziness;
	clock_t start, end, bstart, bend; //clock time variables
	double cpu_time_used;
	char filename[sizeof "Laziness_0.0.dat"];
	for (laziness=0;laziness<1.0;laziness+=0.2)
	{
	sprintf(filename, "Laziness_%.1f.dat", laziness);
	FILE *fp;
	fp=fopen(filename, "w+");
	printf("laziness parameter: %.1f\n", laziness);
	bstart=clock();
	fprintf(fp, "######################################################\n");
	fprintf(fp, "### Laziness parameter: %.1f #########################\n##############################################\n",laziness);
	for (n=100;n<=10000;n=2*n) //up to 6400, in 1000000 steps
	{
	start=clock();
	for (i=0;i<(2*n+1);i++)
	{
		a[i]=0;
		//final[i][0]=0;
		//final[i][1]=0;
	}
	for (i=0;i<1000000;i++)
	{
		x=0;
		for (j=0;j<n;j++)
		{	
			if ((rand()/(1.0*RAND_MAX))>laziness) //laziness
			{
				p=rnd();
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
		x=x+n;
		a[x]+=1;
	}
	p=a[0];
	for (i=0;i<(2*n+1);i++)
	{
		if (p<a[i])
		{
			p=a[i];
			q=i;
		}
	}
	r1=0;
	r2=0;
	check=0;
	for (i=0;i<(2*n+1);i++)
	{
		if ((i%2)==0)
		{
			z=a[i]*1.0/p;
			//k=i-n;
			//printf("%d %f\n", k, z);
			//final[i][0]=k;
			//final[i][1]=z;
			if ((z==0)&&(check==0))
			{
				r1+=2;
				r2+=2;
			}
			if((z!=0)&&(check==0))
			{
				check=1;
				r2+=2;
			}
			if((z!=0)&&(check==1))
			{
				r2+=2;
			}
		}
	}
	r=r2-r1;
	printf("%d %f %f %f\n", n, r1, r2, r);
	fprintf(fp, "%d %f %f %f\n", n, r1, r2, r);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Cpu Time = %f\n", cpu_time_used);
	}
	n=10000;
	start = clock();
	for (i=0;i<(2*n+1);i++)
	{
		a[i]=0;
		//final[i][0]=0;
		//final[i][1]=0;
	}
	for (i=0;i<1000000;i++)
	{
		x=0;
		for (j=0;j<n;j++)
		{	
			if ((rand()/(1.0*RAND_MAX))>laziness) //laziness=0.7
			{
				p=rnd();
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
		x=x+n;
		a[x]+=1;
	}
	p=a[0];
	for (i=0;i<(2*n+1);i++)
	{
		if (p<a[i])
		{
			p=a[i];
			q=i;
		}
	}
	r1=0;
	r2=0;
	check=0;
	for (i=0;i<(2*n+1);i++)
	{
		if ((i%2)==0)
		{
			z=a[i]*1.0/p;
			//k=i-n;
			//printf("%d %f\n", k, z);
			//final[i][0]=k;
			//final[i][1]=z;
			if ((z==0)&&(check==0))
			{
				r1+=2;
				r2+=2;
			}
			if((z!=0)&&(check==0))
			{
				check=1;
				r2+=2;
			}
			if((z!=0)&&(check==1))
			{
				r2+=2;
			}
		}
	}
	r=r2-r1;
	printf("%d %f %f %f\n", n, r1, r2, r);
	fprintf(fp, "%d %f %f %f\n", n, r1, r2, r);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Cpu Time = %f\n", cpu_time_used);
	bend=clock();
	cpu_time_used = ((double) (bend - bstart)) / CLOCKS_PER_SEC;
	printf("Total Cpu Time = %f\n", cpu_time_used);
	fclose(fp);
	}
}

