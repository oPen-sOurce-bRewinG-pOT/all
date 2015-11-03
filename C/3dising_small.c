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
#include "/usr/include/stdbool.h"


float rnd()
{
    float result;
    result=rand()/(pow(2,31)-1);
    return result;
}
main()
{
    int a[10][10][10];
    int i, j, k, in, ip, jn, jp, l, m, q, qn, qp;
    float e, t, sum, avg, avg2, av22, mag, eng, eng12, eng2, sum2;
    for (m=0;m</*10*/1;m++)
    {t=m/20.0;
        avg2=0; //average magnetization
        mag=0; //average magnetization square
        eng12=0;
        eng2=0;
        //initialization of the spin up system
        for (i=0; i<10; i++)
        {
            for (j=0;j<10; j++)
            {
                for (q=0;q<10;q++)
                {
                        {a[i][j][q]=1;}
                }
                
            }
            
        }
        for (l=0;l<10000;l++)
        {
            sum=0; //intermediate variable for summing
            av22=0;
            sum2=0;
            for (k=0; k<100000; k++)
            {
                i=rintf(9*rnd());
                j=rintf(9*rnd());
                q=rintf(9*rnd());
                if (i==0)
                {in=9; ip=i+1;}
                else if (i==9)
                {ip=0; in=i-1;}
                else
                {ip=i+1;in=i-1;}
                if (j==0)
                {jn=9; jp=j+1;}
                else if (j==9)
                {jp=0; jn=j-1;}
                else
                {jp=j+1;jn=j-1;}
                if (q==0)
                {qn=9; qp=q+1;}
                else if (q==9)
                {qp=0; qn=q-1;}
                else
                {qp=q+1;qn=q-1;}
                e=a[i][j][q]*(a[in][j][q]+a[ip][j][q]+a[i][jn][q]+a[i][jp][q]+a[i][j][qn]+a[i][j][qp]);
                e=2.0*e;
                if (rnd()<exp(-e/t))
                {a[i][j][q]=-a[i][j][q];}
            }
            for (i=0;i<10;i++)
            {
                if (i==0)
                {in=9; ip=i+1;}
                else if (i==9)
                {ip=0; in=i-1;}
                else
                {ip=i+1;in=i-1;}
                for (j=0;j<10;j++)
                {
                    if (j==0)
                    {jn=9; jp=j+1;}
                    else if (j==9)
                    {jp=0; jn=j-1;}
                    else
                    {jp=j+1;jn=j-1;}
                    for (q=0;q<10;q++)
                    {
                        if (q==0)
                        {qn=9; qp=q+1;}
                        else if (q==9)
                        {qp=0; qn=q-1;}
                        else
                        {qp=q+1;qn=q-1;}
                        sum=sum+a[i][j][q];
                        sum2=sum2-a[i][j][q]*(a[in][j][q]+a[ip][j][q]+a[i][jn][q]+a[i][jp][q]+a[i][j][qn]+a[i][j][qp]);}
                }
                
            }
            avg=sum/(10*10*10);
            av22=pow(avg,2);
            eng=sum2/(10*10*10*2);
            if (l>1000)
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
