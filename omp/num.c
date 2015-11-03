#include <omp.h>
#include <stdio.h>
main()
{
	long int i, j=0, sum=0;
	#pragma omp parallel for private(j) reduction(+:sum)
	for (i=0;i<100000;i++)
	{
		
		for (j=0;j<100000;j++)
		{
			sum+=j;
		}
	}
	printf("%li\n",sum);
}
