#include <stdio.h>
int isPrime(int x){
	if(x==1 || x==0)
		return 0;
	int i;
	for(i=2;i<x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int tvn(int n){
	int i,s=1;
	for(i=1;i<=n;i++){
		s=s*10;
	}
	return s;
}
int isSuperPrime(int num){
	int td=0,n=num,i;
	while(n>0){
		td++;
		n=n/10;
	}
	for(i=1;i<=td;i++){
		if(!isPrime(num%tvn(i)))
			return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	if(isSuperPrime(n)){
		printf("Yes! it's super prime!");
	}
	else{
		printf("No! it's not super prime!");
	}
}
