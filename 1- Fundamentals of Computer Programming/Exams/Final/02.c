#include <stdio.h>
int * intersection(int *a, int size_a, int *b, int size_b, int *size_result){
	int i,j,k=0;
	static int res[10001];
	for(i=0;i<size_a;i++){
		for(j=0;j<size_b;j++){
			if(a[i]==b[j]){
				res[k]=a[i];
				k++;
				break;
			}
		}
	}
	*size_result=k;
	return res;
}
int main(){
	int m,n,i,j,size;
	scanf("%d%d",&m,&n);
	int a[m],b[n],*inp;
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	inp=intersection(a,m,b,n,&size);
	int in[size];
	for(i=0;i<size;i++){
		in[i]=inp[i];
	}
	for(i=0;i<m;i++){
		printf("%d ",a[i]);
	}
	for(i=0;i<n;i++){
		int isDiff=1;
		for(j=0;j<size;j++){
			if(b[i]==in[j]){
				isDiff=0;
			}
		}
		if(isDiff){
			printf("%d ",b[i]);
		}
	}
	return 0;
}
