#include <stdio.h>
char changeCase(char c){
	if(c>=65 && c<=90){
		return c+32;
	}
	if(c>=97 && c<=122){
		return c-32;
	}
}
int main(){
	int n;
	char ci,co;
	scanf("%d",&n);
	scanf("%c",&ci);
	scanf("%c",&ci);
	co=ci+n;
	printf("%c, %c",co,changeCase(co));
	return 0;
}
