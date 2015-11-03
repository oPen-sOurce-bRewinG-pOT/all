#include <mpi.h>
#include <dc.h>
#include <stdio.h>

mt_struct *mts[16];
void generator(int k)
{
	int j;
	for (j=0;j<k;j++)
    	{
    	/* This trys to find a small Mersenne Twister with period 2^521-1. */
    		mts[j] = get_mt_parameter_id_st(32,19937,rand() % 65536,4172);
		if (mts[j] == NULL){printf("Error on %d thread.\n", j);}
    		else {sgenrand_mt(3241+40*j,mts[j]);}
    	}
}

int main()
{
    int proc, id, 
