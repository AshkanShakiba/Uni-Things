#include <stdio.h>
int isLucky(int n){
	while(n>0){
		if(n%10!=4 && n%10!=7){
			return 0;
		}
		n=n/10;
	}
	return 1;
}
int isNeighbor(int n){
	int t=0;
	while(n>0){
		if(n%10==4 || n%10==7){
			t++;
		}
		n=n/10;
	}
	if(isLucky(t)){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	if(isNeighbor(n)){
		printf("Yes it\'s a neighbor");
	}
	else{
		printf("No it\'s not a neighbor");
	}
}
