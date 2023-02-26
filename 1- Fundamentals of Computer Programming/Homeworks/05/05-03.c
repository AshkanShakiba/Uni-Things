#include <stdio.h>
#include <string.h>
int isMeaningful(char bw[],char wi[]){
	int i,j=0;
	for(i=0;i<strlen(bw);i++){
		while(bw[i]!=wi[j]){
			if(j<strlen(wi)-1){
				j++;
			}
			else{
				return 0;
			}
		}
		j++;
	}
	return 1;
}
int main(){
	char bw[51];
	int n,i,t=0;
	scanf("%s",bw);
	scanf("%d",&n);
	char w[n][51];
	for(i=0;i<n;i++){
		scanf("%s",w[i]);
		if(isMeaningful(bw,w[i])){
			t++;
		}
	}
	printf("%d",t);
}
