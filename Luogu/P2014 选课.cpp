#include <bits/stdc++.h>
using std::max;
int head[305];
struct Edge {
	int v,w;
	int c;//cost
	int next;
}e[305];
int ecnt = 0;
int f[305][305];
void AddEdge(int u,int v,int w,int c) {
	e[ecnt].next = head[u];
	head[u] = ecnt;
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].c = c;
	ecnt ++;
}
void dfs(int cur,int maxp) {//p是当前物品的价格,w是价值(价格*重要度)
	for (int i=head[cur];i != -1;i = e[i].next) {
		if (maxp <= e[i].c) continue;
		for (int j=0;j<=maxp-e[i].c;j++) f[e[i].v][j] = f[cur][j] + e[i].w;
		dfs(e[i].v,maxp-e[i].c);
		for (int j=maxp;j>=e[i].c;j--)
			f[cur][j] = max(f[cur][j],f[e[i].v][j-e[i].c]);
	}
}
int main() {
	int n,m;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int k,s;
		scanf("%d%d",&k,&s);
		AddEdge(k,i,s,1);
	}
	dfs(0,m);
	printf("%d\n",f[0][m]);
	return 0;
}
