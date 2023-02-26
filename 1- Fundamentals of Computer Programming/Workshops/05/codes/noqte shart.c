#include <stdio.h>
#include <math.h>
int main(){
	double x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	
	double d12,d13,d14,d23,d24,d34;
	d12=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	d13=sqrt(pow((x1-x3),2)+pow((y1-y3),2));
	d14=sqrt(pow((x1-x4),2)+pow((y1-y4),2));
	d23=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	d24=sqrt(pow((x2-x4),2)+pow((y2-y4),2));
	d34=sqrt(pow((x3-x4),2)+pow((y3-y4),2));
	
	if((y2-y1)/(x2-x1)==(y3-y2)/(x3-x2) && (y3-y2)/(x3-x2)==(y4-y3)/(x4-x3)){
		printf("All in one line");
	}	
	
	else if((y2-y1)/(x2-x1)==(y3-y2)/(x3-x2)){ //1,2,3
		printf("Three in one line");
	}
	else if((y2-y1)/(x2-x1)==(y4-y2)/(x4-x2)){ //1,2,4
		printf("Three in one line");
	}
	else if((y2-y4)/(x2-x4)==(y3-y2)/(x3-x2)){ //2,3,4
		printf("Three in one line");
	}
	
	else if(d12==d23 && d23==d34 && d34==d14){
		printf("Diamond");
	}
	else if(d13==d34 && d34==d24 && d24==d12){
		printf("Diamond");
	}
	else if(d14==d24 && d24==d23 && d23==d13){
		printf("Diamond");
	}
	
	else{
		printf("None");
	}
}
