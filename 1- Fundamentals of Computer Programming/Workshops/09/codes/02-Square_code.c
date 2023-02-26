#include <stdio.h>
#include <string.h>
int normalize(char str1[],char str2[]){
    int i=0,j=0;
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]>=65&&str1[i]<=90){
            str2[j]=str1[i]+32;
            j++;
        }
        else if(str1[i]>=97&&str1[i]<=122){
            str2[j]=str1[i];
            j++;
        }
    }
    str2[j]='\0';
    return j;
}
void square(char s1[],char s2[]){
	strcpy(s2,"");
	int c=1,r=1,i,j;
	while(c*r<strlen(s1)){
		c++;
		if(c*r<strlen(s1)){
			r++;
		}
	}
	for(i=0;i<c;i++){
		for(j=i;j<strlen(s1);j+=c){
			char ss[1];
			ss[0]=s1[j];
			strncat(s2,ss,1);
		}
		char ss[1];
		ss[0]='!';
		strncat(s2,ss,1);
	}
}
int main(){
	char s1[1001],s2[1001],s3[1001];
	gets(s1);
	normalize(s1,s2);
	square(s2,s3);
	printf("%s",s3);
	return 0;
}
