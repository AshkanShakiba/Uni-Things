#include <iostream>
using namespace std;
int main(){
	int n,i=0,t=1;
	cin>>n;
	while(i<n){
		if(i!=0)
			cout<<i<<endl;
		i=i+t;
		t=t*2;
	}
	if(i==n){
		cout<<i;	
	}
}
/*
int n,i=0,t=1;
input(n);
while(i<n){
	output(i,"\n");
	i=i+t;
	t=t*2;
}
if(i==n){
	output(i);	
}
*/
