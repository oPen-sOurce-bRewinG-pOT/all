#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
	unsigned input=0;
	long int a[33];
	int i;
	long int k=pow(2,32);
	printf("%ld\n", k);
	for (i = 0; i < 33; i++)
	{
		a[i]=0;
	}
	for (input = 0; input < (pow(2,32)-1) ; ++input)
	{
    unsigned
        //input = 0,
        n_bits = 32u,
        *bits = (unsigned*)malloc(sizeof(unsigned) * n_bits),
        bit = 0;

    for(bit = 0; bit < n_bits; ++bit )
        bits[bit] = (input >> bit) & 1;

    /*for(bit = n_bits; bit--;)
        printf("%u", bits[bit]);
    printf("\n");*/
    int sum=0;
    int pos=0;
    for(bit = n_bits; bit--;)
    {
    	pos+=1;
    	if (bits[bit]==0)
	{sum+=1;}
	else
	{sum-=1;}
	if (sum==0)
	{//printf("%d %d\n", sum, pos);
	a[pos]+=1;
	break;}
   }
   
	
    free(bits);
    }
    for (i=2; i<33; i++)
    {
    	if (i%2==0)
    	{
    		long double z=(a[i]*1.0)/k;
    		printf("%d %ld %.32Lf\n%x\n", i, a[i], z);
    	}
    	
    }
}
