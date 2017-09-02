#include <bits/stdc++.h>
using std::max;
int head[65];
struct Edge {
	int v,w;//w是权值，相当于输入数据的p*v
	int p;//价格，相当于输入数据的v
	int next;
}e[65];
int ecnt = 0;
int f[65][32005];
int n,m;
void AddEdge(int u,int v,int w,int p) {
	e[ecnt].next = head[u];
	head[u] = ecnt;
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].p = p;
	ecnt ++;
}
void dfs(int cur,int maxp) {//p是当前物品的价格,w是价值(价格*重要度)
	for (int i=head[cur];i != -1;i = e[i].next) {
		if (maxp <= e[i].p) continue;
		for (int j=0;j<=maxp-e[i].p;j++) f[e[i].v][j] = f[cur][j] + e[i].w;
		dfs(e[i].v,maxp-e[i].p);
		for (int j=maxp;j>=e[i].p;j--)
			f[cur][j] = max(f[cur][j],f[e[i].v][j-e[i].p]);
	}
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int v,p,q;
		scanf("%d%d%d",&v,&p,&q);
		AddEdge(q,i,v*p,v);
	}
	dfs(0,n);
	printf("%d\n",f[0][n]);
	return 0;
}
