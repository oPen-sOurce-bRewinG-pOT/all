#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4

void pr(void)
{
	printf("Caller id = %d.\n", omp_get_thread_num());
}
main()
{
	int i, sum=0;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel for reduction(+:sum)
	for (i=0;i<100;i++)
	{
		pr();
		sum+=1;
	}
	printf("\n\nThe number of times run = %d.\n", sum);
}
