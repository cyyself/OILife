#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long cur = 0;
	for (int i=0;i<=n;i++) {
		cur += i;
		if (cur - (n - i) == k) {
			cout << (n - i) << endl;
			break;
		}
	}
	return 0;
}
