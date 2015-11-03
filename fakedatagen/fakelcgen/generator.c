#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "param.h"
#include "functions.h"

//next: replace integrations with 10 point Gauss Quadrature, done
//also, OMP based jobs.

#define tnum 10 //number of objects
#define N 100 //number of days
typedef struct
{
	double time;
	double T[tnum];
	double a[tnum];
	double b[tnum];
	double r[tnum];
	double j[tnum];
}obj;

main()
{
	obj list[N];
	int i, k, modebb[tnum], modepl[tnum], modebbgen[tnum], modeplgen[tnum];
	//init
	list[0].time = date;
	for (k=0;k<tnum;k++)
	{
		list[0].T[k] = tempgen(T_avg,5e6); //bb param
		printf("T[%d] = %e\n", k, list[0].T[k]);
		list[0].b[k] = plawexp(0,1); //oldval = 0, condition = 1 //pl param exp
		printf("b[%d] = %e\n", k, list[0].b[k]);
		double totflux_c = totflux(limlowf,limhighf,list[0].T[k]); //bb flux
		list[0].a[k] = totflux_c/powerlawint(limlowf,limhighf,list[0].b[k]); //pl param normalizer
		printf("a[%d] = %e\n", k, list[0].a[k]);
		list[0].r[k] = rgen(list[0].T[k],list[0].a[k],list[0].b[k]);
		list[0].j[k] = jgen(list[0].T[k],list[0].a[k],list[0].b[k]);
		if (list[0].r[k] < 0)
		{printf("negative here! %d\n", k);}
		printf("%e\n", list[0].r[k]);
		printf("%e\n", list[0].j[k]);
		printf("Generated for object %d.\n", k+1);
	}
	for (i=0;i<tnum;i++) //variations init
	{
		modebb[i] = 0;
		modepl[i] = 0;
		modebbgen[i] = bb_var_period();
		modeplgen[i] = pl_var_period();
		
	}
	for (i=1;i<N;i++) //evolution
	{
		list[i].time=list[0].time+i;
		printf("Working for day %d.\n", i+1);
		for (k=0;k<tnum;k++)
		{
			if (modebb[k]!=modebbgen[k]) //small variation of BB
			{
				//bb param small var
				list[i].T[k] = tempgen(list[i-1].T[k], T_var_small);
				modebb[k] += 1;
			}
			else //large variation of BB
			{
				//bb param large var
				list[i].T[k] = tempgen(list[i-1].T[k], T_var_large);
				modebb[k] = 0;
				modebbgen[k] = bb_var_period();
			}
			
			if (modepl[k]!=modeplgen[k])
			{
				//pl param small var
				list[i].b[k] = plawexp(list[i-1].b[k], 0);
				//list[i].a[k] = aagen(list[i-1].a[k], 0); //t2
				modepl[k] += 1;
			}
			else
			{
				list[i].b[k] = plawexp(0,1);
				//list[i].a[k] = aagen(list[i-1].a[k], 1); //t2
				modepl[k] = 0;
				modeplgen[k] = pl_var_period();
			}
			double totflux_c = totflux(limlowf,limhighf,list[i].T[k]); //bb flux  //t1
			list[i].a[k] = totflux_c/powerlawint(limlowf,limhighf,list[i].b[k]); //pl param normalizer  //t1
			list[i].a[k] = list[i-1].a[k] + ((list[i].a[k] - list[i-1].a[k])/4); //t1_new
			list[i].r[k] = rgen(list[i].T[k],list[i].a[k],list[i].b[k]);
			list[i].j[k] = jgen(list[i].T[k],list[i].a[k],list[i].b[k]);
			if (list[0].r[k] < 0)
			{printf("negative here! %d\n", k);}	
			//printf("Working on object %d on day %d.\n", k+1, i+1);
		}
	}
	//file generation
	FILE *fp;
	fp = fopen("demo.dat", "w+");
	fprintf(fp,"# date ");
	for (k=0;k<tnum;k++)
	{
		fprintf(fp,"r[%d] j[%d] ", k, k);
		printf("%d\n", k);
	}
	fprintf(fp,"\n");
	for (i=0;i<N;i++)
	{
		fprintf(fp,"%lf ", list[i].time);
		for (k=0;k<tnum;k++)
		{
			fprintf(fp,"%e %e ", list[i].r[k], list[i].j[k]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

