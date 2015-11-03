#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_dht.h>
#include <gsl/gsl_sf_bessel.h>
#include <math.h>
#include "dht.h"

void compute_dht ( int size , double * in , double * out , int order , double rmax )
{
	int i ;
	
	gsl_dht * plan = gsl_dht_new ( size , order , rmax ) ;
	
	gsl_dht_apply ( plan , in , out ) ;
	
	gsl_dht_free ( plan ) ;
	
	double norm = gsl_sf_bessel_Jn ( order , rmax ) / ( rmax * rmax ) ;
	
	for ( i = 0 ; i < size ; i++ )
	{
		out [ i ] *= norm ;
	}
	
}
