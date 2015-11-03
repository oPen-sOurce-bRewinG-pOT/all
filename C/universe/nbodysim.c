#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.673E-11 //value of universal gravitational constant
#define N 20 //number of bodies, now Sun, Earth, Moon, Jupiter.
#define size 1
#define velocity 1
#define mlow 10
#define mhigh 2500
#define TIME 1000


double dt=0.01, t=0, p[N][3], v[N][3];
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
	return (-velocity+(velocity*2.0*rand()/RAND_MAX));
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
		m[i]=1;
		for (j=0;j<3;j++)
		{
			pos[i][j]=gp();
			vel[i][j]=vp();
		}
	}
	}
	printf("Generation done!\n");
	
	
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
			//fprintf(fvel,"%lf ",vel[i][j]);
		}
		for (j=0;j<3;j++)
		{
			fprintf(fpos,"%lf ",vel[i][j]);
			//fprintf(fvel,"%lf ",vel[i][j]);
		}
		fprintf(fpos,"%lf\n",m[i]);
		fprintf(fvel,"%lf\n",m[i]);
	}
	fclose(fpos);
	fclose(fvel);
	printf("State 1 copy done!\n");
	for (t=0;t<TIME;t+=dt)
	{
		//fprintf(fpos,"%lf ",t);
		//fprintf(fvel,"%lf ",t);
		
		//for (k=0;k<N;k++)
		{
		//	for (pk=0;pk<3;pk++)
			{
				//fprintf(fpos,"%lf ",pos[k][pk]);
				//fprintf(fvel,"%lf ",vel[k][pk]);				
			}
				
		}
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
				if (pos[k][j]<0)
				{
					pos[k][j]=-pos[k][j];
				}
				while (pos[k][j]>size)
				{
					pos[k][j]-=size;
				}
			} 
		}
	if (((int)(t/dt))%50000==0){
	//fpos=fopen("pos2.dat","w+");
	//fvel=fopen("vel2.dat","w+");
	//for (i=0;i<N;i++)
	//{
	//	for (j=0;j<3;j++)
//		{
//			fprintf(fpos,"%lf ",pos[i][j]);
			//fprintf(fpos,"%lf ",vel[i][j]);
//		}
//		for (j=0;j<3;j++)
//		{
//			fprintf(fpos,"%lf ",vel[i][j]);
//			//fprintf(fpos,"%lf ",vel[i][j]);
//		}
//		fprintf(fpos,"%lf\n",m[i]);
//		fprintf(fvel,"%lf\n",m[i]);
//	}
//	fclose(fpos);
//	fclose(fvel);
	printf("Plot, I am waiting! Press 1 to continue, 0 to terminate.\n");
	int check;
	//scanf("%d",&check);
	//if (check==0)
	//{break;}	
	}}
	fpos=fopen("pos2.dat","w+");
	fvel=fopen("vel2.dat","w+");
	for (i=0;i<N;i++)
	{
		for (j=0;j<3;j++)
		{
			fprintf(fpos,"%lf ",pos[i][j]);
			//fprintf(fpos,"%lf ",vel[i][j]);
		}
		for (j=0;j<3;j++)
		{
			fprintf(fpos,"%lf ",vel[i][j]);
			//fprintf(fpos,"%lf ",vel[i][j]);
		}
		fprintf(fpos,"%lf\n",m[i]);
		fprintf(fvel,"%lf\n",m[i]);
	}
	fclose(fpos);
	fclose(fvel);
	printf("State 2 copy done! Success!\n");
}


double posx(int i, int j)
{
	return (pos[j][0]-pos[i][0]);
}

double posy(int i, int j)
{
	return (pos[j][1]-pos[i][1]);
}

double posz(int i, int j)
{
	return (pos[j][2]-pos[i][2]);
}

double modpos(int i, int j)
{
	return (pow((posx(i,j)*posx(i,j)+posy(i,j)*posy(i,j)+posz(i,j)*posz(i,j)),0.5));
}


double modvel(int i)
{
	return (pow((vel[i][0]*vel[i][0]+vel[i][1]*vel[i][1]+vel[i][2]*vel[i][2]),0.5));
}

double fx(int i, int j) //acceleration on i due to j, x component
{
	return (G*m[j]*posx(i,j)/pow(modpos(i,j),3));
}

double fy(int i, int j) //force on i due to j, y component
{

	return (G*m[j]*posy(i,j)/pow(modpos(i,j),3));
}

double fz(int i, int j) //force on i due to j, z component
{
	return (G*m[j]*posz(i,j)/pow(modpos(i,j),3));
}



