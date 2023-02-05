#include <stdio.h>
#include <string.h>
int replacer(char *s2,char *s1,char *f,char *r){
	int res_index = 0;
	char *index;
	while((index = strstr(s1, f)) != NULL){
		int len = index - s1;
		if(len > 0){
			strncat(s2, s1, len);
			res_index++;
		}
		strcat(s2, r);
		s1 = index + strlen(f);
	}
	if(strlen(s1) > 0){
		strcat(s2, s1);
		res_index++;
	}
	return res_index;
}
int main(){
	int i;
	char s1[1111],s2[1111],f[111],r[111];
	printf("Please Enter any String: ");
	gets(s1);
	printf("\nPlease Enter the word that you want to Search for: ");
	gets(f);
	printf("\nPlease Enter the New Word: ");
	gets(r);
	replacer(s2,s1,f,r);
	printf("\nThe Final String after Replacing All Occurrences of \"%s\" with \"%s\":\n\n%s",f,r,s2);
	return 0;
}
