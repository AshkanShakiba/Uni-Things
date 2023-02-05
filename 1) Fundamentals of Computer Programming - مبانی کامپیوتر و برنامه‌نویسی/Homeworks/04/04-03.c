#include <stdio.h>
#include <string.h>
char upper(char c){
	if(c>=97 && c<=122){
		return c-32;
	}
	else{
		return c;
	}
}
char lower(char c){
	if(c>=65 && c<=90){
		return c+32;
	}
	else{
		return c;
	}
}
int main(){
	int n,i,j;
	char fn[11][1001];
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		gets(fn[i]);
		fn[i][0]=upper(fn[i][0]);
		j=1;
		while(j<=strlen(fn[i])){	
			if(fn[i][j]==' '){
				fn[i][j+1]=upper(fn[i][j+1]);
				j=j+2;
			}
			else{
				fn[i][j]=lower(fn[i][j]);
				j++;
			}
		}
	}
	for(i=1;i<=n;i++){
		puts(fn[i]);
	}
	return 0;
}
