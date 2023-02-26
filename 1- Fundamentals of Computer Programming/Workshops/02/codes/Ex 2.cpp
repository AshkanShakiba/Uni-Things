#include <iostream>
using namespace std;
int BMM_N(double num1,double num2){
	int N=0,m;
	double a0,a1,a2=1;
	if(num1>=num2){
		a1=num1;
		a2=num2;
	}
	else{
		a1=num2;
		a2=num1;
	}
	while(a2>0){
		a0=a1;
		a1=a2;
		m=a0/a1;
		a2=a0-m*a1;
		N=N+1;
		cout<<a0<<", "<<a1<<", "<<a2<<endl;
	}
	return N;
}
int main(){
	double num1,num2;
	/*cout<<"num1?"<<endl;
	cin>>num1;
	cout<<"num2?"<<endl;
	cin>>num2;*/
	num1=24;
	num2=17;
	cout<<BMM_N(num1,num2);
}
//By Ashkan Shakiba
