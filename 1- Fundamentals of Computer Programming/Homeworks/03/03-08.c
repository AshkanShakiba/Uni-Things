#include <stdio.h>
void p(int x,int q){
	if(x<10){
		printf("0");
	}
	printf("%d",x);
	if(q){
		printf(":");
	}
}
int main(){
	char c;
	int h1,m1,s1,h2,m2,s2,h,m,s;
	scanf("%d%c%d%c%d%d%c%d%c%d",&h1,&c,&m1,&c,&s1,&h2,&c,&m2,&c,&s2);
	s=s1-s2;
	if(s1-s2<0){
		m=m1-m2-1;
		s=60+s;
	}
	else{
		m=m1-m2+(s/60);
		s=s%60;
	}
	if(m<0){
		h=h1-h2-1;
		m=60+m;
	}
	else{
		h=h1-h2+(m/60);
		m=m%60;
	}
	if(h<0){
		h=h+24;
	}
	if(h==0 && m==0 && s==0){
		printf("23:59:59");
	}
	else{
		p(h,1);
		p(m,1);
		p(s,0);
	}
	return 0;
}
