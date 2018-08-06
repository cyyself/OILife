#include <bits/stdc++.h>
int f[15][105][105];
int num[15];
int a,b,k;

int dfs(int dep,int ans1,int ans2,bool up_limited) {
	if (dep == 0) return (ans1 == 0) && (ans2 == 0);
	if (!up_limited && ~f[dep][ans1][ans2]) return f[dep][ans1][ans2];
	int ans = 0;
	int up = 9;
	if (up_limited) up = num[dep];
	for (int i=0;i<=up;i++) {
		ans += dfs(dep-1,(ans1+i)%k,(ans2*10+i)%k,up_limited && i == up);
	}
	if (!up_limited) f[dep][ans1][ans2] = ans;
	return ans;
}
int solve(int x) {
	int len = 0;
	while (x) {
		num[++len] = x % 10;
		x /= 10;
	}
	return dfs(len,0,0,true);
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		scanf("%d%d%d",&a,&b,&k);
		if (k >= 90) printf("Case %d: %d\n",c,0);
		else {
			memset(f,-1,sizeof(f));
			printf("Case %d: %d\n",c,solve(b)-solve(a-1));
		}
	}
	return 0;
}
