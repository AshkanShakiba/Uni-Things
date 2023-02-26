#include <stdio.h>
#include <string.h>
int key(char* msg){
	return 83-msg[0];
}
char cnvrt(char c,int k){
	if(64<c && c<91){
		if(c+k<65)
			return c+k+26;
		if(64<c+k && c+k<91)
			return c+k;
		if(90<c+k)
			return c+k-26;
	}
	if(96<c && c<123){
		if(c+k<97)
			return c+k+26;
		if(96<c+k && c+k<123)
			return c+k;
		if(122<c+k)
			return c+k-26;
	}
	return c;
}
char* decode(char* msg,int key){
	int i;
	static char res[2001];
	for(i=0;i<strlen(msg);i++){
		res[i]=cnvrt(msg[i],key);
	}
	res[i]='\0';
	return res;
}
int main(){
	char msg[2001];
	gets(msg);
	puts(decode(msg,key(msg)));
}
