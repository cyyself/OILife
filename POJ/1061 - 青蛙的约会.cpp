#include <iostream>
using namespace std;
long long gcd(long long a,long long b,long long &x,long long &y){
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
	long long x,y,m,n,l;
	cin >> x >> y >> m >> n >> l;
	long long i=0,j=0;
	long long g = gcd(m-n,l,i,j);
	if ((y-x)%g != 0) cout << "Impossible" << endl;
	else {
		i *= (y-x) / g;
		l /= g;
		if (l < 0) l = -l;
		i = (i % l + l) % l;
		cout << i << endl;
	}
	return 0;
}
