#include <stdio.h>
int n,i;
int next(int j){
	if(j==n-1)
		return 0;
	return j+1;
}
int alive(char a[]){
	int j,r=0;
	for(j=0;j<n;j++){
		if(a[j]=='+') r++;
	}
	return r;
}
int surviver(){
	char a[n];
	int j,k;
	for(j=0;j<n;j++){
		a[j]='+';
	}
	j=0;
	while(alive(a)>1){
		a[j]='-';
		for(k=0;k<i+1;k++){
			while(a[next(j)]=='-'){
				j=next(j);
			}
			j=next(j);
		}
	}
	return j;
}
int main(){
	scanf("%d%d",&n,&i);
	printf("%d",surviver());
}
