#include <stdio.h>
#include <stdlib.h>
struct item{
	int number;
	struct item *pointer;
};
int main(){
	int input=1;
	struct item *head,*end,*previous,*current;
	head=end=previous=NULL;
	while(input!=0){
		scanf("%d",&input);
		if(input>0){
			current=(struct item *)(malloc(sizeof(struct item)));
			current->number=input;
			current->pointer=previous;
			previous=current;
			if(head==NULL){
				head=current;
			}
		}
		else{
			end=previous;
		}
	}
	current=end;
	while(current!=head){
		printf("%d ",current->number);
		current=current->pointer;
	}
	printf("%d",current->number);
	return 0;
}
