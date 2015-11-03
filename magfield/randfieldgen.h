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

void transmalloc_3d ( double **** in , int nx , int ny , int nz )
{
	*in = ( double *** ) malloc ( nz * sizeof ( double * ) ) ;
	int i ;
	for ( i = 0 ; i < nz ; i++ )
	{
		 ( *in ) [ i ] = ( double ** ) malloc ( ny * sizeof ( double * ) ) ;
		 int j ;
		 for ( j = 0 ; j < nx ; j++ )
		 {
		 	( *in ) [ i ] [ j ] = ( double * ) malloc ( nx * sizeof ( double * ) ) ;
		 }
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


double Psum_calc ( int nx , int ny , int nz , double power )
{
	int i , j , k ;
	double *lxaxis, *lyaxis, *lzaxis ;
	lxaxis = ( double * ) malloc ( nx * sizeof ( double ) ) ;
	lyaxis = ( double * ) malloc ( ny * sizeof ( double ) ) ;
	lzaxis = ( double * ) malloc ( nz * sizeof ( double ) ) ;
	
	fftfreq ( lxaxis , nx , 0.2 ) ; fftfreq ( lyaxis , ny , 0.2 ) ; fftfreq ( lzaxis , nz , 0.2 ) ;
	
	double summ = 0 ;
	for ( k = 0 ; k < nz ; k++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			for ( i = 0 ; i < nx ; i++ )
			{
				double l = sqrt ( lxaxis [ i ] * lxaxis [ i ] + lyaxis [ j ] * lyaxis [ j ] + lzaxis [ k ] * lzaxis [ k ] ) ;
				if ( l != 0 )
				{ summ += pow ( l , power ) ; }
			}
		}
	}
	
	free ( lxaxis ) ; free ( lyaxis ) ; free ( lzaxis ) ;
	
	return summ ;
}

void gaussrand3d ( double *** bxx , double *** byy , double *** bzz , int nx , int ny , int nz , double var , double power )
{
	fftw_complex * ax , * ay , * az , * axx, * ayy , * azz , * bx , * by , * bz , * output ;
	ax = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	ay = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	az = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	axx = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	ayy = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	azz = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	
	output = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	//printf("fftcompmalloc\n") ;
	double *lxaxis, *lyaxis, *lzaxis ;
	lxaxis = ( double * ) malloc ( nx * sizeof ( double ) ) ;
	lyaxis = ( double * ) malloc ( ny * sizeof ( double ) ) ;
	lzaxis = ( double * ) malloc ( nz * sizeof ( double ) ) ;
	
	fftfreq ( lxaxis , nx , 0.2 ) ; fftfreq ( lyaxis , ny , 0.2 ) ; fftfreq ( lzaxis , nz , 0.2 ) ; //printf("fftfreq\n") ;
	
	double Psum = Psum_calc ( nx , ny , nz , power ) ;// printf( "psum = %lf\n" , Psum ) ;
	
	int x , y , z , i , j , k ;
	
	double u , v ;
	
	/// GENERATING AX
	
	srand ( time ( NULL ) ) ;
	for ( z = 0 ; z < nz ; z++ )
	{
		for ( y = 0 ; y < ny ; y++ )
		{
			for ( x = 0 ; x < nx ; x++ )
			{
			
				double lx = lxaxis [ x ] ;
				double ly = lyaxis [ y ] ;
				double lz = lzaxis [ z ] ;
				
				double l = sqrt ( lx * lx + ly * ly + lz * lz ) ;
			
				double sigma = sqrt ( powspec ( l , var , nx * ny * nz , Psum , power ) ) ;
			
				double s = 1.1 ;
			
				while ( s > 1 )
				{
					u = -1 + rand ( ) * 2.0 / RAND_MAX ;
					v = -1 + rand ( ) * 2.0 / RAND_MAX ;
				
					s = u * u + v * v ;
				}
			
				double fac = sqrt ( - 2.0 * log ( s ) / s ) ;
			
				double zr = u * fac * sigma ;
				double zc = v * fac * sigma ;
			
				if ( ( x == 0 ) && ( y == 0 ) && ( z == 0 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = 0 ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ; 
				}
			
				else if ( ( x == 0 ) && ( y == ny / 2 ) && ( z == 0 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == 0 ) && ( z == 0 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == ny / 2 ) && ( z == 0 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == 0 ) && ( y == ny / 2 ) && ( z == nz / 2 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == 0 ) && ( z == nz / 2 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == ny / 2 ) && ( z == nz / 2 ) )
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else
				{
					ax [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ax [ z * nz * ny + y * ny + x ] [ 1 ] = zc ;
				}
				
				int y2 = ny - y ;
				int x2 = nx - x ;
				int z2 = nz - z ;
				//printf ( "%d %d\n%d %d\n" , x, y, x2, y2) ;
				
				if ( ( x2 < nx ) && ( y2 < ny ) && ( z2 < nz ) )
				{
					ax [ z2 * nz * ny + y2 * ny + x2 ] [ 0 ] = zr ;
					ax [ z2 * nz * ny + y2 * ny + x2 ] [ 1 ] = - zc ;
				}
				if ( x >= nx / 2 )
				{ break ; }
			}	
			if ( y >= ny / 2 )
			{ break ; }
		}
		if ( z >= nz / 2 )
		{ break ; }
	}
	
	/// GENERATING AY
	
	srand ( time ( NULL ) ) ;
	for ( z = 0 ; z < nz ; z++ )
	{
		for ( y = 0 ; y < ny ; y++ )
		{
			for ( x = 0 ; x < nx ; x++ )
			{
			
				double lx = lxaxis [ x ] ;
				double ly = lyaxis [ y ] ;
				double lz = lzaxis [ z ] ;
				
				double l = sqrt ( lx * lx + ly * ly + lz * lz ) ;
			
				double sigma = sqrt ( powspec ( l , var , nx * ny * nz , Psum , power ) ) ;
			
				double s = 1.1 ;
			
				while ( s > 1 )
				{
					u = -1 + rand ( ) * 2.0 / RAND_MAX ;
					v = -1 + rand ( ) * 2.0 / RAND_MAX ;
				
					s = u * u + v * v ;
				}
			
				double fac = sqrt ( - 2.0 * log ( s ) / s ) ;
			
				double zr = u * fac * sigma ;
				double zc = v * fac * sigma ;
			
				if ( ( x == 0 ) && ( y == 0 ) && ( z == 0 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = 0 ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ; 
				}
			
				else if ( ( x == 0 ) && ( y == ny / 2 ) && ( z == 0 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == 0 ) && ( z == 0 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == ny / 2 ) && ( z == 0 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == 0 ) && ( y == ny / 2 ) && ( z == nz / 2 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == 0 ) && ( z == nz / 2 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == ny / 2 ) && ( z == nz / 2 ) )
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else
				{
					ay [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					ay [ z * nz * ny + y * ny + x ] [ 1 ] = zc ;
				}
				
				int y2 = ny - y ;
				int x2 = nx - x ;
				int z2 = nz - z ;
				//printf ( "%d %d\n%d %d\n" , x, y, x2, y2) ;
				
				if ( ( x2 < nx ) && ( y2 < ny ) && ( z2 < nz ) )
				{
					ay [ z2 * nz * ny + y2 * ny + x2 ] [ 0 ] = zr ;
					ay [ z2 * nz * ny + y2 * ny + x2 ] [ 1 ] = - zc ;
				}
				if ( x >= nx / 2 )
				{ break ; }
			}	
			if ( y >= ny / 2 )
			{ break ; }
		}
		if ( z >= nz / 2 )
		{ break ; }
	}
	
	///GENERATING AZ
	
	srand ( time ( NULL ) ) ;
	for ( z = 0 ; z < nz ; z++ )
	{
		for ( y = 0 ; y < ny ; y++ )
		{
			for ( x = 0 ; x < nx ; x++ )
			{
			
				double lx = lxaxis [ x ] ;
				double ly = lyaxis [ y ] ;
				double lz = lzaxis [ z ] ;
				
				double l = sqrt ( lx * lx + ly * ly + lz * lz ) ;
			
				double sigma = sqrt ( powspec ( l , var , nx * ny * nz , Psum , power ) ) ;
			
				double s = 1.1 ;
			
				while ( s > 1 )
				{
					u = -1 + rand ( ) * 2.0 / RAND_MAX ;
					v = -1 + rand ( ) * 2.0 / RAND_MAX ;
				
					s = u * u + v * v ;
				}
			
				double fac = sqrt ( - 2.0 * log ( s ) / s ) ;
			
				double zr = u * fac * sigma ;
				double zc = v * fac * sigma ;
			
				if ( ( x == 0 ) && ( y == 0 ) && ( z == 0 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = 0 ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ; 
				}
			
				else if ( ( x == 0 ) && ( y == ny / 2 ) && ( z == 0 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == 0 ) && ( z == 0 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == ny / 2 ) && ( z == 0 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == 0 ) && ( y == ny / 2 ) && ( z == nz / 2 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == 0 ) && ( z == nz / 2 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else if ( ( x == nx / 2 ) && ( y == ny / 2 ) && ( z == nz / 2 ) )
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = 0 ;
				}
				
				else
				{
					az [ z * nz * ny + y * ny + x ] [ 0 ] = zr ;
					az [ z * nz * ny + y * ny + x ] [ 1 ] = zc ;
				}
				
				int y2 = ny - y ;
				int x2 = nx - x ;
				int z2 = nz - z ;
				//printf ( "%d %d\n%d %d\n" , x, y, x2, y2) ;
				
				if ( ( x2 < nx ) && ( y2 < ny ) && ( z2 < nz ) )
				{
					az [ z2 * nz * ny + y2 * ny + x2 ] [ 0 ] = zr ;
					az [ z2 * nz * ny + y2 * ny + x2 ] [ 1 ] = - zc ;
				}
				if ( x >= nx / 2 )
				{ break ; }
			}	
			if ( y >= ny / 2 )
			{ break ; }
		}
		if ( z >= nz / 2 )
		{ break ; }
	}
	
	/// Cross product with k :
	
	for ( z = 0 ; z < nz ; z++ )
	{
		for ( y = 0 ; y < ny ; y++ )
		{
			for ( x = 0 ; x < nx ; x++ )
			{
				double lx = lxaxis [ x ] ;
				double ly = lyaxis [ y ] ;
				double lz = lzaxis [ z ] ;
				axx [ z * nz * ny + y *  ny + x ] [ 1 ] = ly * az [ z * nz * ny + y *  ny + x ] [ 0 ] - lz * ay [ z * nz * ny + y *  ny + x ] [ 0 ] ;
				axx [ z * nz * ny + y *  ny + x ] [ 0 ] = - ly * az [ z * nz * ny + y *  ny + x ] [ 1 ] + lz * ay [ z * nz * ny + y *  ny + x ] [ 1 ] ;
				ayy [ z * nz * ny + y *  ny + x ] [ 1 ] = lx * az [ z * nz * ny + y *  ny + x ] [ 0 ] - lz * ax [ z * nz * ny + y *  ny + x ] [ 0 ] ;
				azz [ z * nz * ny + y *  ny + x ] [ 1 ] = lx * ay [ z * nz * ny + y *  ny + x ] [ 0 ] - ly * ax [ z * nz * ny + y *  ny + x ] [ 0 ] ;
				ayy [ z * nz * ny + y *  ny + x ] [ 0 ] = - lx * az [ z * nz * ny + y *  ny + x ] [ 1 ] + lz * ax [ z * nz * ny + y *  ny + x ] [ 1 ] ;
				azz [ z * nz * ny + y *  ny + x ] [ 0 ] = - lx * ay [ z * nz * ny + y *  ny + x ] [ 1 ] + ly * ax [ z * nz * ny + y *  ny + x ] [ 1 ] ;
			}
		}
	}
	
	fftw_free ( ax ) ; fftw_free ( ay ) ; fftw_free ( az ) ; free ( lxaxis ) ; free ( lyaxis ) ; free ( lzaxis ) ; 
	
	bx = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	by = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	bz = ( fftw_complex * ) fftw_malloc ( nx * ny * nz * sizeof ( fftw_complex ) ) ;
	
	//printf("ax_gen\n") ;
	//printf ( "planning...\n" ) ;
	fftw_plan plan = fftw_plan_dft_3d ( nx , ny , nz , axx , bx , FFTW_BACKWARD, FFTW_ESTIMATE ) ; //printf ( "planning done\n") ;
	fftw_execute ( plan ) ; //printf("fft\n") ;
	fftw_destroy_plan ( plan ) ;
	fftw_free ( axx ) ;
	
	plan = fftw_plan_dft_3d ( nx , ny , nz , ayy , by , FFTW_BACKWARD, FFTW_ESTIMATE ) ; //printf ( "planning done\n") ;
	fftw_execute ( plan ) ; //printf("fft\n") ;
	fftw_destroy_plan ( plan ) ;
	fftw_free ( ayy ) ;
	
	plan = fftw_plan_dft_3d ( nx , ny , nz , azz , bz , FFTW_BACKWARD, FFTW_ESTIMATE ) ; //printf ( "planning done\n") ;
	fftw_execute ( plan ) ; //printf("fft\n") ;
	fftw_destroy_plan ( plan ) ;
	fftw_free ( azz ) ;
	
	for ( i = 0 ; i < nx * ny * nz ; i++ )
	{
		bx [ i ] [ 0 ] /= ( nx * ny * nz ) ;
		bx [ i ] [ 1 ] /= ( nx * ny * nz ) ;
		
		by [ i ] [ 0 ] /= ( nx * ny * nz ) ;
		by [ i ] [ 1 ] /= ( nx * ny * nz ) ;
		
		bz [ i ] [ 0 ] /= ( nx * ny * nz ) ;
		bz [ i ] [ 1 ] /= ( nx * ny * nz ) ;
	}
	//printf("normalization\n") ;
	/* double *** bxx ;
	bxx = ( double *** ) malloc ( nz * sizeof ( double ** ) ) ;
	for ( i = 0 ; i < ny ; i++ )
	{
		bxx [ i ] = ( double ** ) malloc ( ny * sizeof ( double * ) ) ;
		for ( j = 0 ; j < nx ; j++ )
		{
			bxx [ i ] [ j ] = ( double * ) malloc ( nx * sizeof ( double ) ) ;
		}
	} */
	//printf("midmalloc\n") ;
	for ( k = 0 ; k < nz ; k++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			for ( i = 0 ; i < nx ; i++ )
			{
				bxx [ k ] [ j ] [ i ] = bx [ k * nz * ny + j * ny + i ] [ 0 ] ;
			}
		}
	}
	
	fftw_free ( bx ) ;
	
	/* double *** byy ;
	byy = ( double *** ) malloc ( nz * sizeof ( double ** ) ) ;
	for ( i = 0 ; i < ny ; i++ )
	{
		byy [ i ] = ( double ** ) malloc ( ny * sizeof ( double * ) ) ;
		for ( j = 0 ; j < nx ; j++ )
		{
			byy [ i ] [ j ] = ( double * ) malloc ( nx * sizeof ( double ) ) ;
		}
	} */
	//printf("midmalloc\n") ;
	for ( k = 0 ; k < nz ; k++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			for ( i = 0 ; i < nx ; i++ )
			{
				byy [ k ] [ j ] [ i ] = by [ k * nz * ny + j * ny + i ] [ 0 ] ;
			}
		}
	}
	
	fftw_free ( by ) ;
	
	/* double *** bzz ;
	bzz = ( double *** ) malloc ( nz * sizeof ( double ** ) ) ;
	for ( i = 0 ; i < ny ; i++ )
	{
		bzz [ i ] = ( double ** ) malloc ( ny * sizeof ( double * ) ) ;
		for ( j = 0 ; j < nx ; j++ )
		{
			bzz [ i ] [ j ] = ( double * ) malloc ( nx * sizeof ( double ) ) ;
		}
	} */
	//printf("midmalloc\n") ;
	for ( k = 0 ; k < nz ; k++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			for ( i = 0 ; i < nx ; i++ )
			{
				bzz [ k ] [ j ] [ i ] = bz [ k * nz * ny + j * ny + i ] [ 0 ] ;
			}
		}
	}
	
	fftw_free ( bz ) ;
	
/*	for ( i = 0 ; i < nx ; i++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			out [ i ] [ ny - 1 - j ] = mid [ i ] [ j ] ;
		}
	}
	for ( j = 0 ; j < ny ; j++ )
	{
		for ( i = 0 ; i < nx ; i++ )
		{
			out [ nx - 1 - i ] [ j ] = mid [ i ] [ j ] ;
		}
	}*/
	
	//printf("fftshift\n") ;
	
}

void plot_to_file ( double *** bxx , double *** byy , double *** bzz , int nx , int ny , int nz , char * fname )
{
	FILE * fp ; fp = fopen ( fname , "w+" ) ;
	int i , j , k ;
	for ( i = 0 ; i < nx ; i++ )
	{
		for ( j = 0 ; j < ny ; j++ )
		{
			for ( k = 0 ; k < nz ; k++ )
			{
				fprintf ( fp , "%d %d %d %lf %lf %lf\n" , i , j , k , bxx [ k ] [ j ] [ i ] , byy [ k ] [ j ] [ i ] , bzz [ k ] [ j ] [ i ] ) ;
			}
		}
		if ( i > 0 )
			break ;
	}
	fclose ( fp ) ;
}
