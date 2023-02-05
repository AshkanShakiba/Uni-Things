#include <stdio.h>
#include <stdlib.h>
struct fig{
	int number;
	struct fig *pointer;
};
int main(){
	int input=0,quotient=0;
	struct fig *firstFig,*lastFig,*firstFig1,*lastFig1,*firstFig2,*lastFig2,*current,*current1,*current2,*previous,*prevoius1,*previous2;
	firstFig1=lastFig1=current=previous=NULL;
	while(input!=-1){
		scanf("%d",&input);
		if(input!=-1){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->number=input;
			current->pointer=previous;
			previous=current;
			if(firstFig1==NULL){
				firstFig1=current;
			}
		}
		else{
			lastFig1=previous;
		}
	}
	input=0;
	firstFig2=lastFig2=current=previous=NULL;
	while(input!=-1){
		scanf("%d",&input);
		if(input!=-1){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->number=input;
			current->pointer=previous;
			previous=current;
			if(firstFig2==NULL){
				firstFig2=current;
			}
		}
		else{
			lastFig2=previous;
		}
	}
	current1=lastFig1;
	current2=lastFig2;
	firstFig=lastFig=current=previous=NULL;
	while(current1!=firstFig1 && current2!=firstFig2){
		current=(struct fig *)(malloc(sizeof(struct fig)));
		current->number=(current1->number+current2->number+quotient)%10;
		quotient=(current1->number+current2->number+quotient)/10;
		current->pointer=previous;
		previous=current;
		if(lastFig==NULL){
			lastFig=current;
		}
		current1=current1->pointer;
		current2=current2->pointer;
	}
	current=(struct fig *)(malloc(sizeof(struct fig)));
	current->number=(current1->number+current2->number+quotient)%10;
	quotient=(current1->number+current2->number+quotient)/10;
	current->pointer=previous;
	previous=current;
	if(current1!=firstFig1){
		current1=current1->pointer;
		while(current1!=firstFig1){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->number=(current1->number+quotient)%10;
			quotient=(current1->number+quotient)/10;
			current->pointer=previous;
			previous=current;
			current1=current1->pointer;
		}
		current=(struct fig *)(malloc(sizeof(struct fig)));
		current->number=(current1->number+quotient)%10;
		quotient=current1->number/10;
		current->pointer=previous;
	}
	if(current2!=firstFig2){
		current2=current2->pointer;
		while(current2!=firstFig2){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->number=(current2->number+quotient)%10;
			quotient=(current2->number+quotient)/10;
			current->pointer=previous;
			previous=current;
			current2=current2->pointer;
		}
		current=(struct fig *)(malloc(sizeof(struct fig)));
		current->number=(current2->number+quotient)%10;
		quotient=current2->number/10;
		current->pointer=previous;
	}
	if(quotient>0){
		current=(struct fig *)(malloc(sizeof(struct fig)));
		current->number=quotient;
		current->pointer=previous;
		previous=current;
	}
	firstFig=current;
	while(current!=lastFig){
		printf("%d ",current->number);
		current=current->pointer;
	}
	printf("%d",current->number);
	return 0;
}
