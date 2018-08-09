#include <bits/stdc++.h>
using namespace std;
long long phi[50005];
long long sum[50005];
int main() {
	phi[1] = 1;
	for (int i=2;i<=50000;i++) {
		if (phi[i] == 0) for (int j=i;j<=50000;j+=i) {
			if (phi[j] == 0) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	}
	for (int i=1;i<=50000;i++) sum[i] = sum[i-1] + phi[i];
	long long n;
	while (scanf("%lld",&n) == 1) {
		if (n == 0) break;
		printf("%lld\n",2*sum[n]-1);
	}
	return 0;
}
