#include <stdio.h>
#include <math.h>
double F(int n){
	return (pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5);
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%.0lf",F(n));
	return 0;
}
