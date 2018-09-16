#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	long long a,b,x,y;
	cin >> a >> b >> x >> y;
	long long div = gcd(x,y);
	x /= div;
	y /= div;
	cout << min(a/x,b/y) << endl;
	return 0;
}
