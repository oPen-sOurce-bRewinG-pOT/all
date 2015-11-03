//timescale
//#define N 300//366
// Universal constants
#define h 6.626E-34
#define c 3E8
#define k_b 1.38E-23

#define stepsize 2500 //integrator parameter

double f;
int id;

// BB temperature base
#define base_avg 1
#define base_var 1 // +/- 0.6
#define T_avg 1E7
double T_var_small = T_avg*0.01;
double T_var_large = T_avg*0.05;
//double T;

// frequency ranges
#define rmin 3.77E14
#define rmax 5.77E14
#define jmax 2.98E14
#define jmin 2.09E14

#define rdiff 2.00E14
#define jdiff 0.89E14

// julian date
#define date 2457258.5

//powerlaw exponent limits
#define bmin 0.7
#define bmax 1.0 
#define b_avg 0.85
double bvar = b_avg*3.0/100;
double a, b; //power law coeffs
#define Tvarday 19
#define Tvardayran 10
#define bvarday 65
#define bvardayran 6

//limits of frequency for obtaining totflux
const double limlowf = 100e6;    //these limits signify the range where bb() exists for temperature range 10^7 +/- 50%
const double limhighf = 6e18;

//gauss quadrature 8 point, weights
double u[8] = {
-0.960289856,
-0.796666477,
-0.525532410,
-0.183434642,
0.183434642,
0.525532410,
0.796666477,
0.960289856
};

double w[8] = {
0.101228536,
0.222381034,
0.313706646,
0.362683783,
0.362683783,
0.313706646,
0.222381034,
0.101228536
};

