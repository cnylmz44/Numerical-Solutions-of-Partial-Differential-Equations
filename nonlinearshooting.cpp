#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI  3.1415926535897932384626433832795
#define N  101
#define M  300
#define TOL  1e-5
double Fxyyt(double x,double y,double yt)
{
	return ;	
}
double Fy(double x,double y,double yt)
{
	return ;	
}
double Fyt(double x,double y,double yt)
{
	return ;	
}
double Y(double x)
{
	return ;	
}
void RungeKutta(double w[3][N],double &u1,double &u2,double a,double h,int n)
{
	double k11,k12,k21,k22,k31,k32,k41,k42,z11,z12,z21,z22,z31,z32,z41,z42;
	double x;
	int i;
	for(i=1;i<=n;i++)
	{
		x=a+(i-1)*h;
		k11=h*w[2][i-1];
		k12=h*Fxyyt(x,w[1][i-1],w[2][i-1]);
		k21=h*(w[2][i-1]+0.5*k12);
		k22=h*Fxyyt(x+h/2,w[1][i-1]+0.5*k11,w[2][i-1]+0.5*k12);
		k31=h*(w[2][i-1]+0.5*k22);
		k32=h*Fxyyt(x+h/2,w[1][i-1]+0.5*k21,w[2][i-1]+0.5*k22);
		k41=h*(w[2][i-1]+k32);
		k42=h*Fxyyt(x+h,w[1][i-1]+k31,w[2][i-1]+k32);
		w[1][i]=w[1][i-1]+1./6*(k11+2*k21+2*k31+k41);
		w[2][i]=w[2][i-1]+1./6*(k12+2*k22+2*k32+k42);
		z11=h*u2;
		z12=h*(Fy(x,w[1][i-1],w[2][i-1])*u1+Fyt(x,w[1][i-1],w[2][i-1])*u2);
		z21=h*(u2+0.5*z12);
		z22=h*(Fy(x+h/2,w[1][i-1],w[2][i-1])*(u1+0.5*z11)+Fyt(x+h/2,w[1][i-1],w[2][i-1])*(u2+0.5*z12));
		z31=h*(u2+0.5*z22);
		z32=h*(Fy(x+h/2,w[1][i-1],w[2][i-1])*(u1+0.5*z21)+Fyt(x+h/2,w[1][i-1],w[2][i-1])*(u2+0.5*z22));
		z41=h*(u2+z32);
		z42=h*(Fy(x+h,w[1][i-1],w[2][i-1])*(u1+z31)+Fyt(x+h,w[1][i-1],w[2][i-1])*(u2+z32));
		u1+=1./6*(z11+2*z21+2*z31+z41);
		u2+=1./6*(z12+2*z22+2*z32+z42);
	}
	return;
}
main()
{
	double w[3][N],a,b,alfa,beta,h,TK,u1,u2;
	int i,k,n;
	// User should complete
    a=;
	b=;
	n=;
	alfa=;
	beta=;
	// do not change anything 

	h=(b-a)/n;
	k=1;
	TK=(beta-alfa)/(b-a);
	while(k<=M)
	{
		w[1][0]=alfa;
		w[2][0]=TK;
		u1=0;
		u2=1;
		RungeKutta(w,u1,u2,a,h,n);
		if(fabs(w[1][n]-beta)<=TOL)break;
		TK=TK-(w[1][n]-beta)/u1;
		k++;
	}
	if(k==M+1) 
	{
		printf("\nMaximum iterasyon sayisina ulasildi cozum yok\n");
		exit(1);		
	}
	else 
	{
		printf("\nxi\twi\t\tyi\t\t|yi-wi|");
		printf("\n______________________________________________________________");
		for(i=0;i<=n;i++)
		{
		   printf("\n%1.2lf\t%lf\t%lf\t%E",a+i*h,w[1][i],Y(a+i*h),fabs(w[1][i]-Y(a+i*h)));
		  	printf("\n______________________________________________________________");
	    }
    }
    printf("\n");
    system("pause");
	return 0; 
	   
}

