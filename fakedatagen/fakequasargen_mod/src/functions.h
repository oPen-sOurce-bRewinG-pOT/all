//Random number generator
mt_struct *mts[N_THR];
void generator(int k)
{
	int j;
	for (j=0;j<k;j++)
    	{
    	/* This trys to find a small Mersenne Twister with period 2^521-1. */
    		mts[j] = get_mt_parameter_id_st(32,521,rand() % 65536,4172);
		if (mts[j] == NULL){printf("Error on %d thread.\n", j);}
    		else {sgenrand_mt(3241+40*j,mts[j]);}
    	}
}

double rnd(int id)
{
	return (genrand_mt(mts[id])*1.0/4294967295);
}

//variation dates
int bb_var_period(void)   //the day bb parameters suffer an abrupt large change
{
    float result = Tvarday + (-(Tvardayran/2) + Tvardayran*floor(rnd(id)));
    return result;
}


int pl_var_period(void)    //the day pl parameters suffer an abrupt large change
{
	float result = bvarday + (-(bvardayran/2)+ bvardayran*floor(rnd(id)));
    	return result;

}

//variations
double basegen(double oldval)
{
    double newvar = 0.05*basevar;
    if (oldval == 0)
    {return (base_avg + (-(basevar/2.0) + (basevar*rnd(id))));}
    else
    {return (oldval - newvar + 2*newvar*rnd(id));}
}
double tempgen(double oldval, double tvar) //tvar is either T_var_small or T_var_large depending on date
{
     float result = oldval + (-tvar + 2*tvar*rnd(id));
     return result;
}

double agen(double oldval, double avar);
{
    
}

double plawexp(double oldval, int condition) //condition is either 0 or 1, 0 implies small change over old date
{
	if (condition == 0)
        	{return (oldval+=-bvar+2*bvar*rnd(id));}
    	else
        	{return (0.7+0.3*rnd(id));}
}

//black body dist
double bb(double f, double T, double base)
{
	return (base*(2*h*pow(f,3)/(c*c))*(1/(exp(h*f/(k_b*T))-1)));
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
double totflux(double limlowf, double limhighf, double T, double base)
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
		for (kounter = 0; kounter < 8; kounter++)
		{
			double x = m*u[kounter] + n ;
			totflux += w[kounter]*bb(x, T, base);
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
		for (kounter = 0; kounter < 8; kounter++)
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
		for (kounter = 0; kounter < 8; kounter++)
		{
			double x = m*u[kounter] + n ;
			totflux += w[kounter]*pl(x, a, b);
		}
	}
	return totflux;
}

double rgen(double base, double T, double a, double b)
{
	//double stepsize = 1000000;
	//double commdiff = (rmax - rmin)/stepsize;
	double result = 0.0;
	result = (totflux(rmin,rmax,T,base) + plawint(rmin,rmax,a,b))/(rdiff);
	//printf("%e %e \n", totflux(rmin,rmax,T), plawint(rmin,rmax,a,b));
	return result;
}	
double jgen(double base, double T, double a, double b)
{
	//double stepsize = 1000000;
	//double commdiff = (rmax - rmin)/stepsize;
	double result = 0.0;
	result = (totflux(jmin,jmax,T,base) + plawint(jmin,jmax,a,b))/(jdiff);
	return result;
}	
	


