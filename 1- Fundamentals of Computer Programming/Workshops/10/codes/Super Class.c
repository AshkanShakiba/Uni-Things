#include <stdio.h>
#include <stdlib.h>
struct student{
	int id;
	char name[999];
	int age;
	char address[9999];
};
struct listItem{
	struct student std;
	struct listItem *nextStd;
};
void getStudent(struct student *std){
	printf("Enter student's id\n");
	fflush(stdin);
	scanf("%d",&(std->id));
	printf("Enter student's name\n");
	fflush(stdin);
	gets(std->name);
	printf("Enter student's age\n");
	fflush(stdin);
	scanf("%d",&(std->age));
	printf("Enter student's address\n");
	fflush(stdin);
	gets(std->address);
}
void putStudent(struct student std){
	printf("student's id: %d\n",std.id);
	printf("student's name: %s\n",std.name);
	printf("student's age: %d\n",std.age);
	printf("student's address: %s\n",std.address);
}
struct listItem makeListItem(struct student inStd){
	struct listItem result;
	result.std=inStd;
	return result;
}
int menu(){
	int choice;
	printf("Press 1 to add student or 2 to show the list\n");
	scanf("%d",&choice);
	return choice;
}
int studentCompare(struct student std1,struct student std2){
	int id;
	char name[999];
	int age;
	char address[9999];
	if(std1.id!=std2.id)
		return 0;
	if(strcmp(std1.name,std2.name)!=0)
		return 0;
	if(std1.age!=std2.age)
		return 0;
	if(strcmp(std1.address,std2.address)!=0)
		return 0;
	return 1;
}
int isNew(struct student std,struct listItem stdList[],int n){
	int i;
	for(i=0;i<n;i++){
		if(studentCompare(std,stdList[i].std)){
			return i;
		}	
	}
	return -1;
}
void insertStudent(struct listItem stdlist[],int n){
	int index;
	struct student std;
	getStudent(&std);
	if(isNew(std,stdlist,n)==-1){
		struct listItem *newListItem=(struct listItem*)malloc(sizeof(struct listItem));
		if(newListItem==NULL){
			printf("Unable to allocate memory for new student\n");
		}
		else{
			newListItem->std=std;
			printf("Enter student's index\n");
			scanf("%d",index);
			stdlist[index-1].nextStd=newListItem;
			newListItem->nextStd=&stdlist[index];
		}
	}
	else{
		printf("your input is same to student #%d\n",isNew(std,stdlist,n));
	}
}
void putList(struct listItem *stdlist){
	putStudent(stdlist->std);
	if(stdlist->nextStd!=NULL){
		putList(stdlist->nextStd);
	}
}
int main(){
	int n,i,choice;
	printf("Enter students' count\n");
	scanf("%d",&n);
	struct listItem stdList[n];
	struct student std[n],*pointer;
	for(i=0;i<n;i++){
		getStudent(&std[i]);
		stdList[i]=makeListItem(std[i]);
		if(i>0){
			stdList[i-1].nextStd=&stdList[i];
		}
	}
	while(1){
		choice=menu();
		switch(choice){
			case 1:
				insertStudent(stdList,n);
				break;
			case 2:
				putList(stdList);
				return 0;
		}
	}
}
