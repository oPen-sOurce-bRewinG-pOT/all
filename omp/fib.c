#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
main()
{
	double sum, sum0=0, sum1=1;int i;
	#pragma omp parallel num_threads(2) //shared(sum0,sum1)
	{
		for (i=0;i<100;i++)
		{
			int id=omp_get_thread_num();
			sum=sum0+sum1;
			sum0=sum1;
			sum1=sum;
			printf("%d %.0lf\n",id,sum1);
		}
	}
}
