#include <stdio.h>
struct Class{
	char professorName[999];
	int studentsCount;
	int average;
	int scores[111];
};
void getClassInfo(struct Class *inClass){
	printf("Enter professor/supervisor's name\n");
	fflush(stdin);
	gets(inClass->professorName);
	printf("Enter students' count\n");
	fflush(stdin);
	scanf("%d",&(inClass->studentsCount));
}
void getClassScores(struct Class *inClass){
	int i;
	for(i=1;i<=inClass->studentsCount;i++){
		printf("Enter student #%d 's score\n",i);
		fflush(stdin);
		scanf("%d",&(inClass->scores[i]));
	}
}
void calculateAverage(struct Class *inClass){
	int i;
	double sum=0;
	for(i=1;i<=inClass->studentsCount;i++){
		sum+=inClass->scores[i];
	}
	inClass->average=sum/(inClass->studentsCount);
}
void putClassInfo(struct Class inClass){
	printf("professor/supervisor's name: %s\n",inClass.professorName);
	printf("students' count: %d\n",inClass.studentsCount);
	printf("average of students' scores: %d\n",inClass.average);
}
int main(){
	struct Class Clab;
	getClassInfo(&Clab);
	getClassScores(&Clab);
	calculateAverage(&Clab);
	putClassInfo(Clab);
	return 0; 
}
