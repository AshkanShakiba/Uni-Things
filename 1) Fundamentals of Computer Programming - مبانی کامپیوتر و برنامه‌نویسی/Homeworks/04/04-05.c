#include <stdio.h>
int main(){
    unsigned long long int a,k,n,r=1;
    scanf("%llu%llu",&n,&k);
    for(a=n+1;a>0;a--){
        r=r*a;
        r=r%k;
    }
    if(r==0){
    	printf("%llu",k);
    }
   	else{
	   printf("%llu",r);
   	}
    return 0;
}
