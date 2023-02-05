#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tenPow(int n){
	int i,s=1;
	for(i=1;i<=n;i++){
		s=s*10;
	}
	return s;
}
void runTheGame(int numbers,int digits){
	int j,i,num[numbers],input;
	for(j=1;j<=5;j++){
		double correctAnswers=0;
		for(i=0;i<numbers;i++){
			num[i]=(rand()%(tenPow(digits)-tenPow(digits-1)))+tenPow(digits-1);
			printf("%d ",num[i]);
		}
		printf("\n");
		for(i=0;i<numbers;i++){
			scanf("%d",&input);
			if(input==num[i]){
				printf("Correct :) :D\n");
				correctAnswers++;
			}
			else{
				printf("Incorrect :( :P\n");
			}
		}
		printf("%.2lf\n",correctAnswers/numbers);
	}
}
char menu(){
	char choice;
	printf("1)Continue\n2)Increase numbers\n3)Increase digits\n4)End\n");
	fflush(stdin);
	scanf("%c",&choice);
	return choice;
}
int main(){
	time_t t=time(NULL);
	srand(t);

	char choice;
	int numbers,digits;
	scanf("%d%d",&numbers,&digits);
	runTheGame(numbers,digits);
	while(1){
		choice=menu();
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
}
// it works, but I can't improve 33 -_-
