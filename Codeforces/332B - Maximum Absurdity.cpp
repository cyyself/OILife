#include <bits/stdc++.h>
using namespace std;
long long s[200005];//原数组的区间和
long long sk[200005];//sk[i]表示从i开始，长度为k的区间的和
long long pos[200005];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		long long t;
		scanf("%lld",&t);
		s[i] = t + s[i-1];
	}
	sk[n-k+1] = s[n] - s[n-k];
	pos[n-k+1] = n - k + 1;
	for (int i=n-k;i>=1;i--) {
		sk[i] = s[i+k-1] - s[i-1];
		if (sk[i] >= sk[pos[i+1]]) {
			pos[i] = i;
		}
		else pos[i] = pos[i+1];
	}
	long long ans = 0;
	int ans_0,ans_1;
	for (int i=1;i+2*k-1<=n;i++) {
		if (sk[i] + sk[pos[i+k]] > ans) {
			ans = sk[i] + sk[pos[i+k]];
			ans_0 = i;
			ans_1 = pos[i+k];
		}
	}
	printf("%d %d\n",ans_0,ans_1);
	return 0;
}
