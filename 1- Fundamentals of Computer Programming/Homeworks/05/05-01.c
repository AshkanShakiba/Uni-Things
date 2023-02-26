#include <stdio.h>
char o[24][60][4001];
int main(){
	char sp[111],op;
	int n,i,j,h,m,k=0,c=0,mx=0;
	scanf("%d",&n);
	n=n*2;
	for(i=0;i<n;i++){
		fflush(stdin);
		scanf("%*s");
		scanf("%d:%d %c",&h,&m,&op);
		o[h][m][k]=op;
		k++;
	}
	for(i=0;i<24;i++){
		for(j=0;j<60;j++){
			for(k=0;k<4001;k++){
				switch(o[i][j][k]){
					case '+':
						c++;
						break;
					case '-':
						c--;
				}
			}
			if(c>mx){
				mx=c;
				h=i;
				m=j;
			}
		}
	}
	printf("%02d:%02d",h,m);
}
