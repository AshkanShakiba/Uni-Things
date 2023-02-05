#include <stdio.h>
int min(int x,int y){
	if(x<=y)
		return x;
	return y;
}
int max(int x,int y){
	if(x>=y)
		return x;
	return y;
}
int main(){
	int a,b,c,d,e,f,g,h,u,v,x,y,s;
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
	u=max(a,e);
	v=max(b,f);
	x=min(c,g);
	y=min(d,h);
	s=(x-u)*(y-v);
	printf("%d",s);
}
