//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
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
	for (auto &v:g1[u]) {
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
bool key_node[maxn];
int getdis(int u,int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u,v)] + 1;//这个题目的dis定义是+1的
}
pair<int,int> pt[maxn];//每个名字的最远点对
int f[maxn];//这个点往下走最深的点
void dfs2(int u,int fa,int name) {
	if (key_node[u]) f[u] = u;
	for (auto &v:g2[u]) {
		if (v == fa) continue;
		dfs2(v,u,name);
	}
	set <pair<int,int> > s;
	for (auto &v:g2[u]) {
		if (v == fa) continue;
		s.insert({dep[f[v]],f[v]});
		if (s.size() > 2) {
			s.erase(s.begin());
		}
	}
	if (!s.empty()) {
		auto x = s.rbegin();
		f[u] = x->second;
	}
	if (key_node[u] && getdis(u,f[u]) > getdis(pt[name].first,pt[name].second)) {
		pt[name].first = u;
		pt[name].second = f[u];
	}
	if (s.size() >= 2) {
		auto x = s.rbegin();
		auto y = next(x);
		if (getdis(x->second,y->second) > getdis(pt[name].first,pt[name].second)) {
			pt[name].first = x->second;
			pt[name].second = y->second;
		}
	}
}
map <int,vector<int> > mem;
map <string,int> ls_name;
int main() {
	int n,q;
	while (scanf("%d%d",&n,&q) == 2) {
		mem.clear();
		ls_name.clear();
		ts = 0;
		int lscnt = 0;
		for (int i=1;i<=n;i++) {
			string t;
			cin >> t;
			if (ls_name.find(t) == ls_name.end()) {
				ls_name[t] = ++lscnt;
			}
			mem[ls_name[t]].push_back(i);
			g1[i].clear();
			for (int j=0;j<20;j++) up[i][j] = 0;//此处调了一个半小时，纪念
		}
		for (int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g1[u].push_back(v);
			g1[v].push_back(u);
		}
		dfs(1,-1);
		for (auto &tmp:mem) {
			auto name = tmp.first;
			auto &h = tmp.second;
			for (auto &t:h) key_node[t] = true;
			sort(h.begin(),h.end(),cmp);
			stack <int> s;
			s.push(1);
			ins[1] = true;
			clear_g2();
			for (auto &x:h) {
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
			pt[name] = make_pair(h[0],h[0]);
			dfs2(1,-1,name);
			for (auto &x:h) key_node[x] = false;
		}
		while (q --) {
			string xx,yy;
			cin >> xx >> yy;
			if (!ls_name[xx] || !ls_name[yy]) printf("-1\n");
			else {
				int ans = 0;
				int x = ls_name[xx], y = ls_name[yy];
				ans = max(ans,getdis(pt[x].first,pt[y].first));
				ans = max(ans,getdis(pt[x].first,pt[y].second));
				ans = max(ans,getdis(pt[x].second,pt[y].first));
				ans = max(ans,getdis(pt[x].second,pt[y].second));
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
