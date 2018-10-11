#include <bits/stdc++.h>
using namespace std;
int p[1000];
int n;
long long judge(int fz,int fm) {
	long long ret = 0;
	for (int i=0;i<n;i++) {
		ret += (long long)fz * p[i] / fm;
	}
	return ret;
}
int main() {
	long long k;
	scanf("%d%lld",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&p[i]);
	for (int i=0;i<n;i++) {
		int l = 1;
		int r = p[i] - 1;
		long long t;
		while (l < r) {
			int mid = (l + r) / 2;
			t = judge(mid,p[i]);
			if (t >= k) r = mid;
			else l = mid + 1;
		}
		if (judge(l,p[i]) == k) {
			printf("%d/%d\n",l,p[i]);
			return 0;
		}
	}
	return 0;
}
