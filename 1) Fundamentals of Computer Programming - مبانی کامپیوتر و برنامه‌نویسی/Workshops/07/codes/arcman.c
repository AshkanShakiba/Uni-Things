#include <stdio.h>
#include <math.h>
unsigned long long int A(unsigned long long int m,unsigned long long int n)
{
    if(m==0)
        return n+1;
    if(m>0&&n==0)
        return A(m-1,1);
    if(m>0&&n>0)
        return A(m-1,A(m,n-1));
}
int main(void)
{
    unsigned long long int m,n;
    scanf("%lu%lu",&m,&n);
    printf("%lu",A(m,n));
    return 0;
}
