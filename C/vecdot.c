#include<stdio.h>
main()
{
	int i,n;
	float a[1000],b[1000],c=0;
	printf("Enter dimension:\n");
	scanf("%d", &n);
	printf("Enter first vector:\n");
	for (i=0;i<n;i++)
	{
		scanf("%f", &a[i]);
	}
	printf("Enter second vector:\n");
	for (i=0;i<n;i++)
	{
		scanf("%f", &b[i]);
		c+=a[i]*b[i];
	}
	printf("The dot product is %f.\n", c);
}
