#include <iostream>
using namespace std;
int func(int n,int sum){
	int m;
	if(n!=0){
		m=n%10;
		sum=sum*10+m;
		func(n/10,sum);
	}
	return sum;
}
int main(){
	int n,sum=0;
	cin>>n;
	cout<<func(n,sum);
}
