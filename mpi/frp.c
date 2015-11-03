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

int rnd_mt(int j)
{
	return (genrand_mt(mts[j]) % 2);
}

int main ()
{
	printf("\n");
	int i, n = 100000, n_parts, p, id, frp = 0, frp_parts; double wtime;
	long int ssl = 10000000000, ss;
	MPI_Init (NULL,NULL);
	MPI_Comm_size ( MPI_COMM_WORLD, &p );
	MPI_Comm_rank ( MPI_COMM_WORLD, &id );
	n_parts = n/p;
	if ( id == 0 )
	{n_parts = n_parts + (n % p); wtime = MPI_Wtime();}
	printf("n_parts is %d for thread %d.\n\n", n_parts, id);
	generator(id);
	for ( ss = ssl ; ss <= ssl ; ss *= 10 )
	{
		frp = 0;
		MPI_Bcast ( &ss , 1, MPI_INT, 0, MPI_COMM_WORLD );
		frp_parts = 0;
		for (i=0;i<n_parts;i++)
		{
			int x = 0;
			int j;
			for ( j = 0 ; j < ss ; j++ )
			{
				if ( rnd_mt(id) == 0 )
				{
					x += 1;
				}
				else
				{
					x -= 1;
				}
				if ( x == 0 )
				{
					frp_parts += 1;
					break;
				}
			}
		}
		MPI_Reduce ( &frp_parts, &frp, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD );
		if ( id == 0 )
		{printf("%d of %d made their return successfully for steps %li.\nSo the probability of first return is %lf for steps %li.\n", frp, n, ss, (frp*1.0/n), ss);}
		//ss *= 10 ;
	}
	if ( id == 0 )
	{
		printf("\n\n\nThe whole operation took %lfs to complete.\n", -wtime + MPI_Wtime());
	}
	free(mts[id]);
	MPI_Finalize();
	return 0;
}
