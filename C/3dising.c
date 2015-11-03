//
//  3dising.c
//  
//
//  Created by Sunip Mukherjee on 02/05/15.
//
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*float rnd() //function to generate random float, [0,1)
{
    float result;
    result=rand()/(1.0*RAND_MAX);
    return result;
}*/

#define rnd() rand()*1.0/RAND_MAX

#define dim 10

main()
{
    int a[dim][dim][dim]; //to avoid confusion, put dimension explicitly
    int i, j, k, in, ip, jn, jp, l, m, q, qn, qp;
    float e, t, sum, avg, avg2, av22, mag, eng, eng12, eng2, sum2;
    for (m=0;m<60;m++) //temperature selector
    {t=m/20.0; //temperature
        avg2=0; //average magnetization
        mag=0; //average magnetization square
        eng12=0; //energy
        eng2=0; //energy square
        //initialization of the spin up system
        for (i=0; i<dim; i++)
        {
            for (j=0;j<dim; j++)
            {
                for (q=0;q<dim;q++)
                {
                        {a[i][j][q]=1;} //initializing the ising ferromagnet with unit magnetization
                }
                
            }
            
        }
        for (l=10000;l>0;l--) //randomization
        {
            sum=0; //intermediate variable for summing
            av22=0; //av^2
            sum2=0; //
            for (k=dim*dim*dim; k>0; k--)
            {
                i=rintf((dim-1)*rnd()); //random selection of a coordinate
                j=rintf((dim-1)*rnd());
                q=rintf((dim-1)*rnd());
                if (i==0) //periodic boundary
                {in=dim-1; ip=i+1;}
                else if (i==dim-1)
                {ip=0; in=i-1;}
                else
                {ip=i+1;in=i-1;}
                if (j==0)
                {jn=dim-1; jp=j+1;}
                else if (j==dim-1)
                {jp=0; jn=j-1;}
                else
                {jp=j+1;jn=j-1;}
                if (q==0)
                {qn=dim-1; qp=q+1;}
                else if (q==dim-1)
                {qp=0; qn=q-1;}
                else
                {qp=q+1;qn=q-1;}
                e=a[i][j][q]*(a[in][j][q]+a[ip][j][q]+a[i][jn][q]+a[i][jp][q]+a[i][j][qn]+a[i][j][qp]); //ising hamiltonian
                e=2.0*e;
                if (rnd()<exp(-e/t)) //boltzmann factor comparison that allows spin flip
                {a[i][j][q]=-a[i][j][q];}
            }
            for (i=dim-1;i>=0;i--) //calculation of total magnetization, energy, susceptibility
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
            if (l<9000) //ingnoring first 1000 data to discard fluctuation
            {avg2=avg2+avg;
                mag=mag+av22;
                eng12=eng12+eng;
                eng2=eng2+(eng*eng);}
            
        }
        avg2=avg2/9000; //avg magnetization
        mag=mag/9000;
        eng12=eng12/9000;   //avg energy
        eng2=eng2/9000;
        mag=(mag-avg2*avg2)/t; //average susceptibility
        printf("%f  %f  %f  %f\n",t,avg2,mag,eng12);
        
    }
}
