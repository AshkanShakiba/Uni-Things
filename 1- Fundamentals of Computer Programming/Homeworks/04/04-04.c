#include <stdio.h>
#include <string.h>
int adad(char c){
	return c-48;
}
int main(){
	char s[101];
	int i,j;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		printf("%c: ",s[i]);
		for(j=0;j<adad(s[i]);j++){
			printf("%c",s[i]);
		}
		printf("\n");
	}
}
