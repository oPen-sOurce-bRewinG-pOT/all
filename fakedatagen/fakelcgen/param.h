//timescale
//#define N 300//366
// Universal constants
#define h 6.626E-34
#define c 3E8
#define k_b 1.38E-23

#define stepsize 2500 //integrator parameter

//bb variation parameters (day)
int bb_base;
int bb_var;

//pl variation parameters (day)
int pl_base;
int pl_var;

double f;

// BB temperature base
#define T_avg 1E7
double T_var_small = T_avg*0.01;
double T_var_large = T_avg*0.05;
//double T;

// frequency ranges
#define rmin 3.77E14
#define rmax 5.77E14
#define jmax 2.98E14
#define jmin 2.09E14

// julian date
#define date 2457258.5

//powerlaw exponent limits
#define bmin 0.7
#define bmax 1.0 
#define b_avg 0.85
double bvar = b_avg*3.0/100;
double a, b; //power law coeffs

//limits of frequency for obtaining totflux
const double limlowf = 100e6;    //these limits signify the range where bb() exists for temperature range 10^7 +/- 50%
const double limhighf = 6e18;

//gauss quadrature 8 point, weights

#define quadrature 8

double u[quadrature] = {
-0.960289856,
-0.796666477,
-0.525532410,
-0.183434642,
0.183434642,
0.525532410,
0.796666477,
0.960289856
};

double w[quadrature] = {
0.101228536,
0.222381034,
0.313706646,
0.362683783,
0.362683783,
0.313706646,
0.222381034,
0.101228536
};

/*sdss type sampler*/
int sdss[78]={119, 415, 469, 532, 766, 795, 802, 822, 829,1153, 1154, 1179, 1207, 1866, 1871, 1878, 1882, 1884, 1887, 1890, 1901, 1907, 1908, 1909, 1912, 1913, 1914, 1915, 1918, 1920, 1923, 1925, 1931, 1940, 1941, 1944, 1949, 2219, 2238, 2240, 2252, 2253, 2254, 2256, 2264, 2268,2272,2274, 2279, 2281, 2284, 2285, 2291, 2293, 2294, 2297, 2300, 2303, 2305, 2306, 2312, 2601, 2606, 2620, 2626, 2629, 2631, 2635, 2638,2640, 2646, 2655, 2657, 2659, 2661, 2662, 2666, 2668};

/*HB type sampler*/

int hb[82]={119, 
    1214 ,
    1240 ,
    1251 ,
    1268 ,
    1269 ,
    1275 ,
    1278 ,
    1305 ,
    1326 ,
    1331 ,
    1596 ,
    1601 ,
    1952 ,
    1956 ,
    1978 ,
    1980 ,
    2314 ,
    2316 ,
    2330 ,
    2332 ,
    2338 ,
    2340 ,
    2342 ,
    2346 ,
    2356 ,
    2358 ,
    2363 ,
    2660 ,
    2670 ,
    2672 ,
    2679 ,
    2681 ,
    2683 ,
    2685 ,
    2701 ,
    2707 ,
    2709 ,
    2710 ,
    2712 ,
    2714 ,
    2717 ,
    2719 ,
    2721 ,
    2724 ,
    2730 ,
    2737 ,
    2742 ,
    2748 ,
    3033 ,
    3039 ,
    3044 ,
    3050 ,
    3051 ,
    3053 ,
    3055 ,
    3069 ,
    3073 ,
    3075 ,
    3080 ,
    3083 ,
    3085 ,
    3092 ,
    3096 ,
    3099 ,
    3102 ,
    3104 ,
    3392 ,
    3409 ,
    3425 ,
    3428 ,
    3430 ,
    3436 ,
    3437 ,
    3440 ,
    3447 ,
    3448 ,
    3449 ,
    3460 ,
    3465 ,
    3476 ,
    3477 };



