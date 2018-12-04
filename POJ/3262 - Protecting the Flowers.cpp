#include <cstdio>
#include <algorithm>
using namespace std;
struct cow {
	long long t,d;
	friend bool operator < (const cow &a,const cow &b) {
		return (double)a.t/a.d < (double)b.t/b.d;
	}
}c[100005];
long long suf[100005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld%lld",&c[i].t,&c[i].d);
	sort(c,c+n);
	suf[n-1] = 0;
	for (int i=n-1;i>=0;i--) {
		suf[i] = suf[i+1] + c[i].d;
	}
	long long cost = 0;
	for (int i=0;i<n;i++) {
		cost += suf[i+1] * c[i].t * 2LL;
	}
	printf("%lld\n",cost);
	return 0;
}
