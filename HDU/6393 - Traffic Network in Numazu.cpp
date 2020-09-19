#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
pair <pair<int,int>,int> e[maxn];
vector <int> g[maxn];
vector <pair<int,int> > g2[maxn];
int fa[maxn];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int n;
namespace cycle {
	int up[maxn];
	void dfs1(int u,int fa) {
		for (auto v:g[u]) {
			if (v == fa) continue;
			up[v] = u;
			dfs1(v,u);
		}
	}
	void get_path(int u,vector <int> &path) {
		while (u != 1) {
			path.push_back(u);
			u = up[u];
		}
		path.push_back(1);
	}
	vector <int> path1,path2;
}
vector <int> cycle_path;
int cycle_l[maxn],cycle_r[maxn];
bool in_cycle[maxn];
//dfs sequence {
int ts;
int st[maxn*2],ed[maxn*2];
int belong[maxn*2];//每个id所属的环上位置
int id[maxn];//这个点所属树的ID(同一位置有多棵树)
int pos[maxn];//环上这个点的位置
int up[maxn][20];
int dep[maxn];
int idc;
struct BIT {
	long long sum[maxn*2];
	void init() {
		for (int i=1;i<=2*n+1;i++) sum[i] = 0;
	}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int x,long long d) {
		for (int i=x;i<=2*n+1;i+=lowbit(i)) {
			sum[i] += d;
		}
	}
	long long query(int x) {
		long long res = 0;
		for (int i=x;i>=1;i-=lowbit(i)) {
			res += sum[i];
		}
		return res;
	}
}cycle_len,dfs_seq;//维护向左走的距离,维护每棵树内的距离
void dfs2(int u,int w,int idn) {
	ts ++;
	id[u] = idn;
	st[u] = ts;
	dfs_seq.add(ts,w);
	for (int i=1,len=1;len<=dep[u];i++,len <<= 1) up[u][i] = up[up[u][i-1]][i-1];
	for (auto x:g2[u]) {
		int v = x.first;
		if (v == up[u][0]) continue;
		dep[v] = dep[u] + 1;
		up[v][0] = u;
		dfs2(v,x.second,idn);
	}
	ts ++;
	ed[u] = ts;
	dfs_seq.add(ts,-w);
}
//dfs sequence }
long long shortest_in_cycle(int x,int y) {
	if (x == y) return 0;
	else {
		if (x > y) swap(x,y);
		long long dis1 = cycle_len.query(y) - cycle_len.query(x);
		long long dis2 = cycle_len.query(x) + cycle_len.query(cycle_path.size()) - cycle_len.query(y);
		return min(dis1,dis2);
	}
}

