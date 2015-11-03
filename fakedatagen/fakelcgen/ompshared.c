#include <omp.h>
#include <stdio.h>
int id;
main()
{
	int i, a[10];
	#pragma omp parallel
	{id = omp_get_thread_num();
	printf("%d\n", id);}
}
