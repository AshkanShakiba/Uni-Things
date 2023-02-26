#include <stdio.h>
int main()
{
int N;
scanf("%d", &N);
N-=1;
double a = 0, b = 1,i;
for (i = 1; i <= N; i++) {
b = b + a;
a = b - a;
}
printf("%.0lf\n",b);
return 0;
}
