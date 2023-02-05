#include <stdio.h>
#include <string.h>
struct count{char word[20]; int cnt;};
int frequency(int rows, int len, char strings[rows][len], struct count result []){
    int i,j,k=0,ki,in,isNew;
    for(i=1;i<=rows;i++){
        in=j=0;
        while(j<strlen(strings[i])){
            while(strings[i][j]!=' ' && strings[i][j]!='\0'){
                j++;
            }
            isNew=1;
            char w[20];
            strncpy(w,strings[i]+in,j-in);
            w[j-in]='\0';
            for(ki=0;ki<k;ki++){
                if(strcmp(result[ki].word,w)==0){
                    result[ki].cnt++;
                    isNew=0;
                    break;
                }
            }
            if(isNew){
                strcpy(result[k].word,w);
                result[k].cnt=1;
                k++;
            }
            j++;
            in=j;
        }
    }
    return k;
}
int main(){
    int rows,len,i,size;
    scanf("%d%d",&rows,&len);
    struct count res[rows*len];
    char strings[rows+1][len];
    for(i=0;i<rows+1;i++){
        gets(strings[i]);
    }
    size=frequency(rows,len,strings,res);
    for(i=0;i<size;i++) {
        printf("%s %d\n", res[i].word, res[i].cnt);
    }
    return 0;
}
