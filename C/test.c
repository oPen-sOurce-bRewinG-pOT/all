#include <stdio.h>
#include <omp.h>
#include <mpi.h>
#define dim 10000
int main()
{	
	//#pragma omp parallel
	{MPI_Init(NULL,NULL);
	int id;
	double wtime;
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	if (id == 0 )
	{wtime=MPI_Wtime();}
	MPI_Bcast ( &wtime, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
	int i;
	int a[dim];
	for(i=0;i<10000;i++)
	{
		a[i]=i;
		//printf("%d\n", a[i]);
	}
	wtime = MPI_Wtime() - wtime;
	printf("%f from %d.\n", (wtime), id);
	printf("Hello world!\n\b\a");}
	MPI_Finalize();
	return 0;
}
