#include <iostream>
using namespace std;
int main(){
	int a,b,i=1,n=0,s[999];
	cin>>a>>b;
	while(a>0){
		s[i]=a%b;
		n=n+1;
		a=a/b;
		i++;
	}
	for(i=n;i>=1;i--){
		cout<<s[i];
	}
}
//By Ashkan Shakiba
