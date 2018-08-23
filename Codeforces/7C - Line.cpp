#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long ret = exgcd(b,a%b,y,x);
		y -= x*(a/b);
		return ret;
	}
}
int main() {
	long long a,b,c;
	cin >> a >> b >> c;
	long long x,y;
	long long g = exgcd(a,b,x,y);
	if (c % g != 0) {
		cout << -1 << endl;
		return 0;
	}
	x = -x;
	y = -y;
	x *= c / g;
	y *= c / g;
	cout << x << " " << y << "\n";
	return 0;
}
