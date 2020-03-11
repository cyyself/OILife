#include <bits/stdc++.h>
using namespace std;
const int maxn = 250005;
const long long inf = 0x3f3f3f3f3f3f3f3f;
vector <int> g1[maxn];
int up[maxn][20];
int dep[maxn];
int dfn[maxn];
int ts;
void dfs(int u,int f) {
	dfn[u] = ts ++;
	for (int i=1;(1<<i) <= dep[u];i++) {
		up[u][i] = up[up[u][i-1]][i-1];
	}
	for (auto v:g1[u]) {
		if (v == f) continue;
		dep[v] = dep[u] + 1;
		up[v][0] = u;
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
bool f[maxn];//表示这个点往下有没有还没设置障碍的点
bool key_node[maxn];
int ans;
bool ok;
void dfs2(int u,int fa) {
	if (ans == -1) return;
	f[u] = false;
	int cnt = 0;
	for (auto v:g2[u]) {
		if (v == fa) continue;
		dfs2(v,u);
		cnt += f[v];
	}
	if (key_node[u]) {
		for (auto v:g2[u]) {
			if (v == fa) continue;
			if (f[v]) {
				if (dep[v] - dep[u] > 1 || !key_node[v]) ans ++;
				else {
					ok = false;
					break;
				}
			}
		}
		f[u] = true;
	}
	else {
		if (cnt > 1) ans ++;
		else if (cnt == 1) f[u] = true;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
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
		for (auto x:h) {
			if (x == 1) continue;
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
		//do dp
		ans = 0;
		ok = true;
		dfs2(1,-1);
		if (!ok) printf("-1\n");
		else printf("%d\n",ans);
		for (auto x:h) key_node[x] = false;
	}
	return 0;
}
