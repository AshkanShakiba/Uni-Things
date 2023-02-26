#include <stdio.h>
#include <math.h>
int main(){
	int n;
	double i,sltr=0,srtl=0;
	scanf("%d",&n);
	for(i=1;i<=pow(2,n);i++){
		sltr=sltr+1/i;
	}
	for(i=pow(2,n);i>=1;i--){
		srtl=srtl+1/i;
	}
	printf("Sum (left to right) = %lf\nSum (right to left) = %lf",sltr,srtl);
}
