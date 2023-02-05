#include <stdio.h>
#include <stdlib.h>
struct ww{
	char code[101],phone[101];
	struct ww *prev,*next;
};
struct ww *head,*end;
int menu(){
	int choice;
	printf("1) Add\n2) Remove\n3) List\n4) Quit\n");
	scanf("%d",&choice);
	return choice;
}
void add(){
	struct ww *curr;
	curr=(struct ww *)(malloc(sizeof(struct ww)));
	printf("No: ");
	scanf("%s",curr->code);
	printf("Phone: ");
	scanf("%s",curr->phone);
	if(head==NULL){
		head=curr;
	}
	else{
		end->next=curr;
		curr->prev=end;
	}
	end=curr;
}
void remove1(){
	int removed=0;
	char code[101];
	struct ww *curr;
	printf("No: ");
	scanf("%s",code);
	if(head!=NULL){
		curr=head;
		while(curr!=end){
			if(strcmp(curr->code,code)==0){
				if(curr==head){
					head=curr->next;
					free(curr);
					removed=1;
				}
				else{
					(curr->prev)->next=curr->next;
					(curr->next)->prev=curr->prev;
					free(curr);
					removed=1;
				}
			}
			curr=curr->next;
		}
		if(strcmp(curr->code,code)==0){
			if(curr==head){
				head=NULL;
			}
			else{
				end=curr->prev;
			}
			free(curr);
			removed=1;
		}
	}
	if(removed){
		printf("%s has been removed\n",code);
	}
	else{
		printf("%s does not exist\n",code);
	}
}
void list(){
	int i=1;
	struct ww *curr;
	if(head!=NULL){
		curr=head;
		while(curr!=end){
			printf("%d)\n",i);
			printf("No: %s\n",curr->code);
			printf("Phone: %s\n",curr->phone);
			curr=curr->next;
			i++;
		}
		printf("%d)\n",i);
		printf("No: %s\n",curr->code);
		printf("Phone: %s\n",curr->phone);
	}
}
void invalid(){
	printf("Invalid input, try again\n");
}
int main(){
	int choice;
	head=NULL;
	while(1){
		choice=menu();
		switch(choice){
			case 1:
				add();
				break;
			case 2:
				remove1();
				break;
			case 3:
				list();
				break;
			case 4:
				return 0;
				break;
			//default:
				//invalid();	
		}
	}
}
