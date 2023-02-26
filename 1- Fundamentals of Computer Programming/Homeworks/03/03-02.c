#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	time_t t = time(NULL);
	srand(t);
	
	int x,rndm,bargoals=40,boxgoals=40;
	
	printf("Enter x\n");
	scanf("%d",&x);
	while(x>100 || x<0){
		printf("Invalid! it must be between 0 and 100; Enter x again\n");
		scanf("%d",&x);
	}
	
	rndm=rand()%100;
	
	if(rndm<=x){
		//Barvard is the winner!
		bargoals=rand()%39+1;
		while(boxgoals>bargoals){
			boxgoals=rand()%39;
		}
		if(x==100){
			while(boxgoals>=bargoals){
				boxgoals=rand()%39;
			}
		}
	}
	else{
		//Boxford is the winner!
		boxgoals=rand()%39+1;
		while(bargoals>boxgoals){
			bargoals=rand()%39;
		}
		if(x==0){
			while(bargoals>=boxgoals){
				bargoals=rand()%39;
			}
		}
	}
	
	printf("BAR %d - %d BOX",bargoals,boxgoals);
}
