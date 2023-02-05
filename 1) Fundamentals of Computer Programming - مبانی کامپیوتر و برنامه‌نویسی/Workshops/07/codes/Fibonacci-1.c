#include <stdio.h>
long int fibonacci (long int n){
    if(n<=0)
       return 0;
    if(n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    long int n;
    scanf("%ld",&n);
    printf("%ld",fibonacci(n));
    return 0;
}
