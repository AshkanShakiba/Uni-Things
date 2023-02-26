#include <stdio.h>
int main()
{
unsigned long long int N;
scanf("%u", &N);
unsigned long long int a = 0, b = 1,i;
for ( i = 1; i <= N; i++) {
b = b + a;
a = b - a;
printf("%u\n",b);
}
return 0;
}
