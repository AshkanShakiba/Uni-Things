#include <stdio.h>
int max(int a[],int s,int e){
	// s = start; e = end;
	int i,max;
	max=s;
	for(i=s+1;i<=e;i++){
		if(a[i]>a[max]){
			max=i;
		}
	}
	return max;
}
int main(){
	int n,i,a[999],tmp;
	printf("How many numbers do you have?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter number #");
		printf("%d\n",i+1);
		scanf("%d",&a[i]);
	}
	for(i=n;i>0;i--){
		tmp=a[i];
		a[i]=a[max(a,0,i)];
		a[max(a,0,i)]=tmp;
	}
	printf("The sorted list is:\n");
	for(i=0;i<n-1;i++){
		printf("%d,",a[i]);
	}
	printf("%d",a[n-1]);
	return 0;
}
//By Ashkan Shakiba
