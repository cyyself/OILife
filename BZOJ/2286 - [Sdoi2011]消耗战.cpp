#include <bits/stdc++.h>
using namespace std;
const int maxn = 250005;
const long long inf = 0x3f3f3f3f3f3f3f3f;
vector <pair<int,int> > g1[maxn];
int up[maxn][20];
int dep[maxn];
long long c[maxn];
int dfn[maxn];
int ts;
void dfs(int u,int f) {
	dfn[u] = ts ++;
	for (int i=1;(1<<i) <= dep[u];i++) {
		up[u][i] = up[up[u][i-1]][i-1];
	}
	for (int i=0;i<g1[u].size();i++) {
	//for (auto x:g1[u]) {
	//	int v = x.first;
	//	int w = x.second;
		int v = g1[u][i].first;
		int w = g1[u][i].second;
		if (v == f) continue;
		dep[v] = dep[u] + 1;
		up[v][0] = u;
		c[v] = min(w*1ll,c[u]);
		dfs(v,u);
	}
}
bool cmp(int x,int y) {
	return dfn[x] < dfn[y];
}
int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int diff = dep[y] - dep[x];
	for (int i=0;diff;i++) if (diff & (1<<i) ) {
		y = up[y][i];
		diff -= (1 << i);
	}
	for (int i=19;i>=0;i--) {
		if (up[x][i] != up[y][i]) {
			x = up[x][i];
			y = up[y][i];
		}
	}
	if (x == y) return x;
	else return up[x][0];
}
bool ins[maxn];
stack <int> used_s;
bool used[maxn];
vector <int> g2[maxn];
void clear_g2() {
	while (!used_s.empty()) {
		int u = used_s.top();
		used_s.pop();
		used[u] = false;
		g2[u].clear();
	}
}
void add(int u,int v) {
	if (!used[u]) {
		used[u] = true;
		used_s.push(u);
	}
	g2[u].push_back(v);
}
long long f[maxn];
bool key_node[maxn];
void dfs2(int u,int fa) {
	f[u] = c[u];
	long long tmp = 0;
	for (int i=0;i<g2[u].size();i++) {
	//for (auto v:g2[u]) {
		int v = g2[u][i];
		if (v == fa) continue;
		dfs2(v,u);
		tmp += f[v];
	}
	if (!key_node[u]) f[u] = min(f[u]*1ll,tmp);
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g1[u].push_back(make_pair(v,w));
		g1[v].push_back(make_pair(u,w));
	}
	c[1] = inf;
	dfs(1,-1);
	int q;
	scanf("%d",&q);
	while (q --) {
		int k;
		scanf("%d",&k);
		vector <int> h;
		for (int i=0;i<k;i++) {
			int t;
			scanf("%d",&t);
			h.push_back(t);
			key_node[t] = true;
		}
		sort(h.begin(),h.end(),cmp);
		stack <int> s;
		s.push(1);
		ins[1] = true;
		clear_g2();
		for (int i=0;i<h.size();i++) {
		//for (auto x:h) {
			int x = h[i];
			int tmp = lca(x,s.top());
			if (tmp == s.top()) {
				s.push(x);
				ins[x] = true;
			}
			else if (ins[tmp]) {
				int last = s.top();
				int cur;
				do {
					ins[last] = false;
					s.pop();
					cur = s.top();
					add(cur,last);
					last = cur;
				}
				while (cur != tmp);
				s.push(x);
				ins[x] = true;
			}
			else {
				int last = s.top();
				while (true) {
					ins[last] = false;
					s.pop();
					int cur = s.top();
					if (dfn[cur] < dfn[tmp]) {
						add(tmp,last);
						s.push(tmp);
						ins[tmp] = true;
						s.push(x);
						ins[x] = true;
						break;
					}
					else {
						add(cur,last);
						last = cur;
					}
				}
			}
		}
		int last = s.top();
		while (!s.empty()) {
			ins[last] = false;
			s.pop();
			if (!s.empty()) {
				int cur = s.top();
				add(cur,last);
				last = cur;
			}
		}
		dfs2(1,-1);
		printf("%lld\n",f[1]);
		for (int i=0;i<h.size();i++) key_node[h[i]] = false;
		//for (auto x:h) key_node[x] = false;
	}
	return 0;
}