int LCA(int u,int v) {
	if (dep[u] > dep[v]) swap(u,v);
	int diff = dep[v] - dep[u];
	for (int i=0,two=1;diff != 0;two <<= 1,i++) {
		if (diff & two) {
			v = up[v][i];
			diff -= two;
		}
	}
	if (u == v) return u;
	for (int i=log(dep[u])/log(2);i>=0;i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		ts = 0;
		idc = 0;
		int q;
		scanf("%d%d",&n,&q);
		for (int i=1;i<=n;i++) {
			for (int j=0;j<20;j++) up[i][j] = 0;
			fa[i] = i;
			in_cycle[i] = false;
			g[i].clear();
			g2[i].clear();
		}
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",&e[i].first.first,&e[i].first.second,&e[i].second);
		}
		int rem_u = -1, rem_v = -1, rem_w = -1;
		for (int i=1;i<=n;i++) {
			int u = e[i].first.first;
			int v = e[i].first.second;
			int w = e[i].second;
			if (find(u) != find(v)) {
				g[u].push_back(v);
				g[v].push_back(u);
				fa[find(u)] = find(v);
			}
			else {
				assert(rem_u == -1);
				rem_u = u;
				rem_v = v;
				rem_w = w;
			}
		}
		assert(rem_u != -1);
		cycle::dfs1(1,-1);
		cycle::path1.clear();
		cycle::path2.clear();
		cycle_path.clear();
		dfs_seq.init();
		cycle_len.init();
		cycle::get_path(rem_u,cycle::path1);
		cycle::get_path(rem_v,cycle::path2);
		reverse(cycle::path1.begin(),cycle::path1.end());
		reverse(cycle::path2.begin(),cycle::path2.end());
		for (int i=min(cycle::path1.size(),cycle::path2.size())-1;i>=0;i--) {
			if (cycle::path1[i] == cycle::path2[i]) {
				for (int j=cycle::path1.size()-1;j>=i;j--) {
					cycle_path.push_back(cycle::path1[j]);
				}
				for (int j=i+1;j<cycle::path2.size();j++) {
					cycle_path.push_back(cycle::path2[j]);
				}
				break;
			}
		}
		for (int i=0;i<cycle_path.size();i++) {
			in_cycle[cycle_path[i]] = true;
			cycle_l[cycle_path[i]] = cycle_path[(i+cycle_path.size()-1)%cycle_path.size()];
			cycle_r[cycle_path[i]] = cycle_path[(i+cycle_path.size()+1)%cycle_path.size()];
			pos[cycle_path[i]] = i + 1;
		}
		queue <pair<int,pair<int,int> > > to_dfs;//u,{dis,pos}
		for (int i=1;i<=n;i++) {
			if (!in_cycle[e[i].first.first] && !in_cycle[e[i].first.second]) {
				g2[e[i].first.first].emplace_back(e[i].first.second,e[i].second);
				g2[e[i].first.second].emplace_back(e[i].first.first,e[i].second);
			}
			else if (!in_cycle[e[i].first.first] && in_cycle[e[i].first.second]) {
				to_dfs.push({e[i].first.first,make_pair(e[i].second,pos[e[i].first.second])});
			}
			else if (in_cycle[e[i].first.first] && !in_cycle[e[i].first.second]) {
				to_dfs.push({e[i].first.second,make_pair(e[i].second,pos[e[i].first.first])});
			}
			else {
				if (cycle_l[e[i].first.first] == e[i].first.second) {
					cycle_len.add(pos[e[i].first.first],e[i].second);
				}
				else {
					cycle_len.add(pos[e[i].first.second],e[i].second);
				}
			}
		}
		while (!to_dfs.empty()) {
			auto cur = to_dfs.front();
			to_dfs.pop();
			idc ++;
			belong[idc] = cur.second.second;
			dep[cur.first] = 0;
			dfs2(cur.first,cur.second.first,idc);
		}
		while (q --) {
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if (op == 0) {
				int u = e[x].first.first;
				int v = e[x].first.second;
				if (in_cycle[v]) swap(u,v);
				if (!in_cycle[u] && !in_cycle[v]) {
					if (up[v][0] == u) swap(u,v);
					dfs_seq.add(st[u],-e[x].second);
					dfs_seq.add(ed[u],e[x].second);
					e[x].second = y;
					dfs_seq.add(st[u],e[x].second);
					dfs_seq.add(ed[u],-e[x].second);
				}
				else if (in_cycle[u] && !in_cycle[v]) {
					dfs_seq.add(st[v],-e[x].second);
					dfs_seq.add(ed[v],e[x].second);
					e[x].second = y;
					dfs_seq.add(st[v],e[x].second);
					dfs_seq.add(ed[v],-e[x].second);
				}
				else {
					if (cycle_l[u] == v) swap(u,v);
					cycle_len.add(pos[v],-e[x].second);
					e[x].second = y;
					cycle_len.add(pos[v],e[x].second);
				}
			}
			else {
				if (in_cycle[y]) swap(x,y);
				if (in_cycle[x] && in_cycle[y]) {
					printf("%lld\n",shortest_in_cycle(pos[x],pos[y]));
				}
				else if (in_cycle[x] && !in_cycle[y]) {
					long long ans = dfs_seq.query(st[y]) + shortest_in_cycle(pos[x],belong[id[y]]);
					printf("%lld\n",ans);
				}
				else if (!in_cycle[x] && !in_cycle[y]) {
					if (id[x] == id[y]) {
						int lca = LCA(x,y);
						long long ans = dfs_seq.query(st[x]) + dfs_seq.query(st[y]) - 2 * dfs_seq.query(st[lca]);
						printf("%lld\n",ans);
					}
					else {
						long long ans = dfs_seq.query(st[x]) + dfs_seq.query(st[y]) + shortest_in_cycle(belong[id[x]],belong[id[y]]);
						printf("%lld\n",ans);
					}
				}
			}
		}
	}
	return 0;
}
