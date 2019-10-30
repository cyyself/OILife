#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int id;
	double d;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.d > b.d;
	}
};
double a[200005];
int cnt[200005];
double sq(double x) {
	return x * x;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		priority_queue <DATA> q;
		int n,m;
		scanf("%d%d",&n,&m);
		double avg = 0;
		for (int i=1;i<=n;i++) {
			scanf("%lf",&a[i]);
			cnt[i] = 1;
			avg += a[i];
		}
		avg /= m;
		double ans = -avg * avg * m;
		for (int i=1;i<=n;i++) {
			double old_c = sq(a[i] / cnt[i]) * cnt[i];
			double new_c = sq(a[i] / (cnt[i]+1)) * (cnt[i]+1);
			//double old_c = sq(a[i] - avg);
			//double new_c = sq(a[i] / 2 - avg) * 2;
			q.push((DATA){i,new_c - old_c});
			ans += old_c;
		}
		for (int i=n+1;i<=m;i++) {
			auto cur = q.top();
			q.pop();
			ans += cur.d;
			cnt[cur.id] ++;
			//double old_c = sq(a[cur.id] / cnt[cur.id] - avg) * cnt[cur.id];
			//double new_c = sq(a[cur.id] / (cnt[cur.id]+1) - avg) * (cnt[cur.id]+1);
			double old_c = sq(a[cur.id] / cnt[cur.id]) * cnt[cur.id];
			double new_c = sq(a[cur.id] / (cnt[cur.id]+1)) * (cnt[cur.id]+1);
			q.push((DATA){cur.id,new_c - old_c});
		}
		ans /= m;
		printf("Case #%d: %0.10lf\n",cas,ans);
	}
	return 0;
}
