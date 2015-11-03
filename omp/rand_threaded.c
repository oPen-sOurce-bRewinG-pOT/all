#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int rnd(int n)
{
	int id, i, sum=0;
	#pragma omp parallel num_threads(2*omp_get_max_threads()) reduction(+:sum)
	{
		id=omp_get_thread_num();
		srand(id);
		//#pragma omp for reduction (+:sum)
		for (i=0;i<n;i++)
		{
		//	printf("%d %f\n", id, (rand()*1.0/RAND_MAX));
			float x=rand()*1.0/RAND_MAX;
			sum+=1;
			//if (sum==(n-1))
			//{break;}
		}
	}
	return sum;
}
main()
{
	int i;
	for (i=0;i<100;i++){
	int p=rnd(10);
	if (p!=40)
	{printf("%d\n",p);}}

}
