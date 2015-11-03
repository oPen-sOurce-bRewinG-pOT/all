//Ising model with more than nearest neighbour interaction, with an weight factor. At T=0, i.e. guided by only the minimization of the Hamiltonian.
#include<stdio.h>
#include<math.h>
float lambda=2; //global order parameter
int ds_max=4;	//global distance parameter
float rnd()
{
	float result;
	result=rand()/(pow(2,31)-1);
	return result;
}
float w(int i, int j)
{
	float result;
	result = exp(-(i-j)*(i-j)/(lambda*lambda));
	return result;
}
main()
{
	int a[100], dim=100, i, ip, in, j, jp, jn, k, kp ,kn;
	float e, t, sum, avg, avg2, av22, mag, eng, eng12, eng2, sum2;
	avg2=0; //average magnetization
        mag=0; //average magnetization square
        eng12=0;
        eng2=0;
        //initialization of the random system
        for (i=0; i<dim; i++)
        {
            if (rnd()>0.5)
            {
            	a[i]=1;
            }    
            else
            {
            	a[i]=-1;
            }
        }
        for (l=0;l<10000;l++)
        {
            sum=0; //intermediate variable for summing
            av22=0;
            sum2=0;
            for (k=0; k<(dim); k++)
            {
                i=rintf((dim-1)*rnd());
                if (i==0)
                {in=dim-1; ip=i+1;}
                else if (i==dim-1)
                {ip=0; in=i-1;}
                else
                {ip=i+1;in=i-1;}
                e=0; //energy
                for (j=-dx_max; j<=ds_max; j++) !!In between 0 and 4 then what!! Look into it
                e=a[i]*(a[in][j][q]+a[ip][j][q]+a[i][jn][q]+a[i][jp][q]+a[i][j][qn]+a[i][j][qp]);
                e=2.0*e;
                //if (rnd()<exp(-e/t))
                {a[i][j][q]=-a[i][j][q];}
            }
            for (i=0;i<dim;i++)
            {
                if (i==0)
                {in=dim-1; ip=i+1;}
                else if (i==dim-1)
                {ip=0; in=i-1;}
                else
                {ip=i+1;in=i-1;}
                for (j=0;j<dim;j++)
                {
                    if (j==0)
                    {jn=dim-1; jp=j+1;}
                    else if (j==dim-1)
                    {jp=0; jn=j-1;}
                    else
                    {jp=j+1;jn=j-1;}
                    for (q=0;q<dim;q++)
                    {
                        if (q==0)
                        {qn=dim-1; qp=q+1;}
                        else if (q==dim-1)
                        {qp=0; qn=q-1;}
                        else
                        {qp=q+1;qn=q-1;}
                        sum=sum+a[i][j][q];
                        sum2=sum2-a[i][j][q]*(a[in][j][q]+a[ip][j][q]+a[i][jn][q]+a[i][jp][q]+a[i][j][qn]+a[i][j][qp]);}
                }
                
            }
            avg=sum/(dim*dim*dim);
            av22=pow(avg,2);
            eng=sum2/(dim*dim*dim*2);
            if (l>1000)
            {avg2=avg2+avg;
                mag=mag+av22;
                eng12=eng12+eng;
                eng2=eng2+(eng*eng);}
            
        }
        avg2=avg2/9000; //avg magnetization
        mag=mag/9000;
        eng12=eng12/9000;   //avg energy
}


