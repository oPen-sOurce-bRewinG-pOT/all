#include <stdio.h>
#include <omp.h>
int a[10][2];
main()
{
	int i,j;
	for (i=0;i<10;i++)
	{
		for (j=0;j<2;j++)
		{
			a[i][j]=0;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("Half done!\n");
	for (i=0;i<10;i++)
	{
		#pragma omp parallel //reduction (+:a[i])
		{
			int id=omp_get_thread_num();
			a[i][id]+=id;
			printf("%d %d\n",i, id);
			#pragma omp barrier
		}
	}
	for (i=0;i<10;i++)
        {
                for (j=0;j<2;j++)
                {
                        a[i][j]=0;
                        printf("%d ",a[i][j]);
                }
                printf("\n");
        }
}	
 
