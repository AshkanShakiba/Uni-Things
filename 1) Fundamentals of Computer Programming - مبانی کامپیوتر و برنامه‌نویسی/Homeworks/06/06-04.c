#include <stdio.h>
#include <stdlib.h>
struct fig{
	int power;
	struct fig *pointer;
};
int main(){
	int input=0,moved;
	struct fig *firstFig,*lastFig,*firstFig1,*lastFig1,*firstFig2,*lastFig2,*current,*current1,*current2;
	struct fig *currentS,*currentN,*previous,*prevoius1,*previous2,*previousS;
	firstFig1=lastFig1=current=previous=NULL;
	while(input!=-1){
		scanf("%d",&input);
		if(input!=-1){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->power=input;
			if(firstFig1==NULL){
				firstFig1=current;
			}
			else{
				previous->pointer=current;
			}
			previous=current;
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
			current->power=input;
			if(firstFig2==NULL){
				firstFig2=current;
			}
			else{
				previous->pointer=current;
			}
			previous=current;
		}
		else{
			lastFig2=previous;
		}
	}
	current1=firstFig1;
	current2=firstFig2;
	firstFig=lastFig=current=previous=NULL;
	while(current1!=lastFig1 && current2!=lastFig2){
		current=(struct fig *)(malloc(sizeof(struct fig)));
		if(current1->power>current2->power){
			current->power=current1->power;
			current1=current1->pointer;
		}
		else{
			current->power=current2->power;
			current2=current2->pointer;
		}
		if(firstFig==NULL){
			firstFig=current;
		}
		else{
			previous->pointer=current;
		}
		previous=current;
	}
	moved=0;
	previousS=NULL;
	if(current1==lastFig1){
		currentS=firstFig2;
		while(currentS!=lastFig2 && moved==0){
			if(currentS->power<current1->power){
				if(previousS==NULL){
					currentN=(struct fig *)(malloc(sizeof(struct fig)));
					currentN->power=current1->power;
					currentN->pointer=firstFig2;
					firstFig2=currentN;
					moved=1;
				}
				else{
					currentN=(struct fig *)(malloc(sizeof(struct fig)));
					currentN->power=current1->power;
					currentN->pointer=previousS->pointer;
					previousS->pointer=currentN;
					moved=1;
				}
			}
			previousS=currentS;
			currentS=currentS->pointer;
		}
		if(moved==0){
			if(currentS->power<current1->power){
				currentN=(struct fig *)(malloc(sizeof(struct fig)));
				currentN->power=current1->power;
				currentN->pointer=previousS->pointer;
				previousS->pointer=currentN;
			}
			else{
				currentN=(struct fig *)(malloc(sizeof(struct fig)));
				currentN->power=current1->power;
				currentS->pointer=currentN;
				lastFig2=currentN;
			}
		}
	}
	if(current2==lastFig2){
		currentS=firstFig1;
		while(currentS!=lastFig1 && moved==0){
			if(currentS->power<current2->power){
				if(previousS==NULL){
					currentN=(struct fig *)(malloc(sizeof(struct fig)));
					currentN->power=current2->power;
					currentN->pointer=firstFig1;
					firstFig1=currentN;
				}
				else{
					currentN=(struct fig *)(malloc(sizeof(struct fig)));
					currentN->power=current2->power;
					currentN->pointer=previousS->pointer;
					previousS->pointer=currentN;
				}
				moved=1;
			}
			previousS=currentS;
			currentS=currentS->pointer;
		}
		if(moved==0){
			if(currentS->power<current2->power){
				currentN=(struct fig *)(malloc(sizeof(struct fig)));
				currentN->power=current2->power;
				currentN->pointer=previousS->pointer;
				previousS->pointer=currentN;
			}
			else{
				currentN=(struct fig *)(malloc(sizeof(struct fig)));
				currentN->power=current2->power;
				currentS->pointer=currentN;
				lastFig1=currentN;
			}
		}
	}
	if(current1!=lastFig1){
		if(current1->power<currentN->power){
			current1=currentN;
		}
		while(current1!=lastFig1){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->power=current1->power;
			current1=current1->pointer;
			previous->pointer=current;
			previous=current;
		}
		current=(struct fig *)(malloc(sizeof(struct fig)));
		current->power=current1->power;
		previous->pointer=current;
		previous=current;
	}
	if(current2!=lastFig2){
		if(current2->power<currentN->power){
			current2=currentN;
		}
		while(current2!=lastFig2){
			current=(struct fig *)(malloc(sizeof(struct fig)));
			current->power=current2->power;
			current2=current2->pointer;
			previous->pointer=current;
			previous=current;
		}
		current=(struct fig *)(malloc(sizeof(struct fig)));
		current->power=current2->power;
		previous->pointer=current;
		previous=current;
	}
	lastFig=current;
	current=firstFig;
	while(current!=lastFig){
		printf("%d ",current->power);
		current=current->pointer;
	}
	printf("%d",current->power);
	return 0;
}
