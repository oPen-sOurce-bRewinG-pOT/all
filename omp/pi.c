#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
static long n_s=1000000000;
double step;
main()
{	
	int i; double x, pi, sum=0;
	step=1.0/(double)n_s;
	{
	#pragma omp parallel for reduction(+:sum)
	
		for (i=0;i<n_s;i++)
		{
			x=(i+1.0)*step;
			sum+=4.0/(1.0+x*x);

		}
	
		pi=step*sum;
		int id;
	//	#pragma omp parallel
		/*{*/id=omp_get_thread_num();
		printf("Pi = %lf from thread %d.\n", pi, id);
	}//}
}
