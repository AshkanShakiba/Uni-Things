#include <stdio.h>
int nextint(double x){
	if((int)x==x)
		return x;
	return (int)x+1;
}
int main(){
	double n,m,a;
	scanf("%lf%lf%lf",&n,&m,&a);
	printf("%d",nextint(n/a)*nextint(m/a));
}
