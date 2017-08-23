#include <bits/stdc++.h>
int c[5],d[5];
unsigned long long f[100005];
unsigned long long ans;
void dfs(int p,int k,int s) {
	if (s < 0) return;
	if (p == 4) {
		if (k % 2) ans -= f[s];
		else ans += f[s];
		return;
	}
	dfs(p+1,k+1,s-(d[p]+1)*c[p]);
	dfs(p+1,k,s);
}
int main() {
	int tot;
	for (int i=0;i<4;i++) scanf("%d",&c[i]);
	scanf("%d",&tot);
	f[0] = 1;
	for (int i=0;i<4;i++)
		for (int j=c[i];j<=100000;j++) f[j] += f[j-c[i]];
	while (tot--) {
		for (int i=0;i<4;i++) scanf("%d",&d[i]);
		int s;
		scanf("%d",&s);
		ans = 0;
		dfs(0,0,s);
		printf("%llu\n",ans);
	}
	return 0;
}