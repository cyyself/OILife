#include <cstdio>
int f[2005];
int r[2005];
int find(int x) {
	if (f[x] == x) return x;
	int t = find(f[x]);
	r[x] = (r[x] + r[f[x]]) % 2;
	return f[x] = t;
}
bool ans;
void uni(int x,int y) {
	int xr = find(x);
	int yr = find(y);
	if (xr == yr) {
		if (r[x] == r[y]) ans = true;
	}
	else {
		f[xr] = yr;
		r[xr] = (r[x] + r[y] + 1) % 2;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n,m;
		scanf("%d%d",&n,&m);
		ans = false;
		for (int i=1;i<=n;i++) {
			f[i] = i;
			r[i] = 0;
		}
		while (m --) {
			int x,y;
			scanf("%d%d",&x,&y);
			uni(x,y);
		}
		printf("Scenario #%d:\n",c);
		if (ans) printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}
