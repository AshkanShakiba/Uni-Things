#include <stdio.h>
int main(){
	int j = 0, i = 0,
	*p1;
	int **p2, **p3;
	p2 = p3 = (int **) malloc(3 * sizeof(int *));
	printf("%d\n", sizeof(int *));
	do {
	*p2 = (int *) calloc(2 * (i + 1) , sizeof(int));
	for(j = 1, p1 = (*p2) + 1; j < 2 * (i + 1); j++, p1++)
	*p1 += j + *(p1 - 1);
	p2++;
	i++;
	} while(i < 3);
	p2 = p3;
	for(i = 2; i >= 0; i--)
	for(j = 0; j < 2 * (i + 1); j++)
	printf("[%d][%d] = %d\n", i, j, *((*(p2 + i))+j));
}
