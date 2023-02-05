#include <stdio.h>
int f(int n){
	int i,w=1,j=4,t=1;
	while(w<n){
		t++;
		w=w+j;
		j=j+2;
	}
	if(w==n)
		return t;
	return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
}
