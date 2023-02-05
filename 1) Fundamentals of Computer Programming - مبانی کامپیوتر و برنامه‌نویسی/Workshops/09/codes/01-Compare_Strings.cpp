#include <stdio.h>
int cmpStr(char x[],char y[]){
	int p=1,i=0;
	while(x[i]!='\0' && y[i]!='\0'){
		if(x[i]!=y[i]){
			p=0;
		}
		i++;
	}
	return p;
}
int main(){
	char a[1001],b[1001];
	gets(a);
	gets(b);
	switch(cmpStr(a,b)){
		case 1:
			printf("Same!");
			break;
		case 0:
			printf("Different!");
	}
	return 0;
}
