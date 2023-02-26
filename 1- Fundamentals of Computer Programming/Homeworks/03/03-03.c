#include <stdio.h>
#include <math.h>
int main(){
	double l1,l2,l3,t,tm;
	scanf("%lf%lf%lf%lf",&l1,&l2,&t,&tm);
	if(t>tm){
		printf("Theta is bigger than theta max!");
	}
	else{
		l3=sqrt(pow(l1,2)+pow(l2,2)-2*l1*l2*cos(t));
		printf("%.2lf",l3);
	}
	return 0;
}
