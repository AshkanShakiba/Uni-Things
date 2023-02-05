#include <stdio.h>
int main(){
	int x,y,m,i;
	scanf("%d%d",&x,&y);
	if(x>y){
		m=x;
	}
	else{
		m=y;
	}
	for(i=2;i<=m;i++){
		if(x%i==y%i){
			printf("%d\n",i);
		}
	}
	return 0;
}
