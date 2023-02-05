#include <stdio.h>
void m(int n){
	if(n>2){
		int i;
		m(n/2);
		printf("\n");
		m(n/2);
		m(n/2);
	}
	else{
		printf(" *\n* *");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	m(n);
}
