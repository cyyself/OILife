#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int inf = 0x3f3f3f3f;
vector <int> g1[maxn];
int up[maxn][20];
int dep[maxn];
int dfn[maxn];
int ts;
int sz[maxn];
void dfs(int u,int f) {
	dfn[u] = ts ++;
	sz[u] = 1;
	for (int i=1;(1<<i) <= dep[u];i++) {
		up[u][i] = up[up[u][i-1]][i-1];
	}
	for (int i=0;i<g1[u].size();i++) {
	//for (auto x:g1[u]) {
	//	int v = x.first;
	//	int w = x.second;
		int v = g1[u][i];
		if (v == f) continue;
		dep[v] = dep[u] + 1;
		up[v][0] = u;
		dfs(v,u);
		sz[u] += sz[v];
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
int f[maxn],down[maxn];
bool key_node[maxn];
void dfs2(int u,int fa) {
	if (key_node[u]) down[u] = u;
	else down[u] = -1;
	for (int i=0;i<g2[u].size();i++) {
	//for (auto v:g2[u]) {
		int v = g2[u][i];
		if (v == fa) continue;
		dfs2(v,u);
		if (
			down[u] == -1 || 
			(dep[down[v]] < dep[down[u]]) || 
			(dep[down[v]] == dep[down[u]] && down[v] < down[u]) ) {
			down[u] = down[v];
		}
	}
}
int node_min(int x,int y) {
	if (dep[x] == dep[y]) return min(x,y);
	else if (dep[x] < dep[y]) return x;
	else return y;
}
struct DATA {
	int down,v;
	friend bool operator < (const DATA &a,const DATA &b) {
		if (dep[a.down] != dep[b.down]) return dep[a.down] < dep[b.down];
		else return a.down < b.down;
	}
};
int getdis(int u,int v) {
	return dep[u] + dep[v] - dep[lca(u,v)] * 2;
}
void dfs3(int u,int fa,int up_n) {
	if (key_node[u]) up_n = u;
	int near = (up_n==-1)?down[u]:( 
		(getdis(u,up_n)<getdis(u,down[u])||(getdis(u,up_n)==getdis(u,down[u]) && up_n < down[u]) )?up_n:down[u]
	);
	int tot = 0;
	set <DATA> s;//dep[v],v
	for (int i=0;i<g2[u].size();i++) {
	//for (auto v:g2[u]) {
		int v = g2[u][i];
		if (v == fa) continue;
		s.insert((DATA){down[v],v});
		if (s.size() > 2) {
			set<DATA>::iterator ed = s.end();
			ed --;
			s.erase(ed);
		}
	}
	for (int j=0;j<g2[u].size();j++) {
	//for (auto v:g2[u])
		int v = g2[u][j];
		if (v == fa) continue;
		int up_edge = up_n;
		if (s.size() == 2) {
			set<DATA>::iterator fi = s.begin();
			set<DATA>::iterator se = s.begin();
			se ++;//要是支持c++11有next多好
			if (fi->v == v) {
				if (
					up_edge == -1 || 
					getdis(v,se->down) < getdis(v,up_edge) || 
					(getdis(v,se->down) == getdis(v,up_edge) && se->down < up_edge)) {
					up_edge = se->down;
				}
			}
			else {
				if (
					up_edge == -1 ||
					getdis(v,fi->down) < getdis(v,up_edge) || 
					(getdis(v,fi->down) == getdis(v,up_edge) && fi->down < up_edge)) {
					up_edge = fi->down;
				}
			}
		}
		//处理这条边 {
		int dis_up = (up_edge == -1)?inf:getdis(u,up_edge);
		int dis_down = getdis(v,down[v]);
		int len = dep[v] - dep[u];//链的长度
		int x = 0;
		int l = 1, r = len;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (dis_up + mid < dis_down + (len - mid)) {
				x = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		int rem = sz[v] - 1;
		//处理下部分{
		int sz_d = 0;
		if (len - (x + 1) >= 1) {
			int d_node = v;
			int diff = len - (x + 1) - 1;
			for (int i=0;i<20;i++) if ( (1 << i) & diff) d_node = up[d_node][i];
			sz_d = sz[d_node];
		}
		if (sz_d) f[down[v]] += sz_d - rem;
		//处理下部分}
		//处理中部分{
		int sz_m = 0;
		if (x + 1 <= len) {
			int m_node = v;
			int diff = len - (x + 1);
			for (int i=0;i<20;i++) if ((1 << i) & diff) m_node = up[m_node][i];
			sz_m = sz[m_node];
		}
		if (sz_m) {
			if (
				dis_up + x + 1 < dis_down + (len - (x + 1)) ||
				(dis_up + x + 1 == dis_down + (len - (x + 1)) && up_edge < down[v])
				) f[up_edge] += sz_m - (sz_d?sz_d:rem);
			else f[down[v]] += sz_m - (sz_d?sz_d:rem);
		}
		//处理中部分}
		//处理上部分{
		int sz_u = 0;
		if (x) {
			int u_node = v;
			int diff = len - 1;
			for (int i=0;i<20;i++) if ((1 << i) & diff) u_node = up[u_node][i];
			sz_u = sz[u_node];
		}
		if (sz_u) f[up_edge] += sz_u - (sz_m?sz_m:rem);
		//处理上部分}
		/*
		f[up_edge] += x;
		if (x + 1 <= len) {
			if (
				dis_up + x + 1 < dis_down + (len - (x + 1)) ||
				(dis_up + x + 1 == dis_down + (len - (x + 1)) && up_edge < down[v])
				)
				f[up_edge] ++;
			else f[down[v]] ++;
		}
		f[down[v]] += max(0,len - (x + 1));
		*/
		//处理这条边 }
		int all_sz = 0;
		int tv = v;
		int diff = len - 1;
		for (int i=0;i<20;i++) if ((1 << i) & diff) tv = up[tv][i];
		tot += sz[tv];
		dfs3(v,u,up_edge);
	}
	f[near] += sz[u] - 1 - tot;
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
		vector <int> mg;
		for (int i=0;i<k;i++) {
			int t;
			scanf("%d",&t);
			mg.push_back(t);
			key_node[t] = true;
		}
		vector <int> h = mg;
		sort(h.begin(),h.end(),cmp);
		stack <int> s;
		s.push(1);
		ins[1] = true;
		clear_g2();
		for (int i=0;i<h.size();i++) {
		//for (auto x:h) {
			int x = h[i];
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
		dfs2(1,-1);
		for (int i=0;i<mg.size();i++) f[mg[i]] = 0;
		dfs3(1,-1,-1);
		f[down[1]] ++;
		int cnt = 0;
		for (int i=0;i<mg.size();i++) {
			printf("%d%c",f[mg[i]],i==mg.size()-1?'\n':' ');
			cnt += f[mg[i]];
		}
		assert(cnt == n);
		for (int i=0;i<h.size();i++) key_node[h[i]] = false;
		//for (auto x:h) key_node[x] = false;
	}
	return 0;
}
