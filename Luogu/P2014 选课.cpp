#include <bits/stdc++.h>
using std::max;
int head[305];
int next[305];
int to[305];
int w[305];
int ecnt = 0;
int m;
void add(int _u,int _v,int _w) {
	next[ecnt] = head[_u];
	head[_u] = ecnt;
	to[ecnt] = _v;
	w[ecnt] = _w;
	ecnt ++;
}
int f[305][305];
void dfs(int n) {
	for (int e=head[n];e != -1;e=next[e]) {
		int v = to[e];
		dfs(v);
		for (int j=m;j>=1;j--)
			for (int k=1;k<=j;k++)
				f[n][j] = max(f[n][j],f[n][j-k]+f[v][k-1]+w[e]);
	}
}
int main() {
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int k,s;
		scanf("%d%d",&k,&s);
		add(k,i,s);
	}
	dfs(0);
	printf("%d\n",f[0][m]);
	return 0;
}