#include <bits/stdc++.h>
using namespace std;
bool vis[51][201];
pair <pair<int,int>,int> pre[51][201];
pair <int,int> getd(int i,int j,int k) {
	int dn = i * j + k;
	int dm = 0;
	if (i == 1) dm += 2 * (j - 2) + 2 * 3;
	else dm += 4 * 2 + 2*(i-2) + 2*(j-2);
	if (k) {
		if (k <= j) dm += 2;
		else dm += 2 + 2*(k - j);
	}
	return make_pair(dn,dm);
}
void init() {
	vis[0][0] = true;
	queue <pair<int,int> > q;
	q.push({0,0});
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int rem = 50 - cur.first;
		for (int i=1;i<=rem;i++) for (int j=i;j<=rem/i;j++) {
			for (int k=0;k<=rem-i*j;k++) {
				pair <int,int> x = getd(i,j,k);
				int dn = x.first;
				int dm = x.second;
				if (!vis[cur.first+dn][cur.second+dm]) {
					vis[cur.first+dn][cur.second+dm] = true;
					pre[cur.first+dn][cur.second+dm] = make_pair(make_pair(i,j),k);
					q.push({cur.first+dn,cur.second+dm});
				}
			}
		}
	}
}
int main() {
	init();
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		if (vis[n][m]) {
			printf("Yes\n");
			int sx = 0, sy = 0;
			int curn = n, curm = m;
			while (pre[curn][curm] != make_pair(make_pair(0,0),0)) {
				for (int i=0;i<pre[curn][curm].first.first;i++) 
					for (int j=0;j<pre[curn][curm].first.second;j++) printf("%d %d\n",sx+i,sy+j);
				if (pre[curn][curm].second) {
					for (int j=0;j<pre[curn][curm].second;j++) printf("%d %d\n",sx+pre[curn][curm].first.first,sy+j);
				}
				pair <int,int> prev = getd(pre[curn][curm].first.first,pre[curn][curm].first.second,pre[curn][curm].second);
				curn -= prev.first;
				curm -= prev.second;
				sx += 100;
			}
		}
		else printf("No\n");
	}
	return 0;
}
