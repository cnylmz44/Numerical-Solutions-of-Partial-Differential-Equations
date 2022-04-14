#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
#define PI 3.1415926535897932384626433832795
double p(double x)
{
    return ;  
}
double q(double x)
{
    return ;   
}
double r(double x)
{
    return ;    
}
double Y(double x)
{
	return ;
}
void RungaKutta(double u[3][N],double v[3][N],double a,double h, int n)
{
     double k11,k12,k21,k22,k31,k32,k41,k42,z11,z12,z21,z22,z31,z32,z41,z42;
     double x;
     int i;
     for(i=0;i<n;i++)
     {
         x=a+i*h;
         k11=h*u[2][i];
         k12=h*(p(x)*u[2][i]+q(x)*u[1][i]+r(x));
         k21=h*(u[2][i]+0.5*k12);
         k22=h*(p(x+h/2)*(u[2][i]+0.5*k12)+q(x+h/2)*(u[1][i]+0.5*k11)+r(x+h/2));
         k31=h*(u[2][i]+0.5*k22);
         k32=h*(p(x+h/2)*(u[2][i]+0.5*k22)+q(x+h/2)*(u[1][i]+0.5*k21)+r(x+h/2));
         k41=h*(u[2][i]+k32);
         k42=h*(p(x+h)*(u[2][i]+k32)+q(x+h)*(u[1][i]+k31)+r(x+h));
         u[1][i+1]=u[1][i]+1./6*(k11+2*k21+2*k31+k41);
         u[2][i+1]=u[2][i]+1./6*(k12+2*k22+2*k32+k42);
         z11=h*v[2][i];
         z12=h*(p(x)*v[2][i]+q(x)*v[1][i]);
         z21=h*(v[2][i]+0.5*z12);
         z22=h*(p(x+h/2)*(v[2][i]+0.5*z12)+q(x+h/2)*(v[1][i]+0.5*z11));
         z31=h*(v[2][i]+0.5*z22);
         z32=h*(p(x+h/2)*(v[2][i]+0.5*z22)+q(x+h/2)*(v[1][i]+0.5*z21));
         z41=h*(v[2][i]+z32);
         z42=h*(p(x+h)*(v[2][i]+z32)+q(x+h)*(v[1][i]+z31));
         v[1][i+1]=v[1][i]+1./6*(z11+2*z21+2*z31+z41);
         v[2][i+1]=v[2][i]+1./6*(z12+2*z22+2*z32+z42);
     }
     return;
}
main()
{
      double a,b,alfa,beta;
      double u[3][N],v[3][N];
      double w10,w20,W1,W2;
      double h,x;
      int n,i;
      //User should change
      a=;
	  b=;
	  n=;
	  alfa=;
	  beta=;
	  //Do not change anything
      h=(b-a)/n;
      u[1][0]=alfa;
      u[2][0]=0;
      v[1][0]=0;
      v[2][0]=1;
      RungaKutta(u,v,a,h,n);
      w10=alfa;
      w20=(beta-u[1][n])/v[1][n];
      printf("\nxi\t\twi\t\tYi\t\t|wi-yi|");
      printf("\n________________________________________________________");
      printf("\n%1.2lf\t%lf\t%lf\t%E",a,w10,Y(a),fabs(Y(a)-u[1][0]));
      printf("\n________________________________________________________");
      for(i=1;i<=n;i++)
      {
             W1=u[1][i]+w20*v[1][i];
             W2=u[2][i]+w20*v[2][i];
             x=a+i*h;
             printf("\n%1.2lf\t%lf\t%lf\t%E",x,W1,Y(x),fabs(W1-Y(x)));
             printf("\n_____________________________________________________________________");
      }
      printf("\n");
      system("pause");
      return 0;
}
      
      
