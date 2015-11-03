//Random number generator
#include <dc.h>
mt_struct *mts;
void mts_gen(void)
{
    int i,j;
    

    init_dc(4172);

    /* This trys to find a small Mersenne Twister with period 2^521-1. */
    mts = get_mt_parameter(32,521);
    if (mts == NULL) {
        printf ("error\n");
    }
    else {
        sgenrand_mt(3241, mts);
    }
}


double rnd(void)
{
	return (genrand_mt(mts)*1.0/4294967295);
}

//variation dates
int bb_var_period(void)   //the day bb parameters suffer an abrupt large change
{
    float result = bb_base + (-bb_var+ genrand_mt(mts) % (2*bb_var+1));
    return result;
}


int pl_var_period(void)    //the day pl parameters suffer an abrupt large change
{
	float result = pl_base + (-pl_var+ genrand_mt(mts) % (2*pl_var+1));
    	return result;

}

//variations
double tempgen(double oldval, double tvar) //tvar is either T_var_small or T_var_large depending on date
{
     float result = oldval + (-tvar + 2*tvar*rnd());
     return result;
}

double aagen(double oldval, int condition)
{
    double var;
    if (condition == 0)
    {
        var = oldval*0.1;
    }
    else
    {
        var = oldval*0.5;
    }
    return (oldval += -var + 2*var*rnd());
}

double plawexp(double oldval, int condition) //condition is either 0 or 1, 0 implies small change over old date
{
	if (condition == 0)
        	{return (oldval+=-bvar+2*bvar*rnd());}
    	else
        	{return (0.7+0.3*rnd());}
}

//black body dist
double bb(double f, double T)
{
	return ((2*h*pow(f,3)/(c*c))*(1/(exp(h*f/(k_b*T))-1)));
}
	
//powerlaw	
double pl(double f, double a, double b)
{
	return (a*pow(f,-b));
}
	
//plawstripped	
double pl1(double f, double b)
{
	return (pow(f,-b));
}

//integrators
double totflux(double limlowf, double limhighf, double T)
{
	//double stepsize = 100000;
	double commdiff = (limhighf - limlowf)/stepsize;
	double totflux = 0.0;
	int counter;
	int kounter;
	double lowerlim;
	double upperlim;
	for(counter=0;counter<stepsize;counter++)
		//{totflux += (bb(limlowf+counter*commdiff,T) + bb(limlowf+(counter+1)*commdiff,T))*(h*0.5);}
	{
		lowerlim = limlowf + counter*commdiff;
		upperlim = limlowf + (counter + 1)*commdiff;
		double m = upperlim - lowerlim;
		m *= 0.5;
		double n = upperlim + lowerlim;
		n *= 0.5;
		for (kounter = 0; kounter < quadrature; kounter++)
		{
			double x = m*u[kounter] + n ;
			totflux += w[kounter]*bb(x, T);
		}
	}
	//printf("Totflux = %e\n", totflux);
	return totflux;
}

double powerlawint(double limlowf, double limhighf, double b)
{
	//double stepsize = 100000;
	double commdiff = (limhighf - limlowf)/stepsize;
	double totflux = 0.0;
	int counter;
	int kounter;
	double lowerlim;
	double upperlim;
	for(counter=0;counter<stepsize;counter++)
		//{totflux += (pl1(limlowf+counter*commdiff, b) + pl1(limlowf+(counter+1)*commdiff, b))*(h*0.5);}
	{
		lowerlim = limlowf + counter*commdiff;
		upperlim = limlowf + (counter + 1)*commdiff;
		double m = upperlim - lowerlim;
		m *= 0.5;
		double n = upperlim + lowerlim;
		n *= 0.5;
		for (kounter = 0; kounter < quadrature; kounter++)
		{
			double x = m*u[kounter] + n ;
			totflux += w[kounter]*pl1(x, b);
		}
	}
	//printf("Totflux = %e\n", totflux);
	return totflux;
}

double plawint(double limlowf, double limhighf, double a, double b)
{
	//double stepsize = 100000;
	double commdiff = (limhighf - limlowf)/stepsize;
	double totflux = 0.0;
	int counter;
	int kounter;
	double lowerlim;
	double upperlim;
	for(counter=0;counter<stepsize;counter++)
		//{totflux += (pl1(limlowf+counter*commdiff, b) + pl1(limlowf+(counter+1)*commdiff, b))*(h*0.5);}
	{
		lowerlim = limlowf + counter*commdiff;
		upperlim = limlowf + (counter + 1)*commdiff;
		double m = upperlim - lowerlim;
		m *= 0.5;
		double n = upperlim + lowerlim;
		n *= 0.5;
		for (kounter = 0; kounter < quadrature; kounter++)
		{
			double x = m*u[kounter] + n ;
			totflux += w[kounter]*pl(x, a, b);
		}
	}
	return totflux;
}

double rgen(double T, double a, double b)
{
	//double stepsize = 1000000;
	//double commdiff = (rmax - rmin)/stepsize;
	double result = 0.0;
	result = (totflux(rmin,rmax,T) + plawint(rmin,rmax,a,b))/(rmax-rmin);
	//printf("%e %e \n", totflux(rmin,rmax,T), plawint(rmin,rmax,a,b));
	return result;
}	
double jgen(double T, double a, double b)
{
	//double stepsize = 1000000;
	//double commdiff = (rmax - rmin)/stepsize;
	double result = 0.0;
	result = (totflux(jmin,jmax,T) + plawint(jmin,jmax,a,b))/(jmax-jmin);
	return result;
}	
	


