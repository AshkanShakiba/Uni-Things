#include <stdio.h>
#include <math.h>
int main(){
	int x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	/*
	x4=x2+x3-x1;
	y4=y2+y3-y1;
	if(((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1))==((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))){
		printf("%d %d",x4,y4);
		return 0;
	}
	*/
	x4=x1+x3-x2;
	y4=y1+y3-y2;
	if(((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2))==((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))){
		printf("%d %d",x4,y4);
		return 0;
	}
	/*
	x4=x1+x2-x3;
	y4=y1+y2-y3;
	if(((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))==((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))){
		printf("%d %d",x4,y4);
		return 0;
	}
	*/
	printf("Not Possible");
	return 0;
}
