#include <mpi.h>
#include <stdio.h>
#define N 12
int main()
{
	int id, p, array[N];
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Status status;
	int k = id;
	while (k<N)
	{
		array[k]=k*(1+id);
		printf("%d %d %d \n",id,k,array[k]);
		//MPI_Bcast(&array[k],1,MPI_INT,id,MPI_COMM_WORLD);
		if ( id != 0 )
		{
			MPI_Send(&k,1,MPI_INT,0,1,MPI_COMM_WORLD);
			MPI_Send(&array[k],1,MPI_INT,0,0,MPI_COMM_WORLD);
			printf("Send success of %d from %d process!\n", k, id);
		}
		else if ( id == 0 )
		{
			
			int pid;
			for (pid=1;pid<p;pid++)
			{
				int recv;
				MPI_Recv(&recv,1,MPI_INT,pid,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				MPI_Recv(&array[recv],1,MPI_INT,pid,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				printf("Received %d success!\n", recv);
			}
			
		}
		k += p ;
	}
	
	//MPI_Bcast(array, 10, MPI_INT, 1, MPI_COMM_WORLD);
	MPI_Finalize();
	if ( id == 0 )
	{
		for (k=0;k<N;k++)
		{
			printf("%d\n", array[k]);
		}
	}
	return 0;
}
