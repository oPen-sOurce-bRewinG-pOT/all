#ifndef gauss_fn_h
double powspec(double L, double variance, double Npix, double Psum, double power) ;
void fftfreq ( double * in , int n , double d ) ;
void transmalloc_2d ( double *** in , int row , int column );
void transpose_2d ( double ** out , double ** in , int row , int column );
double Psum_calc ( int nx , int ny , double power );
void gaussrand2d ( double * out , int nx , int ny , double var , double power );
#endif
