#include <stdio.h>
int main(){
	int n,m,p,q,i,j,k,a;
	printf("Enter n,m,p and q\n");
	scanf("%d%d%d%d",&n,&m,&p,&q);
	int A[n][m],B[p][q],AB[n][q];
	if(m!=p){
		printf("Invalid!");
		return 0;
	}
	printf("------\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("------\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&B[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			a=0;
			for(k=0;k<m;k++){
				a=a+A[i][k]*B[k][j];
			}
			AB[i][j]=a;
		}
	}
	printf("------\n");
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			printf("%d ",AB[i][j]);
		}
		printf("\n");
	}
	return 0;
}
