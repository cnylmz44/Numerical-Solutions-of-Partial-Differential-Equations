#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 101
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
void FiniteDifference(double w[N],double a,double b, double alfa, double beta, double h, int n)
{
     double x,A[N],B[N],C[N],D[N],U[N],Z[N],L[N];
     int i;
     x=a+h;
     A[1]=2+pow(h,2)*q(x);
     B[1]=-1+h/2*p(x);
     D[1]=-pow(h,2)*r(x)+(1+h/2*p(x))*alfa;
     
     for(i=2;i<n;i++)
     {
     	x=a+i*h;
     	A[i]=2+pow(h,2)*q(x);
     	B[i]=-1+h/2*p(x);
     	C[i]=-1-h/2*p(x);
     	D[i]=-pow(h,2)*r(x);
     	
     }
     
     x=b-h;
     A[n]=2+pow(h,2)*q(x);
    
     C[n]=-1-h/2*p(x);
     D[n]=-pow(h,2)*r(x)+(1-h/2*p(x))*beta;
     
     L[1]=A[1];
	 U[1]=B[1]/A[1];
	 
	 for(i=2;i<n;i++)
	 {
	 	L[i]=A[i]-C[i]*U[i-1];
	  	U[i]=B[i]/L[i];
	 }
	 L[n]=A[n]-C[n]*U[n-1];
	 Z[1]=D[1]/L[1];
	 for(i=2;i<=n;i++) Z[i]=(D[i]-C[i]*Z[i-1])/L[i];
	 w[0]=alfa;
	 w[n+1]=beta;
	 w[n]=Z[n];
	 for(i=n-1;i>0;i--) 
	      w[i]=Z[i]-U[i]*w[i+1];
	return;
}
int main()
{
      double a,b,alfa,beta;
      double w[N],h,x;
      int n,i;
      //user should complete
      a=;
	  b=;
	  n=;
	  alfa=;
	  beta=;
	  //Do not change anything
      h=(b-a)/(n+1);
      FiniteDifference(w,a,b,alfa,beta,h,n);
      
      
      printf("\nxi                 wi              Yi            |wi-Yi|");
      printf("\n__________________________________________________________");
      for(i=0;i<=n+1;i++)
      {
      	      x=a+i*h;
			  printf("\n%1.2lf       %1.8lf     %1.8lf     %E",x,w[i],Y(x),fabs(w[i]-Y(x)));
			  printf("\n__________________________________________________________");
      }
      printf("\n");
      system("pause");
      return 0;
}
      
      
