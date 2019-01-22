#include <bits/stdc++.h>
using namespace std;
struct DATA {
	long long cnt[3];
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.cnt[0] - a.cnt[1] > b.cnt[0] - b.cnt[1];
	}
}a[100005];
long long x[100005];
long long y[100005];
priority_queue <long long> q;//用操作都取相反数的方法化为小根堆
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int cnt[3];
		scanf("%d%d%d",&cnt[0],&cnt[1],&cnt[2]);
		int n = cnt[0] + cnt[1] + cnt[2];
		long long zsum = 0;
		for (int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&a[i].cnt[0],&a[i].cnt[1],&a[i].cnt[2]);
			zsum += a[i].cnt[2];
		}
		sort(a+1,a+1+n);
		while (!q.empty()) q.pop();
		for (int i=1;i<=cnt[0];i++) {
			q.push(-(a[i].cnt[0] - a[i].cnt[2]));
			x[i] = x[i-1] + a[i].cnt[0] - a[i].cnt[2];
		}
		for (int i=cnt[0]+1;i<=n-cnt[1];i++) {
			if (a[i].cnt[0] - a[i].cnt[2] > -q.top()) {
				x[i] = x[i-1] + q.top() + a[i].cnt[0] - a[i].cnt[2];
				q.pop();
				q.push(-(a[i].cnt[0] - a[i].cnt[2]));
			}
			else x[i] = x[i-1];
		}
		while (!q.empty()) q.pop();//clear queue
		y[n+1] = 0;
		for (int i=n;i>n-cnt[1];i--) {
			y[i] = y[i+1] + a[i].cnt[1] - a[i].cnt[2];
			q.push(-(a[i].cnt[1] - a[i].cnt[2]));
		}
		for (int i=n-cnt[1];i>cnt[0];i--) {
			if (a[i].cnt[1] - a[i].cnt[2] > -q.top()) {
				y[i] = y[i+1] + q.top() + a[i].cnt[1] - a[i].cnt[2];
				q.pop();
				q.push(-(a[i].cnt[1] - a[i].cnt[2]));
			}
			else y[i] = y[i+1];
		}
		long long ans = 0;
		for (int i=cnt[0];i<=n-cnt[1];i++) ans = max(ans,zsum + x[i] + y[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}
