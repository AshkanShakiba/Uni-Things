#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	srand(time(0));
	double a,b,c,aa,ba,ca;
	a=rand()%20+5;
	b=rand()%20+5;
	ca=(rand()%(1571))/1000.0;
	c=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(ca));
	aa=asin((a*sin(ca))/c);
	ba=asin((b*sin(ca))/c);
	printf("Random numbers:\n\ta = %.2lf, b = %.2lf, ^C = %.2lf Rad\n",a,b,ca);
	printf("Result:\n\tc = %.2lf\n",c);
	printf("Other angles:\n\t^A = %.2lf Rad, ^B = %.2lf Rad",aa,ba);
	return 0;
}
