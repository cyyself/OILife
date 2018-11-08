#include <bits/stdc++.h>
using namespace std;
int phi[1100005];
int minx[1100005];
void getphi(int x) {
	phi[1] = 1;
	for (int i=2;i<=x;i++) {
		if (phi[i] == 0) for (int j=i;j<=x;j+=i) {
			if (phi[j] == 0) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	}
}
int main() {
	getphi(1100000);
	for (int i=2;i<=1100000;i++) if (minx[phi[i]] == 0) minx[phi[i]] = i;
	int cur = 1e9+7;
	for (int i=1100000;i>=1;i--) {
		if (minx[i] == 0) minx[i] = cur;
		else {
			cur = min(cur,minx[i]);
			minx[i] = cur;
		}
	}
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		long long ans = 0;
		while (n --) {
			int x;
			scanf("%d",&x);
			ans += minx[x];
		}
		printf("Case %d: %lld Xukha\n",c,ans);
	}
	return 0;
}
