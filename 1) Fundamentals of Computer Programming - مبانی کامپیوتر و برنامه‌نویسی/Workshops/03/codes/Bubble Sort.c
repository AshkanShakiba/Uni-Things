#include <stdio.h>
int main(){
	int n,i,j,a[999],tmp;
	printf("How many numbers do you have?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter number #");
		printf("%d\n",i+1);
		scanf("%d",&a[i]);
	}
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	printf("The sorted list is:\n");
	for(i=0;i<n-1;i++){
		printf("%d,",a[i]);
	}
	printf("%d",a[n-1]);
	return 0;
}
//By Ashkan Shakiba
