#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "objnum.h"
#include "param.h"
#include "functions.h"

//next: replace integrations with 10 point Gauss Quadrature, done
//also, OMP based jobs.

int N, *tate;

typedef struct
{
	double time;
	double T[tnum];
	double a[tnum];
	double b[tnum];
	double r[tnum];
	double j[tnum];
}obj;

obj list [ 10000 ] ;

int main(int argc, char *arg[])
{if (argc != 8) //error message
    {printf("This code will generate Redder when brighter or Bluer when brighter Quasar Light Curves.\nBy default generates 10 objects of the given type. Use the header file \"objnum.h\" to change the number.\n\nUsage: generator <output file name> <object type (integer)> <sampling type (raw/sdss/hb)> <Black Body Variation Base> <Black Body Variation Deviation> <Power Law Variation Base> <Power Law Variation Deviation>\n");}
else
{
    mts_gen();
    int type = atof(arg[2]);
    bb_base = atof(arg[4]);
    bb_var = atof(arg[5]);
    pl_base = atof(arg[6]);
    pl_var = atof(arg[7]);
    //printf("%d\n", N);
    if (strcmp(arg[3],"sdss") == 0)
    {N = sdss[77]; tate = &sdss[0]; printf("Number of days to generate is %d.\n", N);}
    else if (strcmp(arg[3],"hb") == 0)
    {N = hb[81]; tate = &hb[0]; printf("Number of days to generate is %d.\n", N);}
    else if (strcmp(arg[3],"raw") == 0)
    {printf("Enter the number of days you want to generate the light curve for: ");
    //scanf("%d", &N); 
    N = 2000 ;}
	//obj list[N+1];
	int i, k, modebb[tnum], modepl[tnum], modebbgen[tnum], modeplgen[tnum], internalcounter=0;
	//init
	list[0].time = 0;
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
	for (i=1;i<=N;i++) //evolution
	{
		list[i].time=list[0].time+i;
		if (i%50 == 0)
		{printf("Working for day %d.\n", i+1);}
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
				if (type == 2)
				{list[i].a[k] = aagen(list[i-1].a[k], 0);} //t2}
				modepl[k] += 1;
			}
			else
			{
				list[i].b[k] = plawexp(0,1);
				if (type == 2)
				{list[i].a[k] = aagen(list[i-1].a[k], 1);} //t2}
				modepl[k] = 0;
				modeplgen[k] = pl_var_period();
			}
			if (type == 1)
			{double totflux_c = totflux(limlowf,limhighf,list[i].T[k]); //bb flux  //t1
			list[i].a[k] = totflux_c/powerlawint(limlowf,limhighf,list[i].b[k]);} //pl param normalizer  //t1}
			{
			    list[i].r[k] = (rgen(list[i].T[k],list[i].a[k],list[i].b[k]));
			    list[i].j[k] = (jgen(list[i].T[k],list[i].a[k],list[i].b[k]));
			}
			if (list[0].r[k] < 0)
			{printf("negative here! %d\n", k);}	
			//printf("Working on object %d on day %d.\n", k+1, i+1);
		}
	}
	// conversion to magnitude
	double log10 = log(10.0);
	for (i=0;i<=N;i++)
	{
	    for (k=0;k<tnum;k++)
	    {
	        list[i].r[k] = -2.5*log(list[i].r[k])/log10;
	        list[i].j[k] = -2.5*log(list[i].j[k])/log10;
	        if (type == 1)
	        {
	            double mid1 = list[i].r[k] - list[i].j[k];
	            list[i].r[k] = 4*list[i].r[k]-45;
	            list[i].j[k] = list[i].r[k] - mid1;
	        }
	    }
	}
	//file generation
	FILE *fp;
	fp = fopen(arg[1], "w+");
	fprintf(fp,"# date ");
	for (k=0;k<tnum;k++)
	{
		fprintf(fp,"r[%d] j[%d] ", k, k);
		printf("%d\n", k);
	}
	fprintf(fp,"\n");
	if (strcmp(arg[3],"raw") != 0)
	{
	    for (i=0;i<=N;i++)
	    {
	        if (i==*(tate+internalcounter))
	        {
		        fprintf(fp,"%lf ", list[i].time);
		        for (k=0;k<tnum;k++)
		        {
			        fprintf(fp,"%lf %lf ", list[i].r[k], list[i].j[k]);
		        }
		        fprintf(fp, "\n"); internalcounter++;
		    }
		}
	}
	else
	{
	    for (i=0;i<=N;i++)
		{
		    fprintf(fp,"%lf ", list[i].time);
		    for (k=0;k<tnum;k++)
		    {
			    fprintf(fp,"%lf %lf ", list[i].r[k], list[i].j[k]);
		    } 
		    fprintf(fp, "\n");
		}
	}
	fclose(fp);
}
return 0;
}
