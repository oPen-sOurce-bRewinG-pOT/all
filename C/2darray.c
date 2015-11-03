#include<stdio.h>
#include<stdlib.h>
int **readmatrix(int m, int n)
{
	int **f = (int **)malloc(m * sizeof(int *));
	int i;
	for (i=0;i<m;i++)
	{f[i]=(int *)malloc(n * sizeof(int));}
	int j;
	for (i=0;i<m;i++)
	{
	    for (j=0;j<n;j++)
	    {scanf("%d", &f[i][j]);}
	}
	return f;
}

void freematrix(int rows, double **mat){
    int i=0;
    for(i=0;i<rows;i++)    
        free(mat[i]);
    free(mat);
}

int main()
{
    int r=3, c=4;
    int **arr;
    int count = 0,i,j;
  
    arr=createarr(r, c);
   
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count
  
    for (i = 0; i <  r; i++)
        {for (j = 0; j < c; j++)
            {printf("%d ", arr[i][j]);}
	printf("\n");}
  
    return 0;
}


