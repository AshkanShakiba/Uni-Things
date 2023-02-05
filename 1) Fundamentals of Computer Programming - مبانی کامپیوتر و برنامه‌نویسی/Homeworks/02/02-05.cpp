#include <iostream>
using namespace std;
int main(){
	int n,votes[201],results[100],i;
	cin>>n; //n<100
	i=1;
	while(i<=n){
		results[i]=0;
		i++;
	}
	i=1;
	while(i<=200){
		cin>>votes[i];
		i++;
	}
	i=1;
	while(i<=200){
		results[votes[i]]++;
		i++;
	}
	i=1;
	while(i<=n){
		cout<<"#"<<i<<": "<<results[i]<<endl;
		i++;
	}
}
/*
int n,votes[],results[],i;
input(n); 
i=1;
while(i<=n){
	results[i]=0;
	i=i+1;
}
i=1;
while(i<=200){
	input(votes[i]);
	i=i+1;
}
i=1;
while(i<=200){
	results[votes[i]]=results[votes[i]]+1;
	i=i+1;
}
i=1;
while(i<=n){
	output("#",i,": ",results[i],"\n");
	i=i+1;
}
*/
