#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,k;
	cin >> n >> k;
	if (n * 2 < k) printf("0\n");
	else {
		if (n * 2 == k && k%2LL == 0) {
			printf("0\n");
		}
		else {
			long long lmax = k / 2;
			lmax = min(lmax,n);
			long long rmax = n - lmax;
			if (k % 2 == 0 && lmax >= k/2 && rmax >= k/2) lmax --;
			cout << min(lmax,rmax) << endl;
		}
	}
	return 0;
}
