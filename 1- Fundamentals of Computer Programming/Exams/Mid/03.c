#include <stdio.h>
#include <math.h>
int check_right_left_digits(int num){
	int r,c,td=0,n=num;
	while(n>0){
		td++;
		n=n/10;
	}
	if(td==1){
		return 0;
	}
	r=num%10;
	c=num/pow(10,td-1);
	if(c!=r){
		return -1;
	}
	n=num-c*pow(10,td-1);
	n=n/10;
	return n;
}
int isMotaqaren(int num){
	int p=1,i,td=0,m,n;
	m=n=num;
	while(n>0){
		td++;
		n=n/10;
	}
	for(i=1;i<=td/2;i++){
		if((int)(m/pow(10,i-1))%10==0){
			if((int)(m/pow(10,td-i))%10!=0){
				p=0;
			}
		}
		if((int)(m/pow(10,td-i))%10==0){
			if((int)(m/pow(10,i-1))%10!=0){
				p=0;
			}
		}
	}
	n=num;
	while(n>0){
		n=check_right_left_digits(n);
	}
	if(n==0 && p)
		return 1;
	return 0;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		if(isMotaqaren(i)){
			printf("%d\n",i);
		}
	}
	return 0;
}
