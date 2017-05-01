#include<iostream>
#include<cstdio>
using namespace std;
double F_2x(double x);
double F_xx(double x);
double integration(int a,int b,double (*f)(double x));
int main()
{
	int a,b;
	cin>>a>>b;
	double sum1=0,sum2 = 0;
	sum1 = integration(a,b,F_2x);
	sum2 = integration(a,b,F_xx);
	printf("%.2f\t%.2f\n",sum1,sum2);
	return 0;
}
double F_2x(double x)
{
	return 2*x;
}
double F_xx(double x)
{
	return x*x;
}
double integration(int a,int b,double (*f)(double x))
{
	double step = (double)(b-a)/1000;
	double x=a+step/2;
	double sum = 0;
	int i=0;
	for(i=0;i<1000;i++)
	{
			x+=step;
			sum += f(x)*step;
	}
	return sum;
}
