#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> g1[5005];//缩点前的图
int low[5005],dfn[5005],rt[5005],w[5005],ts,subg;
vector <int> ch[5005];
void tarjan(int u) {
	static stack <int> s;
	static bool ins[5005];
	dfn[u] = low[u] = ts++;
	s.push(u);
	ins[u] = true;
	for (auto v:g1[u]) {
		if (dfn[v] == -1) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if (ins[v]) low[u] = min(low[u],dfn[v]);
	}
	if (low[u] == dfn[u]) {
		subg ++;
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			ins[cur] = false;
			rt[cur] = subg;
			ch[subg].push_back(cur);
			w[subg] ++;//权值为点的数量
			if (cur == u) break;
		}
	}
}

vector <int> g2[5005];//缩点后的图
vector <int> g3[5005];//缩点后的反图
bool vis[5005];
int ticket[5005];
int dfs(int u,int r) {
	int res = w[u];
	vis[u] = true;
	for (auto v:g3[u]) {
		if (v == r || vis[v]) continue;
		res += dfs(v,u);
	}
	return res;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		ts = 0;
		subg = -1;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) {
			ticket[i] = 0;
			g1[i].clear();
			g2[i].clear();
			g3[i].clear();
			ch[i].clear();
			rt[i] = -1;
			w[i] = 0;
			dfn[i] = -1;
			low[i] = -1;
		}
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g1[u].push_back(v);
		}
		for (int i=0;i<n;i++) if (rt[i] == -1) tarjan(i);
		for (int u=0;u<n;u++) {
			int x = rt[u];
			for (auto v:g1[u]) {
				int y = rt[v];
				if (x != y) {
					g2[x].push_back(y);
					g3[y].push_back(x);
				}
			}
		}
		for (int i=0;i<=subg;i++) {
			for (int i=0;i<=subg;i++) vis[i] = false;
			ticket[i] = dfs(i,i) - 1;
		}
		//for (int i=0;i<=subg;i++) ticket[i] += w[i] - 1;
		set <int> ans;
		int max_num = 0;
		for (int i=0;i<=subg;i++) {
			if (ticket[i] < max_num) continue;
			if (ticket[i] > max_num) {
				ans.clear();
				max_num = ticket[i];
			}
			for (auto x:ch[i]) ans.insert(x);
		}
		printf("Case %d: %d\n",cas,max_num);
		bool f = false;
		for (auto x:ans) {
			if (f) putchar(' ');
			printf("%d",x);
			f = true;
		}
		printf("\n");
	}
	return 0;
}
