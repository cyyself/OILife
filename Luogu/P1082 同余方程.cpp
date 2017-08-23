#include <iostream>
using namespace std;
int gcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	else{
		int t = gcd(b,a%b,y,x);
		y-=x*(a/b);
		return t;
	}
}
int main(){
	int a,b;
	cin >> a >> b;
	int x=0,y=0;
	gcd(a,b,x,y);
	cout << (x + b) % b << endl;
	return 0;
}