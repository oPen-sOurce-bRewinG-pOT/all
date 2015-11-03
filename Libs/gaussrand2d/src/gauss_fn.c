#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>
#include <time.h>
#include "gauss_fn.h"

double powspec(double L, double variance, double Npix, double Psum, double power) //Power Spectrum
{
	if (L <= 0)
    		return 0.0 ;
	else
	{
		double A = variance*(Npix*Npix)/(2.0*Psum) ;
		return ( A * pow(L,power) ) ;
	}	
		
}

void fftfreq ( double * in , int n , double d )
{
	int i ;
	if ( n % 2 == 1 )
	{
		for ( i = 0 ; i <= n / 2 ; i++ )
		{
			in [ i ] = i / ( d * n );
		}
		int j = 1 ;
		for ( ; i < n ; i++ )
		{
			in [ i ] = - in [ i - j ] ;
			j += 2 ;
		}
	}
	else
	{
		for ( i = 0 ; i < n / 2 ; i++ )
		{
			in [ i ] = i / ( d * n ) ;
		}
		int j = 0 ;
		for (  ; i < n ; i++ )
		{
			in [ i ] = ( j - i ) / ( d * n ) ;
			j += 2 ;
		}
	}
}

void transmalloc_2d ( double *** in , int row , int column )
{
	*in = ( double ** ) malloc ( column * sizeof ( double * ) ) ;
	int i ;
	for ( i = 0 ; i < column ; i++ )
	{
		 ( *in ) [ i ] = ( double * ) malloc ( row * sizeof ( double ) ) ;
	}
}

void transpose_2d ( double ** out , double ** in , int row , int column )
{
	int i , j ;
	for ( i = 0 ; i < row ; i++ )
	{
		for ( j = 0 ; j < column ; j++ )
		{
			out [ j ] [ i ] = in [ i ] [ j ] ;
		}
	}
}


double Psum_calc ( int nx , int ny , double power )
{
	int i , j ;
	double *lxaxis, *lyaxis ;
	lxaxis = ( double * ) malloc ( nx * sizeof ( double ) ) ;
	lyaxis = ( double * ) malloc ( ny * sizeof ( double ) ) ;
	
	fftfreq ( lxaxis , nx , 0.2 ) ; fftfreq ( lyaxis , ny , 0.2 ) ;
	
	double **lx , **ly, **ly_t , **l ;
	lx = ( double ** ) malloc ( nx * sizeof ( double * ) ) ;
	ly_t = ( double ** ) malloc ( ny * sizeof ( double * ) ) ;
	
	for ( i = 0 ; i < nx ; i++ )
	{
		lx [ i ] = lxaxis ;
		ly_t [ i ] = lyaxis ; //not transposed
	}
	


	
	transmalloc_2d ( &ly , ny , ny ) ;
	transpose_2d ( ly , ly_t , ny , ny ) ; //transposing ly_t to ly
	
	transmalloc_2d ( &l , nx , nx ) ;
	
	double summ = 0 ;
	for ( i = 0 ; i < nx ; i++ )
	{
		for ( j = 0 ; j < nx ; j++ )
		{
			l [ i ] [ j ] = sqrt ( lx [ i ] [ j ] * lx [ i ] [ j ] + ly [ i ] [ j ] * ly [ i ] [ j ] ) ;
			if ( l [ i ] [ j ] != 0.0 )
			{ summ += pow ( l [ i ] [ j ] , power ) ; }
		}
	}
	
	free ( lxaxis ) ; free ( lyaxis ) ; free ( lx ) ; free ( ly ) ; free ( ly_t ) ; free ( l ) ;
	
	return summ ;
}

