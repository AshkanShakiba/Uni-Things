#include <stdio.h>
int fact(int x){
	if(x==1)
		return 1;
	return x*fact(x-1);
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",fact(n+1)%k);
	return 0;
}
