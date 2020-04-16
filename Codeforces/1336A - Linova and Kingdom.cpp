#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector <int> g[maxn];
int up[maxn];
int ch[maxn];
int dep[maxn],sz[maxn];
struct DATA {
	int idx;
	int sz;
	friend bool operator < (const DATA &a,const DATA &b) {
		return dep[a.idx] - a.sz < dep[b.idx] - b.sz;
	}
};
priority_queue <DATA> q;
void dfs(int u,int f) {
	for (auto v:g[u]) {
		if (v == f) continue;
		up[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v,u);
		ch[u] ++;
	}
	if (ch[u] == 0) q.push((DATA){u,0});
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep[1] = 1;
	dfs(1,0);
	long long ans = 0;
	for (int i=1;i<=k;i++) {
		auto cur = q.top();
		while (cur.sz != sz[cur.idx]) {
			q.pop();
			q.push((DATA){cur.idx,sz[cur.idx]});
			cur = q.top();
		}
		q.pop();
		ans += dep[cur.idx] - 1 - cur.sz;
		sz[up[cur.idx]] += sz[cur.idx] + 1;
		ch[up[cur.idx]] --;
		if (ch[up[cur.idx]] == 0) q.push((DATA){up[cur.idx],sz[up[cur.idx]]});
	}
	printf("%lld\n",ans);
	return 0;
}
