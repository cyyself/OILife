#include <bits/stdc++.h>
using namespace std;
int n,m;
int w[300005];
struct Player {
	int u;
	int v;
	int len;
	int lca;
}p[300005];
int ehead[300005];
struct Edge {//存储树
	int v;
	int next;
}e[600005];
int ecnt = 0;
inline void AddEdge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = ehead[u];
	ehead[u] = ecnt;
	ecnt ++;
}
int qhead[300005];
struct Query {//LCA查询
	int v;
	int next;
}q[600005];
int qcnt = 0;
inline void AddQuery(int u,int v) {
	q[qcnt].v = v;
	q[qcnt].next = qhead[u];
	qhead[u] = qcnt;
	qcnt ++;
}
int f[300005];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
inline void uni(int u,int v) {
	f[find(u)] = find(v);
}
bool vis[300005];
int dep[300005];
int maxdep;

void tarjan(int u) {
	vis[u] = true;
	maxdep = max(dep[u],maxdep);
	for (int i=ehead[u];i != -1;i = e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			dep[v] = dep[u] + 1;
			tarjan(v);
			uni(v,u);
		}
	}
	for (int i=qhead[u];i != -1;i = q[i].next) {
		int v = q[i].v;
		if (vis[v]) {
			int pn = i / 2;//加入的时候按顺序
			p[pn].lca = find(v);
			p[pn].len = dep[p[pn].u] + dep[p[pn].v] - dep[p[pn].lca] * 2;
		}
	}
}

int tong[600005];
int scnt[300005];//每个点作为起点的次数
vector <int> len1[300005],len2[300005],len3[300005];
/*
	len1[i]:存储lca为i的人的起点的深度
	len2[i]:存储终点为i的人的终点的深度减去这个人走的总长 
	len3[i]:存储lca为i的人的终点的深度减去这个人走的总长
*/
int ans[300005];
void dfs(int u) {
	int now = dep[u] + w[u];
	int tmp = tong[now];
	for (int i=ehead[u];i != -1;i = e[i].next) {
		int v = e[i].v;
		if (dep[u] < dep[v]) dfs(v);
	}
	tong[dep[u]] += scnt[u];
	if (now <= maxdep) ans[u] += tong[now] - tmp;
	for (int i=len1[u].size()-1;i>=0;i--) {
		tong[len1[u][i]] --;
	}
}
void dfs2(int u) {
	int now = dep[u] - w[u] + 300000;
	int pre = tong[now];
	for (int i=ehead[u];i != -1;i = e[i].next) {
		int v = e[i].v;
		if (dep[u] < dep[v]) dfs2(v);
	}
	for (int i=len2[u].size()-1;i>=0;i--) {
		tong[len2[u][i]+300000] ++;
	}
	ans[u] += tong[now] - pre;
	for (int i=len3[u].size()-1;i>=0;i--) {
		tong[len3[u][i]+300000] --;
	}
}
int main() {
	memset(ehead,-1,sizeof(ehead));
	memset(qhead,-1,sizeof(qhead));
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&p[i].u,&p[i].v);
		AddQuery(p[i].u,p[i].v);
		AddQuery(p[i].v,p[i].u);
	}
	dep[1] = 1;
	tarjan(1);
	//for (int i=0;i<m;i++) printf("lca[%d]=%d\n",i,p[i].lca);
	for (int i=0;i<m;i++) {
		if (dep[p[i].u] - dep[p[i].lca] == w[p[i].lca]) ans[p[i].lca] --;
	}
	for (int i=0;i<m;i++) {
		scnt[p[i].u] ++;
		len1[p[i].lca].push_back(dep[p[i].u]);
	}
	dfs(1);
	memset(tong,0,sizeof(tong));
	for (int i=0;i<m;i++) {
		int now = dep[p[i].v] - p[i].len;
		len2[p[i].v].push_back(now);
		len3[p[i].lca].push_back(now);
	}
	dfs2(1);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
