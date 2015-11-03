#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>


#include "randfieldgen.h"


#define xdim 100
#define ydim 100
#define zdim 100

#include <time.h>
int main( int argc , char *argv [ ] )
{
/*	if ( argc != 6 )
	{
		printf ( "Usage: < Executable name > < Nx > < Ny > < Variance > < Power > < Output File Name >\n" ) ;
		return 0 ;
	}
	int nx = atoi ( argv [ 1 ] ) ;
	int ny = atoi ( argv [ 2 ] ) ;
	double var = atof ( argv [ 3 ] ) ;
	double power = atof ( argv [ 4 ] ) ; */
	double *** bxx , *** byy , *** bzz , rtime ; clock_t tick , tock ;
	transmalloc_3d ( &bxx , xdim , ydim , zdim ) ;
	transmalloc_3d ( &bzz , xdim , ydim , zdim ) ;
	transmalloc_3d ( &byy , xdim , ydim , zdim ) ;
	tick = clock ( ) ;
	gaussrand3d ( bxx , byy , bzz , xdim , ydim , zdim , 1 , -10 ) ;
	tock = clock ( ) ;
	printf ( "Time taken to generate %d x %d x %d field = %lf seconds.\n" , xdim , ydim , zdim , ( double ) ( tock - tick ) / CLOCKS_PER_SEC ) ;
	printf ( "Printing to file ... \n" ) ;
	tick = clock ( ) ;
	plot_to_file ( bxx , byy , bzz , xdim , ydim , zdim , "plot.dat" ) ;
	tock = clock ( ) ;
	printf ( "Time taken to plot %d x %d x %d field = %lf seconds.\n" , xdim , ydim , zdim , ( double ) ( tock - tick ) / CLOCKS_PER_SEC ) ;
	free ( bxx ) ; free ( byy ) ; free ( bzz ) ;
}
