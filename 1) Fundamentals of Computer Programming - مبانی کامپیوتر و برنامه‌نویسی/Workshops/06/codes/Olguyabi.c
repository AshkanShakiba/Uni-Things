#include <stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			printf("%d",j);
		}
		if(i==n){
			printf("\b");
		}
		for(j=1;j<2*(n-i);j++){
			printf(" ");	
		}
		for(j=i;j>=1;j--){
			printf("%d",j);	
		}
		printf("\n");
	}
}
