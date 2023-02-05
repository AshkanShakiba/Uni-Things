#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int i){
    int j;
    if((i==0)&&(i==1))
        return 0;
    for(j=2;j<i;j++){
        if(i%j==0)
            return 0;
    }
    return 1;
}
int numDigits(int n){
    int count=0;
    if(n==0)
        return 1;
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}
int main()
{
    int num, k, i;
    scanf("%d",&num);
    k = numDigits(num);
    for(i=0;i<k;i++){
        if(isPrime(num%(int)pow(10,i)))
            continue;
        else{
            printf("No!");
            return 0;
        }
    }
    printf("Yes!");
    return 0;
}
