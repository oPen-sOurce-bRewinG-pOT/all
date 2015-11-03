#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <dc.h>

#define N_THR 100 // maximum number of processes allowed

//this is the MT State vector
mt_struct *mts[N_THR];

void generator (int j)		//this is the generator which takes in the different ids for the processes and generates the required Mersenne Twister State
{
    	{
    	/* This trys to find a small Mersenne Twister with period 2^521-1. */
    		mts[j] = get_mt_parameter_id_st(32,521,(rand () % 200)*j,4172);
		if (mts[j] == NULL){printf("Error on %d thread.\n", j);}
    		else {sgenrand_mt(3241+(rand() % 40)*j,mts[j]);printf("Generated for %d thread.\n", j);}
    	}
}

double rnd_mt(int j)
{
	return (genrand_mt(mts[j])*1.0/4294967295);
}

int main ()
{
	printf("\n");
	int i, n = 100, n_parts, p, id;
	MPI_Init (NULL,NULL);
	MPI_Comm_size ( MPI_COMM_WORLD, &p );
	MPI_Comm_rank ( MPI_COMM_WORLD, &id );
	n_parts = n/p;
	if ( id == 0 )
	{n_parts = n_parts + (n % p);}
	printf("n_parts is %d for thread %d.\n\n", n_parts, id);
	generator(id);
	for (i=0;i<n_parts;i++)
	{
		printf("%lf %d\n", rnd_mt(id), id);
	}
	free(mts[id]);
	MPI_Finalize();
	return 0;
}
