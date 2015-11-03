#include<stdio.h>
#include<math.h>
float rnd()
{
	float result;
	float rand_max = pow(2,31)-1;
	result = rand()/rand_max;
	return result;
}
main()
{
	int i, a, n=100000;
	float z, head=0, tail=0, phead, ptail;
	for (i = 0; i < n; i++)
	{
		z = 2*rnd();
		a = floor(z);
		if (a==1)
		{
			head+=1;
		}
		tail = i+1-head;
		phead = head/(i+1);
		ptail = tail/(i+1);
		printf("%d %f %f\n", i, phead, ptail);
	}
} 
