#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 101
#define M 100
#define PI 3.1415926535897932384626433832795
#define TOL 1e-8
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
double Modul(double v[],int n)
{
	double e=fabs(v[1]);
	int i;
	for(i=2;i<=n;i++)
	     if(fabs(v[i])>e) e=fabs(v[i]);
	return e;
}
void NonlinearFiniteDifference(double w[N],double a,double b, double alfa, double beta, double h, int n)
{
     double x,t,A[N],B[N],C[N],D[N],U[N],Z[N],L[N],v[N];
     int i,k;
     w[0]=alfa;
     w[n+1]=beta;
     for(i=1;i<=n;i++)w[i]=alfa+i*((beta-alfa)/(b-a))*h;
     k=1;
     while(k<=M)
     {
     	x=a+h;
     	t=(w[2]-alfa)/(2*h);
     	A[1]=2+pow(h,2)*Fy(x,w[1],t);
     	B[1]=-1+h/2*Fyt(x,w[1],t);
     	D[1]=-(2*w[1]-w[2]-alfa+pow(h,2)*Fxyyt(x,w[1],t));
     	for(i=2;i<n;i++)
     	{
     		x=a+i*h;
     		t=(w[i+1]-w[i-1])/(2*h);
     		A[i]=2+pow(h,2)*Fy(x,w[i],t);
			B[i]=-1+h/2*Fyt(x,w[i],t);   
			C[i]=-1-h/2*Fyt(x,w[i],t);  		
			D[i]=-(2*w[i]-w[i+1]-w[i-1]+pow(h,2)*Fxyyt(x,w[i],t));
     	}
     	x=b-h;
     	t=(beta-w[n-1])/(2*h);
        A[n]=2+pow(h,2)*Fy(x,w[n],t);
        C[n]=-1-h/2*Fyt(x,w[n],t);
     	D[n]=-(2*w[n]-w[n-1]-beta+pow(h,2)*Fxyyt(x,w[n],t));
     	
     	L[1]=A[1];
		U[1]=B[1]/A[1];
		Z[1]=D[1]/L[1];
		for(i=2;i<n;i++)
		{
		 	L[i]=A[i]-C[i]*U[i-1];
		  	U[i]=B[i]/L[i];
		 	Z[i]=(D[i]-C[i]*Z[i-1])/L[i];
		}
		L[n]=A[n]-C[n]*U[n-1];
		Z[n]=(D[n]-C[n]*Z[n-1])/L[n];
		v[n]=Z[n];
		w[n]+=v[n];
		for(i=n-1;i>0;i--)
		{
			v[i]=Z[i]-U[i]*v[i+1];
			w[i]+=v[i];
		}
		if(Modul(v,n)<=TOL) return;
	    k++;	
	}
	printf("\nMaximum number of iterations exceed\n");
	system("pause");
	exit(1);
}
int main()
{
      double a,b,alfa,beta;
      double w[N],h,x;
      int n,i;
      //User shuld complete
      a=;
	  b=;
	  n=;
	  alfa=;
	  beta=;
	  //Do not change anything
      h=(b-a)/(n+1);
      NonlinearFiniteDifference(w,a,b,alfa,beta,h,n);
      
      printf("\nxi\twi\t\tYi\t\t|wi-Yi|");
      printf("\n________________________________________________________");
      for(i=0;i<=n+1;i++)
      {
      	      x=a+i*h;
			  printf("\n%1.2lf\t%lf\t%lf\t%E",x,w[i],Y(x),fabs(w[i]-Y(x)));
			  printf("\n________________________________________________________");
      }
      printf("\n");
      system("pause");
      return 0;
}
      
      
