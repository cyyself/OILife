#include <cstdio>
int f[50005];
int r[50005];
int find(int x) {
	if (f[x] == x) return x;
	int y = f[x];
	int t = find(f[x]);
	r[x] = (r[x] + r[y]) % 3;
	return f[x] = t;
}
int ans;
void uni(int o,int x,int y) {
	int xr = find(x);
	int yr = find(y);
	if (xr == yr) {
		if ( (r[y]-r[x]+3) % 3 != o-1) ans ++;
	}
	else {
		f[xr] = yr;
		r[xr] = (r[y]-r[x]-(o-1)+3) % 3;
	}
}

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		f[i] = i;
		r[i] = 0;
	}
	ans = 0;
	while (k --) {
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if (x > n || y > n || (o == 2 && x == y)) ans ++;
		else uni(o,x,y);
	}
	printf("%d\n",ans);
	return 0;
}
