#include <cstdio>
int k;
int c[2005][2005];
int mem[2005][2005];
int ans[2005][2005];
int main() {
	int t;
	scanf("%d%d",&t,&k);
	c[1][0] = 1;
	c[1][1] = 1;
	for (int i=2;i<=2000;i++) {
		c[i][0] = 1;
		for (int j=1;j<=i;j++) {
			c[i][j] = (c[i-1][j] % k + c[i-1][j-1] % k) % k;
			mem[i][j] = mem[i][j-1];
			if (c[i][j] % k == 0) {
				mem[i][j] ++;
			}
		}
		for (int j=i+1;j<=2000;j++) mem[i][j] = mem[i][i];	
	}
	for (int i=1;i<=2000;i++) for (int j=1;j<=2000;j++) ans[i][j] = ans[i-1][j] + mem[i][j];
	while(t --) {
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",ans[n][m]);
	}
	return 0;
}