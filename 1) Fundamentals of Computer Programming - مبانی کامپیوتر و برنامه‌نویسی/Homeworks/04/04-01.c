#include <stdio.h>
void removeEnter(){
	char c;
	scanf("%c",&c);
}
int main(){
	int n,i,t=0,s;
	scanf("%d",&n);
	//removeEnter();
	fflush(stdin);
	//char yf[n],ys[n];
	char yf[n],ys[n];
	/*for(i=0;i<n;i++){
		yf[i]=getchar();
		//printf("yf[%d]=%c\n",i,yf[i]);
	}*/
	fgets(yf,sizeof(yf)+1,stdin);
	/*for(i=0;i<n;i++){
		printf("yf[%d]=%c\n",i,yf[i]);
	}*/
	//removeEnter();
	fflush(stdin);
	/*for(i=0;i<n;i++){
		ys[i]=getchar();
		//printf("ys[%d]=%c\n",i,ys[i]);
	}*/
	fgets(ys,sizeof(ys)+1,stdin);
	/*for(i=0;i<n;i++){
		printf("ys[%d]=%c\n",i,ys[i]);
	}*/
	for(i=0;i<n-1;i++){
		if(yf[i]!=ys[i]){
			t++;
			if(yf[i+1]!=ys[i+1] && yf[i]!=yf[i+1]){
				i++;
			}
		}
	}
	if(i<n){
		if(yf[i]!=ys[i]){
			t++;
		}
	}
	printf("%d",t);
	return 0;
}
