#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.673E-11 //value of universal gravitational constant
#define N 10 //number of bodies, now Sun, Earth, Moon, Jupiter.
#define size 1
#define velocity 100
#define mlow 0.5
#define mhigh 3.2


double dt=1, t=0, p[N][3], v[N][3];
double pos[N][3], vel[N][3], m[N];

/* N body simulation code. Let's try to do something good. All in SI. No approximations. Simple Brute Force Stuff. */

//The FORCE calculator, takes in an integer (that depicts that body, and hence I get all info like position etc.)
double posx(int i, int j);
double posy(int i, int j);
double posz(int i, int j);

double modpos(int i, int j);

double fx(int i, int j);
double fy(int i, int j);
double fz(int i, int j);

//position generator
double gp(void)
{
	return (size*1.0*rand()/RAND_MAX);
}

//velocity generator
double vp(void)
{
	return (velocity*1.0*rand()/RAND_MAX);
}

//mass generator
double mp(void)
{
	return (mlow+((mhigh-mlow)*1.0*rand()/RAND_MAX));
}



main()
{
	//initial conditions, Sun
	//pos[0][0]=5.232390004684601E+08;
	//pos[0][1]=5.801842462211855E+07;
	//pos[0][2]=-2.307177112284731E+07;
	
	//Mercury
	//pos[1][0]=-4.900595711964040E+10;
	//pos[1][1]=1.978992366271316E+10;
	//pos[1][2]=6.133258850210199E+9;
	
	//Venus
	//pos[2][0]=5.067655349913087E+10;
	//pos[2][1]=-9.653428273036470E+10;
	//pos[2][2]=-4.241247608362041E+9;
	
	//Earthwa
	//pos[3][0]=9.252785130208500E+10;
	//pos[3][1]=0;
	//pos[3][2]=0;
	
	//positions, all at once. In the order described in sol_init.dat
	
	
	
	//m[0]=1.989E+30;
	//m[1]=5.972E+24;
	//m[2]=7.35E+22;
	//m[3]=317.828*m[1];
	{
	int i, j;
	for (i=0;i<N;i++)
	{
		printf("%d\n",i);
		m[i]=mp();
		for (j=0;j<3;j++)
		{
			pos[i][j]=gp();
			vel[i][j]=vp();
		}
	}
	}
	printf("Generation done.\n");
	
	
	FILE *fpos, *fvel;
	int k, pk;
	
	fpos=fopen("pos1.dat","w+");
	fvel=fopen("vel1.dat","w+");
	int i, j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<3;j++)
		{
			fprintf(fpos,"%lf ",pos[i][j]);
			fprintf(fvel,"%lf ",vel[i][j]);
		}
		fprintf(fpos,"%lf\n",m[i]);
		fprintf(fvel,"%lf\n",m[i]);
	}
	fclose(fpos);
	fclose(fvel);
	printf("Copy done.\n");
	for (t=0;t<6000;t+=dt)
	{
		//fprintf(fpos,"%lf ",t);
		//fprintf(fvel,"%lf ",t);
		
		//for (k=0;k<N;k++)
		//{
		//	for (pk=0;pk<3;pk++)
			//{
				//fprintf(fpos,"%lf ",pos[k][pk]);
				//fprintf(fvel,"%lf ",vel[k][pk]);				
			//}
				
		//}
		//fprintf(fpos,"\n");
			//fprintf(fvel,"\n");
		for (k=0;k<N;k++)
		{
			v[k][0]=vel[k][0];
			v[k][1]=vel[k][1];
			v[k][2]=vel[k][2];
						
			p[k][0]=pos[k][0]+vel[k][0]*dt;
			p[k][1]=pos[k][1]+vel[k][1]*dt;
			p[k][2]=pos[k][2]+vel[k][2]*dt;
						
			
			
				int j;
				for(j=0;j<N;j++)
				{
					if (j!=k)
					{
						int thread;
						#pragma omp parallel for 
						v[k][0]+=fx(k,j)*dt;
						v[k][1]+=fy(k,j)*dt;
						v[k][2]+=fz(k,j)*dt;
						
						p[k][0]+=0.5*fx(k,j)*dt*dt;
						p[k][1]+=0.5*fy(k,j)*dt*dt;
						p[k][2]+=0.5*fz(k,j)*dt*dt;
						
					}
				}
				
		}
		//update
		for (k=0;k<N;k++)
		{
			int j;
			for (j=0;j<3;j++)
			{
				pos[k][j]=p[k][j];
				vel[k][j]=v[k][j];
			} 
		}
		
	}
	fpos=fopen("pos2.dat","w+");
	fvel=fopen("vel2.dat","w+");
	for (i=0;i<N;i++)
	{
		for (j=0;j<3;j++)
		{
			fprintf(fpos,"%lf ",pos[i][j]);
			fprintf(fvel,"%lf ",vel[i][j]);
		}
		fprintf(fpos,"%lf\n",m[i]);
		fprintf(fvel,"%lf\n",m[i]);
	}
	fclose(fpos);
	fclose(fvel);
}


double posi(int i, int j, int k)
{
	return (pos[j][k]-pos[i][k]);
}


double modpos(int i, int j)
{
	double result=0;
	int k;
	#pragma omp parallel for reduction(+:result)
	for (k=0;k<3;k++)
	{
		result+=(posi(i,j,k)*posi(i,j,k));
	}
	return (pow(result,0.5));
}


double modvel(int i)
{
	return (pow((vel[i][0]*vel[i][0]+vel[i][1]*vel[i][1]+vel[i][2]*vel[i][2]),0.5));
}

double f(int i, int j, int k) //acceleration on i due to j, k component
{
	return (G*m[j]*posx(i,j,k)/pow(modpos(i,j),3));
}

