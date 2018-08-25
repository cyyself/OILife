#include <bits/stdc++.h>
using namespace std;
long long b[200005];
int main() {
	long long n,a;
	cin >> n >> a;
	long long MIN = n;
	long long MAX = 0;
	for (int i=1;i<=n;i++) {
		cin >> b[i];
		MAX += b[i];
	}
	for (int i=1;i<=n;i++) {
		long long l = 1;
		long long r = b[i];
		l = max(l,a-(MAX-b[i]));
		r = min(r,a-(MIN-1));
		if (i > 1) printf(" ");
		cout << b[i]-max(r-l+1,0ll);
	}
	printf("\n");
	return 0;
}
