#include <stdio.h>
int absv(int x){
	if(x>=0)
		return x;
	return -x;
}
int main(){
	int n,i,j,s,min,ai=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		s=0;
		for(j=0;j<n;j++){
			s+=absv(i-j)*a[j];
		}
		if(i==0){
			min=s;
		}
		if(s<min){
			min=s;
			ai=i;
		}
	}
	printf("%d",ai+1);
	return 0;
}
