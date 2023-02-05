#include <iostream>
using namespace std;
int main(){
	int n,a,b,c;
	cin>>n;
	for(a=1;a<=n-2;a++){
		for(b=1;b<=n-2;b++){
			for(c=1;c<=n-2;c++){
				if(a+b+c==n && a<b+c && b<c+a && c<a+b && a<=b && b<=c){
					cout<<"("<<a<<","<<b<<","<<c<<")"<<endl;
				}
			}
		}
	}
}
/*
int n,a,b,c;
input(n);
a=1;
while(a<=n-2){
	b=1;
	while(b<=n-2){
		c=1;
		while(c<=n-2){
			if(a+b+c==n && a<b+c && b<c+a && c<a+b && a<=b && b<=c){
				output("(",a,",",b,",",c,")\n");
			}
			c=c+1;
		}
		b=b+1;
	}
	a=a+1;
}
*/
