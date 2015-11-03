#include <stdio.h>
#include <dc.h>
#include <stdlib.h>

#include <omp.h>
#define N_THR 2
mt_struct *mts[N_THR];
void generator(int k)
{
	int j;
	for (j=0;j<k;j++)
    	{
    	/* This trys to find a small Mersenne Twister with period 2^521-1. */
    		mts[j] = get_mt_parameter_id_st(32,521,200*j,4172);
		if (mts[j] == NULL){printf("Error on %d thread.\n", j);}
    		else {sgenrand_mt(3241+40*j,mts[j]);}
    	}
}

int rnd( int id )
{
    return (genrand_mt(mts[id]) % 4) ;
}

int main()
{
    printf ( " # Step Size FRP \n" ) ;
    generator ( N_THR ) ;
    int i, ensemble = 1000000, ssl = 10000, ss, tot ;
    for ( ss = 10 ; ss <= ssl ; ss *= 10 )
    {
        tot = 0 ;
        #pragma omp parallel for reduction(+:tot)
        for ( i = 0 ; i < ensemble ; i++ )
        {
            int x = 0 , y = 0 , id , j ;
            id = omp_get_thread_num ( ) ;
            for ( j = 0 ; j < ss ; j++ )
            {
                int p = rnd(id) ;
                if ( p == 0 )
                { x++ ; }
                else if ( p == 1 )
                { y-- ; }
                else if ( p == 2 )
                { y++ ; }
                else
                { x-- ; }
                
                if ( ( x == 0 ) && ( y == 0 ) )
                { tot++ ; break ; }
            }    
        }
        printf ( " %d  %lf \n", ss , tot * 1.0 / ensemble ) ;
    }
    return 0 ; 
}
