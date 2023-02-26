#include <iostream>
using namespace std;
int main(){
	bool p;
	int n,t=0,i=2,j=2;
	cin>>n;
	while(i<=n){
		j=2;
		p=true;
		while(j<i){
			if(i%j==0){
				p=false;
			}
			j++;
		}
		if(p==true){
			t=t+1;
		}
		i++;
	}
	cout<<t;
}
/*
bool p;
int n,t=0,i=2,j=2;
input(n);
while(i<=n){
	j=2;
	p=true;1
	while(j<i){
		if(i%j==0){
			p=false;
		}
		j=j+1;
	}
	if(p==true){
		t=t+1;
	}
	i=i+1;
}
output(t);
*/
