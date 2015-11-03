#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.673E-11 //value of universal gravitational constant
#define N 9 //number of bodies, now Sun, Earth, Moon, Jupiter.

double dt=100, t=0, p[N][3], v[N][3]; int kounter = 0;
double pos[N][3]={5.232390004684601E+05,5.801842462211855E+04,-2.307177112284731E+04,
			-4.900595711964040E+07,1.978992366271316E+07,6.133258850210199E+06,
			5.067655349913087E+07 ,-9.653428273036470E+07 ,-4.241247608362041E+06,
			 9.252785130208500E+07 ,-1.207621941600018E+08 ,-1.969190382720530E+04,
			 -6.391025220913667E+07 , 2.313913561825329E+08 , 6.405606146924660E+06,
			-7.038582913579912E+08  ,3.896220814257443E+08  ,1.412060224062607E+07,
			-6.653451362193804E+08 ,-1.336821593920252E+09 , 4.972376346619070E+07,
			2.852365348803131E+09  ,8.987975733052702E+08 ,-3.361501171208161E+07,
			4.155870568844649E+09 ,-1.679765506544582E+09, -6.118472145001519E+07};//,
			//1.205393445282690E+09 ,-4.772074295966565E+09,  1.619716110654769E+08//,
			//9.271708401062796E+07 ,-1.210748696936508E+08 , 8.865380553849041E+03,
			//-7.034395876950529E+08 , 3.896836151896999E+08 , 1.412908367202076E+07,
			//-7.039375457219200E+08 , 3.889579775112717E+08 , 1.409008482399184E+07,
			//-7.032909963720385E+08 , 3.887161806200539E+08 , 1.409383239287183E+07,
			//-7.026149462248083E+08 , 3.910215042064786E+08,  1.418189792355913E+07
			//};
	double vel[N][3] = {3.721305063471464E-03 , 1.094945472318582E-02, -1.011263382640045E-04,
			      -2.807294247031718E+01, -4.317031430920626E+01, -9.525423321312552E-01,
			      3.084879279680437E+01 , 1.603067800998303E+01 ,-1.560531391984081E+00,
			      2.320780330074669E+01 , 1.793936454954464E+01 ,-1.810536446145150E-04,
			      -2.241728166347100E+01, -4.432534972258257E+00,  4.570891196930922E-01,
			      -6.481855643411865E+00, -1.081763221407449E+01 , 1.899086833619119E-01,
			      8.120402512828402E+00 ,-4.332681693341700E+00 ,-2.476998312348229E-01,
			      -2.096455795918605E+00,  6.177763220713631E+00 , 5.023190560423396E-02,
			      1.999853833362889E+00 , 5.071205819093015E+00 ,-1.501792715256820E-01};//,
			      //5.388676824532903E+00 , 2.355295232186675E-01 ,-1.566647789188120E+00//,
			     // 2.410669529186982E+01 , 1.852772981574312E+01 ,-4.966149027938727E-02,	
			     // -9.037137153825107E+00,  6.257361880874135E+00 , 7.585767760209459E-01,
			      //7.208454209282952E+00 ,-1.232451272734195E+01  ,3.261386978410448E-01,
			     // 2.751087611900628E+00 ,-5.046378907905977E+00 , 5.287232040070915E-01	,
				//-1.261901810088844E+01, -5.309937762894675E+00,  2.827401953071980E-01	
				//};
double m[N]={1.9891E+30,
	3.3022E23,
	4.8685E24,
	5.9736E+24,
	6.4185E23,
	//1.8986E27,
	1.9891E+29,
	5.6846E26,
	8.6810E25,
	10.243E25};
	//1.25E22};//,
	//7.349E+22,
	//8.93E22,
	//4800000E16,
	//14819000E16,
	//10759000E16
	//};	

/* N body simulation code. Let's try to do something good. All in SI. No approximations. Simple Brute Force Stuff. */

//The FORCE calculator, takes in an integer (that depicts that body, and hence I get all info like position etc.)
double posx(int i, int j);
double posy(int i, int j);
double posz(int i, int j);

double modpos(int i, int j);

double fx(int i, int j);
double fy(int i, int j);
double fz(int i, int j);




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
		for (j=0;j<3;j++)
		{
			pos[i][j]*=1E3;
			vel[i][j]*=1E3;
		}
	}
	}
	
	
	
	FILE *fpos, *fvel;
	int k, pk;
	
	fpos=fopen("poslpert.dat","w+");
	fvel=fopen("vell.dat","w+");
	for (t=0;t<520037690.4;t+=dt)
	{
		if (kounter%1000 == 0){
		//{
		fprintf(fpos,"%lf ",t);
		fprintf(fvel,"%lf ",t);
		
		for (k=0;k<N;k++)
		{
			for (pk=0;pk<3;pk++)
			{
				fprintf(fpos,"%lf ",pos[k][pk]);
				fprintf(fvel,"%lf ",vel[k][pk]);				
			}
				
		}
			fprintf(fpos,"\n");
			fprintf(fvel,"\n");}
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
			} 
		}
		kounter+=1;
	}
	fclose(fpos);
	fclose(fvel);
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



