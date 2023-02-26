#include <stdio.h>
int main(){
	int m;
	double h;
	scanf("%d%lf",&m,&h);
	printf("%.2lf",m*h*0.94+(m/12)*2*h-(m/6)*(h/5));
}
