#include <mpi.h>
#include <stdio.h>

main()
{
int world_size;
int node;
MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Finalize();
    printf("%d %d\n", node, world_size);
}
