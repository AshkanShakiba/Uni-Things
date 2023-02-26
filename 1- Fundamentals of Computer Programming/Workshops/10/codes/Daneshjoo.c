#include <stdio.h>
struct student{
	int id;
	char name[999];
	int age;
	char address[9999];
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
int main(){
	int n,i;
	printf("Enter students' count\n");
	scanf("%d",&n);
	struct student std[n];
	for(i=0;i<n;i++){
		getStudent(&std[i]);
	}
	for(i=0;i<n;i++){
		putStudent(std[i]);
	}
	return 0;
}
