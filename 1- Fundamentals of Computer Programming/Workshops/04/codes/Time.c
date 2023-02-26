#include <stdio.h>
int main(){
	int t,d,h,m,s;
	scanf("%d",&t);
	s=t%60;
	t=t-s;
	m=(t/60)%60;
	t=t-m*60;
	h=(t/3600)%24;
	t=t-h*3600;
	d=t/86400;
	printf("%d days & %d hours & %d minutes & %d seconds",d,h,m,s);
}
