#include <omp.h>
#include <stdio.h>
main()
{
	int id=omp_get_max_threads();
	printf("%d\n", id);
}
