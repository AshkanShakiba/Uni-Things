#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	string c;
	bool b=false;
	int f,y,f1,f2,y1,y2,x;
	f1=rand()%10+1;
	f2=rand()%10+1;
	y1=rand()%10+1;
	y2=rand()%10+1;
	f=f1+f2;
	y=y1+y2;
	cout<<"Father's cards = "<<f1<<" + ?"<<endl;
	cout<<"Your cards = "<<y1<<" + "<<y2<<endl;
	while(b==false && y<21){
		cout<<"Your hand = "<<y<<endl;
		cout<<"\"AddAdad\" or \"AdadBas\"?"<<endl;
		cin>>c;
		if(c=="AddAdad"){
			x=rand()%10+1;
			cout<<"Your New Card = "<<x<<endl;
			y=y+x;
		}
		else if(c=="AdadBas"){
			b=true;
		}
		else{
			cout<<"What?! Say again plz"<<endl;
		}
	}
	cout<<"Your hand = "<<y<<endl;
	while(f<17){
		x=rand()%10+1;
		cout<<"Father\'s New Card = "<<x<<endl;
		f=f+x;
	}
	cout<<"Father's hand = "<<f<<endl;
	if(f==y){
		cout<<"It's a tie game!";
	}
	else if(f==21 || y>21){
		cout<<"Father wins!";
	}
	else if(y==21 || f>21){
		cout<<"You win!";
	}
	else if(f>y){
		cout<<"Father wins!";
	}
	else{
		cout<<"You win!";
	}
}
//By Ashkan Shakiba