void gaussrand2d ( double * out , int nx , int ny , double var , double power )
{
	fftw_complex * trial , * output ;
	trial = ( fftw_complex * ) fftw_malloc ( nx * ny * sizeof ( fftw_complex ) ) ;
	output = ( fftw_complex * ) fftw_malloc ( nx * ny * sizeof ( fftw_complex ) ) ;
	//printf("fftcompmalloc\n") ;
	double *lxaxis, *lyaxis ;
	lxaxis = ( double * ) malloc ( nx * sizeof ( double ) ) ;
	lyaxis = ( double * ) malloc ( ny * sizeof ( double ) ) ;
	
	fftfreq ( lxaxis , nx , 0.2 ) ; fftfreq ( lyaxis , ny , 0.2 ) ; //printf("fftfreq\n") ;
	
	double Psum = Psum_calc ( nx , ny , power ) ;// printf( "psum = %lf\n" , Psum ) ;
	
	int x , y , i , j ;
	
	double u , v ;
	
	srand ( time ( NULL ) ) ;
	
	for ( y = 0 ; y < ny ; y++ )
	{
		for ( x = 0 ; x < nx ; x++ )
		{
			
			double lx = lxaxis [ x ] ;
			double ly = lyaxis [ y ] ;
			
			double l = sqrt ( lx * lx + ly * ly ) ;
			
			double sigma = sqrt ( powspec ( l , var , nx * ny , Psum , power ) ) ;
			
			double s = 1.1 ;
			
			while ( s > 1 )
			{
				u = -1 + rand ( ) * 2.0 / RAND_MAX ;
				v = -1 + rand ( ) * 2.0 / RAND_MAX ;
				
				s = u * u + v * v ;
			}
			
			double fac = sqrt ( - 2.0 * log ( s ) / s ) ;
			
			double z1 = u * fac * sigma ;
			double z2 = v * fac * sigma ;
			
			if ( ( x == 0 ) && ( y == 0 ) )
			{
				trial [ y * ny + x ] [ 0 ] = 0 ;
				trial [ y * ny + x ] [ 1 ] = 0 ; 
			}
			
			else if ( ( x == 0 ) && ( y == ny / 2 ) )
			{
				trial [ y * ny + x ] [ 0 ] = z1 ;
				trial [ y * ny + x ] [ 1 ] = 0 ;
			}
			
			else if ( ( x == nx / 2 ) && ( y == 0 ) )
			{
				trial [ y * ny + x ] [ 0 ] = z1 ;
				trial [ y * ny + x ] [ 1 ] = 0 ;
			}
			
			else if ( ( x == nx / 2 ) && ( y == ny / 2 ) )
			{
				trial [ y * ny + x ] [ 0 ] = z1 ;
				trial [ y * ny + x ] [ 1 ] = 0 ;
			}
			
			else
			{
				trial [ y * ny + x ] [ 0 ] = z1 ;
				trial [ y * ny + x ] [ 1 ] = z2 ;
			}
			
			int y2 = ny - y ;
			int x2 = nx - x ;
			//printf ( "%d %d\n%d %d\n" , x, y, x2, y2) ;
			
			if ( ( x2 < nx ) && ( y2 < ny ) )
			{
				trial [ y2 * ny + x2 ] [ 0 ] = z1 ;
				trial [ y2 * ny + x2 ] [ 1 ] = - z2 ;
			}
			if ( x >= nx / 2 )
			{ break ; }
		}
		if ( y >= ny / 2 )
		{ break ; }
	}
	//printf("trial_gen\n") ;
	//printf ( "planning...\n" ) ;
	fftw_plan plan = fftw_plan_dft_2d ( nx , ny , trial , output , FFTW_BACKWARD, FFTW_ESTIMATE ) ; //printf ( "planning done\n") ;
	fftw_execute ( plan ) ; //printf("fft\n") ;
	fftw_free ( trial ) ; fftw_destroy_plan ( plan ) ;  free ( lxaxis ) ; free ( lyaxis ) ;
	for ( i = 0 ; i < nx * ny ; i++ )
	{
		output [ i ] [ 0 ] /= ( nx * ny ) ;
		output [ i ] [ 1 ] /= ( nx * ny ) ;
	}
	//printf("normalization\n") ;
	double ** mid ;
	mid = ( double ** ) malloc ( nx * sizeof ( double * ) ) ;
	for ( i = 0 ; i < nx ; i++ )
	{
		mid [ i ] = ( double * ) malloc ( ny * sizeof ( double ) ) ;
	}
	//printf("midmalloc\n") ;
	for ( i = 0 ; i < nx ; i++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			mid [ i ] [ j ] = output [ i * ny + j ] [ 0 ] ;
		}
	}
	
	fftw_free ( output ) ;
	
	for ( i = 0 ; i < nx ; i++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			out [ i * nx + ny - 1 - j ] = mid [ i ] [ j ] ;
		}
	}
	for ( j = 0 ; j < ny ; j++ )
	{
		for ( i = 0 ; i < nx ; i++ )
		{
			out [ ( nx - 1 - i ) * nx +  j ] = mid [ i ] [ j ] ;
		}
	}
	
	//printf("fftshift\n") ;
	 free ( mid ) ;	
	
}

/*#include <time.h>
int main( int argc , char *argv [ ] )
{
	if ( argc != 6 )
	{
		printf ( "Usage: < Executable name > < Nx > < Ny > < Variance > < Power > < Output File Name >\n" ) ;
		return 0 ;
	}
	int nx = atoi ( argv [ 1 ] ) ;
	int ny = atoi ( argv [ 2 ] ) ;
	double var = atof ( argv [ 3 ] ) ;
	double power = atof ( argv [ 4 ] ) ;
	double * arr , rtime ; clock_t tick , tock ;
	arr = ( double * ) malloc ( nx * ny * sizeof ( double ) ) ;
	tick = clock ( ) ;
	gaussrand2d ( arr , nx , ny , var , power ) ;
	tock = clock ( ) ;
	printf ( "Time taken to generate %d x %d field = %lf seconds.\n" , nx , ny , ( double ) ( tock - tick ) / CLOCKS_PER_SEC ) ;
	FILE *fp ; fp = fopen ( argv [ 5 ] , "w+" ) ;
	int i , j ;
	for ( i = 0 ; i < ny ; i++ )
	{
		for ( j = 0 ; j < nx ; j++ )
			fprintf ( fp , "%lf " , arr [ i * ny + j ] ) ;
		fprintf ( fp , "\n" ) ;
	}
}*/
