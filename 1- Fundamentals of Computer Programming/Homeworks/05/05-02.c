#include <stdio.h>
int negOnePow(int x){
	if(x%2)
		return -1;
	return 1;
}
void newM(int n,int i,int a[][n],int b[][n-1]){
	int j,k,l=0,m=0;
	for(k=1;k<n;k++){
		for(j=0;j<n;j++){
			if(j!=i){
				b[l][m]=a[k][j];
				m++;
				if(m+1==n){
					m=0;
					l++;
				}
			}
		}
	}
}
long long int det(int n,int a[][n]){
	if(n==1)
		return a[0][0];
	int i,b[n-1][n-1];
	long long int s=0;
	for(i=0;i<n;i++){
		newM(n,i,a,b);
		s=s+negOnePow(i)*a[0][i]*det(n-1,b);
	}
	return s;
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	int m[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&m[i][j]);
		}
	}
	printf("%lld",det(n,m));
	return 0;
}
