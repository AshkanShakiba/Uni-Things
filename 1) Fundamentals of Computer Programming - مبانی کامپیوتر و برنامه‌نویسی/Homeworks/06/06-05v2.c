#include <stdio.h>
#include <stdlib.h>
int main(){
	int input,*array1,i1=1,*array2,i2=1,*array3,i3=1,c1,c2=1,c3=0,done=0;
	scanf("%d",&input);
	array1=(int *)(malloc(sizeof(int)));
	array1[0]=input;
	while(input!=-1){
		scanf("%d",&input);
		if(input!=-1){
			array1=(int *)(realloc(array1,(i1+1)*sizeof(int)));
			array1[i1]=input;
			i1++;
		}
	}
	scanf("%d",&input);
	array2=(int *)(malloc(sizeof(int)));
	array2[0]=input;
	while(input!=-1){
		scanf("%d",&input);
		if(input!=-1){
			array2=(int *)(realloc(array2,(i2+1)*sizeof(int)));
			array2[i2]=input;
			i2++;
		}
	}
	scanf("%d",&input);
	array3=(int *)(malloc(sizeof(int)));
	array3[0]=input;
	while(input!=-1){
		scanf("%d",&input);
		if(input!=-1){
			array3=(int *)(realloc(array3,(i3+1)*sizeof(int)));
			array3[i3]=input;
			i3++;
		}
	}
	for(c1=0;c1<i1;c1++){
		if(array1[c1]==array2[0] && done==0){
			array1[c1]=-1;
			done=1;
		}
		if(c2<i2 && array1[c1]==array2[c2]){
			array1[c1]=-11;
			c2++;
		}
	}
	for(c1=0;c1<i1;c1++){
		if(array1[c1]>0){
			printf("%d ",array1[c1]);
		}
		if(array1[c1]==-1){
			for(c3=0;c3<i3;c3++){
				printf("%d ",array3[c3]);
			}
		}
	}
	return 0;
}
