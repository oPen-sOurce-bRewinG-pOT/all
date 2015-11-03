/*
    This is a simple example for Dynamic Creator library.
*/

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
    		mts[j] = get_mt_parameter_id_st(32,521,200*j,4172);
		if (mts[j] == NULL){printf("Error on %d thread.\n", j);}
    		else {sgenrand_mt(3241+40*j,mts[j]);}
    	}
}

int main(void)
{
    int i, j, id;
    //printf("Enter number of threads: ");
    //scanf("%d", &k);
    omp_set_num_threads(N_THR);
    
    generator(N_THR);
    
    #pragma omp parallel for
    for (i=0;i<100;i++) 
    {
    	id = omp_get_thread_num();
    	printf("%lf %d\n", genrand_mt(mts[id])*1.0/4294967295, id);
    }
    for (j=0;j<N_THR;j++)
    {
    	free(mts[j]);
    }
	
   return 0;
}

