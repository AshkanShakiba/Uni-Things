#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int numbers,digits;
void runTheGame(int numbers,int digits);
int tenPow(int n){
	int i,s=1;
	for(i=1;i<=n;i++){
		s=s*10;
	}
	return s;
}
int menu(){
	char choice;
	printf("1)Continue\n2)Increase numbers\n3)Increase digits\n4)End\n");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice){
		case '1':
			runTheGame(numbers,digits);
			break;
		case '2':
			numbers++;
			runTheGame(numbers,digits);
			break;
		case '3':
			digits++;
			runTheGame(numbers,digits);
			break;
		case '4':
			return 0;
	}
}
void runTheGame(int numbers,int digits){
	int j,i,k,num[numbers],input,p;
	for(j=1;j<=5;j++){
		double correctAnswers=0;
		for(i=0;i<numbers;i++){
			num[i]=(rand()%(tenPow(digits)-tenPow(digits-1)))+tenPow(digits-1);
			printf("%d ",num[i]);
		}
		printf("\n");
		for(i=0;i<numbers;i++){
			p=0;
			scanf("%d",&input);
			for(k=0;k<numbers;k++){
				if(input==num[k]){
					p=1;
				}
			}
			if(p){
				printf("Correct :) :D\n");
				correctAnswers++;
			}
			else{
				printf("Incorrect :( :P\n");
			}
		}
		printf("%lf\n",correctAnswers/numbers);
	}
	menu();
}
int main(){
	time_t t=time(NULL);
	srand(t);

	scanf("%d %d",&numbers,&digits);
	runTheGame(numbers,digits);
}
