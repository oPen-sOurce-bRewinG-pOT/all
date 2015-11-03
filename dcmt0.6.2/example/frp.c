#include <stdio.h>
#include "dc.h"
#include <stdlib.h>

#include <omp.h>
#define N_THR 2
mt_struct *mts[N_THR];
void generator(int k)
{
	int j;
	for (j=0;j<k;j++)
    	{
    	/* This trys to find a small Mersenne Twister with period 2^521-1. */
    		mts[j] = get_mt_parameter_id_st(32,521,rand() % 65536,4172);
		if (mts[j] == NULL){printf("Error on %d thread.\n", j);}
    		else {sgenrand_mt(3241+40*j,mts[j]);}
    	}
}


int main()
{
	long long int ensemble=1000000, ssl=100000, sum=0, pos, posmax;
	float frp, lp; long long int i, j, ss; int kounter; int id;
	double rnd;
	
	omp_set_num_threads(N_THR);
    	generator(N_THR);
	
	
	for (ss=ssl;ss<=ssl;ss*=10)
	{
		printf("\n\n# Step Size = %lli\n# LP FRP RETTIMEAV PMAV\n\n",ss);
		for (lp=0;lp<0.1;lp+=0.1)
		{
			int tfrp=0;
			int posmaxe=0;
			sum=0;
			int enp=0;
			#pragma omp parallel for private(i, pos ,j , posmax, kounter, rnd) reduction(+:sum,enp,tfrp,posmaxe)
			for (i=0;i<ensemble;i++)
			{
				pos=0;
				posmax=0;
				kounter=0;
				for (j=0;j<ss;j++)
				{
					id = omp_get_thread_num();
					rnd = genrand_mt(mts[id])*1.0/4294967295;
					//printf("%lf\n", rnd);
					if(rnd>lp)
					{
						id = omp_get_thread_num();
						rnd = genrand_mt(mts[id])*1.0/4294967295;
						kounter=1;
						if (rnd>0.5)
						{pos+=1;}
						else
						{pos-=1;}
						//printf("%li\n", pos);
					}
					if (pos*pos>posmax)
					{posmax=pos*pos;}
					if (kounter==1 && pos==0)
					{posmaxe+=posmax;tfrp+=j+1;sum+=1;break;}	
					

				}
				//#pragma omp barrier
				enp+=1;
			}
		//	printf("\n%d\n",enp);
			frp=sum*1.0/enp;
			float avtfrp=tfrp*1.0/enp;
			float avposmax=posmaxe*1.0/enp;
			printf("%f %f %f %f %lli\n",lp,frp,avtfrp,avposmax, sum);
		}
	}
	for (j=0;j<N_THR;j++)
	{
		free(mts[j]);
	}
	//scanf("%li",&i);
	return 0;
}
