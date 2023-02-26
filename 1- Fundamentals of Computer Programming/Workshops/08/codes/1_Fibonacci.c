#include <stdio.h>
int fibA[10001];
int fibF(int n){
	if(fibA[n]!=0){
		return fibA[n];
	}
	else{
		return fibF(n-2)+fibF(n-1);
	}
}
int main(){
	int i,n=1;
	for(i=0;i<10001;i++){
		if(i<3){
			fibA[i]=1;
		}
		else{
			fibA[i]=0;
		}
	}
	while(n!=0){
		scanf("%d",&n);
		if(n>0){
			printf("fibonacci[%d]: %d\n",n,fibF(n));
		}	
	}
	return 0;
}
