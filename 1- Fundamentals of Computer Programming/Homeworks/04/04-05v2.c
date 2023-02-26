#include <stdio.h>
int main(){
	int i;
	unsigned long long int n,k,f=1;
	scanf("%llu%llu",&n,&k);
	for(i=1;i<=n+1;i++){
		f=f*i;
	}
	printf("%llu",f%k);
	return 0;
}
