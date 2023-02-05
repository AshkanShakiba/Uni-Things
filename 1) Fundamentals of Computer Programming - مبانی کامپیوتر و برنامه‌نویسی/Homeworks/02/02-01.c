#include <stdio.h>
#include <math.h>
//#define P 3.14
//#define e 2.72
#define P 3.141592653589793
#define e 2.7182818284590451
int main(){
	/*
	//Optimized solution:
	printf("34.76\n84.59\n0.14");
	//Heh! >_< @_@
	*/
	
	//Not optimized solution:
	double answer1,answer2,answer3;
	double a=-5,b=P/6,c=P/5;
	// log2 (x) = logy (x) / logy (2)
	answer1=pow(e,(log(fabs(a))/log(2))+sin(b)+tan(c));
	a=3.5;
	b=2;
	c=9;
	answer2=a*(a+b)*b*log(c);
	a=5;
	b=6;
	answer3=pow(1/pow(a,0.3)+2/pow(b,2.3),4.5);
	printf("%.2lf\n%.2lf\n%.2lf\n",answer1,answer2,answer3);
}

