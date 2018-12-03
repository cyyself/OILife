#include <bits/stdc++.h>
using namespace std;
struct edge {
	int u,v,w;
	bool inmst;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w < b.w;
	}
}e[44850];
int n,m;
struct unionset {
	int f[305];
	void init() {
		for (int i=1;i<=n;i++) f[i] = i;
	}
	int find(int x) {
		if (f[x] != x) f[x] = find(f[x]);
		return f[x];
	}
	void uni(int x,int y) {
		f[find(x)] = find(y);
	}
};
int getmst() {
	unionset s;
	s.init();
	int cnt = 0;
	int cost = 0;
	for (int i=0;i<m && cnt < n-1;i++) {
		if (s.find(e[i].u) != s.find(e[i].v)) {
			s.uni(e[i].u,e[i].v);
			cost += e[i].w;
			cnt ++;
			e[i].inmst = true;
		}
	}
	if (cnt != n-1) return -1;
	return cost;
}
bool exist(int mstcost) {
	unionset s;
	for (int j=0;j<n-1;j++) {//在mst上的第几条边的时候跳过
		s.init();
		int cnt = 0;
		bool skip = false;
		int cost = 0;
		for (int i=0;i<m && cnt < n-1 && cost < mstcost;i++) {
			if (e[i].inmst && cnt == j && !skip) {
				skip = true;
				continue;
			}
			if (s.find(e[i].u) != s.find(e[i].v)) {
				s.uni(e[i].u,e[i].v);
				cost += e[i].w;
				cnt ++;
			}
		}
		if (cnt == n-1 && cost == mstcost) return true;
	}
	return false;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++) {
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			e[i].inmst = false;
		}
		sort(e,e+m);
		int mstcost = getmst();
		if (exist(mstcost)) printf("ZWY Wake Up!\n");
		else printf("%d\n",mstcost);
	}
	return 0;
}
