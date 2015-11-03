#include <omp.h>
#include <stdio.h>
main()
{
	#pragma omp parallel num_threads(2)
	{
		int id=omp_get_thread_num();
		//int id=0;
		printf("Hello(%d) ",id);
		printf("world(%d)!\n",id);
	}
}
