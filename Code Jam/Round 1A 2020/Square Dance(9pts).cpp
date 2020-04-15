#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
struct UnionSet {
	int f[105];
	int find(int x) {
		if (f[x] == x) return x;
		else return f[x] = find(f[x]);
	}
	void uni(int x,int y) {
		f[find(x)] = find(y);
	}
	void init(int n) {
		for (int i=0;i<=n+1;i++) f[i] = i;
	}
}u[105],d[105],l[105],r[105];
int mt[105][105];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++) {
			u[i].init(n);
			d[i].init(n);
		}
		for (int i=1;i<=n;i++) {
			l[i].init(m);
			r[i].init(m);
		}
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			scanf("%d",&mt[i][j]);
		}
		vector <pair<int,int> > tmp;
		long long ans = 0;
		do {
			tmp.clear();
			for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
				if (mt[i][j] != -1) {
					ans += mt[i][j];
					int sum = 0;
					int cnt = 0;
					int cu = u[j].find(i-1);
					if (cu != 0) {
						sum += mt[cu][j];
						cnt ++;
					}
					int cd = d[j].find(i+1);
					if (cd != n + 1) {
						sum += mt[cd][j];
						cnt ++;
					}
					int cl = l[i].find(j-1);
					if (cl != 0) {
						sum += mt[i][cl];
						cnt ++;
					}
					int cr = r[i].find(j+1);
					if (cr != m + 1) {
						sum += mt[i][cr];
						cnt ++;
					}
					if (mt[i][j] * cnt < sum) {
						tmp.push_back(make_pair(i,j));
					}
				}
			}
			for (auto pos:tmp) {
				mt[pos.x][pos.y] = -1;
				l[pos.x].uni(pos.y,pos.y-1);
				r[pos.x].uni(pos.y,pos.y+1);
				u[pos.y].uni(pos.x,pos.x-1);
				d[pos.y].uni(pos.x,pos.x+1);
			}
		}
		while (tmp.size());
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}
