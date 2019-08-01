#include <bits/stdc++.h>
using namespace std;
int n;
int a[5000],c[5000];
vector <int> g[5000];
void color(int u,int rt) {
	for (auto v:g[u]) {
		if (v == rt) continue;
		if (~c[v]) continue;
		c[v] = c[u] ^ 1;
		color(v,u);
	}
}
bool s[5000],t[5000];
int l[5000],r[5000];
bool dfs(int u) {
	s[u] = true;
	for (auto v:g[u]) {
		if (t[v]) continue;
		t[v] = true;
		if (l[v] == -1 || dfs(l[v])) {
			l[v] = u;
			r[u] = v;
			return true;
		}
	}
	return false;
}
void work() {
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	int match = 0;
	for (int i=0;i<n;i++) if (c[i] == 0) {
		memset(t,false,sizeof(t));
		match += dfs(i);
	}
	memset(s,false,sizeof(s));
	memset(t,false,sizeof(t));
	for (int i=0;i<n;i++) if (c[i] == 0 && r[i] == -1) dfs(i);
	printf("%d\n",n-match);
	for (int i=0;i<n;i++) if (!((c[i] == 0 && !s[i]) || (c[i] == 1 && t[i]))) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main() {
	memset(c,-1,sizeof(c));
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	n = unique(a,a+n) - a;
	for (int i=0;i<n;i++) 
		for (int j=0;j<i;j++) 
			if (__builtin_popcount(a[i] ^ a[j]) == 1) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
	for (int i=0;i<n;i++) if (c[i] == -1) {
		c[i] = 0;
		color(i,-1);
	}
	work();
	return 0;
}
