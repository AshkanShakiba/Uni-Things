#include <stdio.h>
#include <math.h>
int main(){
	int r;
	char cc;
	double sin=2,cos;
	while(sin>1 || sin<-1){
		printf("sin?\n");
		scanf("%lf",&sin);
	}
	scanf("%c",&cc); //only for Enter char
	while(cc!='+' && cc!='-'){
		printf("cos is + or -?\n");
		scanf("%c",&cc);	
	}
	switch(cc){
		case '+':
			cos=sqrt(1-pow(sin,2));
			printf("cos = %lf\n",cos);
			if(sin==0 || cos==0){
				printf("Border");
			}
			else if(sin>0){
				printf("First");
			}
			else{
				printf("Fourth");	
			}
			break;
			
		case '-':
			cos=-sqrt(1-pow(sin,2));
			printf("cos = %lf\n",cos);
			if(sin==0 || cos==0){
				printf("Border");
			}
			else if(sin>0){
				printf("Second");
			}
			else{
				printf("Third");	
			}
			break;
	}
}
