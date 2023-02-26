#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c,d,e,f; // input: [a,b], [c,d], [e,f]
	double y,z; //output: [y,z]
	scanf("%lf%lf",&a,&b);
	scanf("%lf%lf",&c,&d);
	scanf("%lf%lf",&e,&f);
	
	if(a>=c && a>=e){
		y=a;
	}
	else if(c>=a && c>=e){
		y=c;
	}
	else if(e>=a && e>=c){
		y=e;
	}
	
	if(b<=d && b<=f){
		z=b;
	}
	else if(d<=b && d<=f){
		z=d;
	}
	else if(f<=b && f<=d){
		z=f;
	}
	
	if(z>=y){
		printf("Result=[%lf,%lf]",y,z);
	}
	else{
		printf("Sorry! your input is invalid");	
	}
}
