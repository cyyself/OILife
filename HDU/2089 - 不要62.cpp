#include <bits/stdc++.h>
using namespace std;
int a,b;
int num[20];
int f[20][2];
int dfs(int dep,bool last6,bool up_limited) {
	if (dep == 0) return 1;
	if (!up_limited && f[dep][last6]) return f[dep][last6];
	int cnt = 0;
	int up = 9;
	if (up_limited) up = num[dep];
	for (int i=0;i<=up;i++) {
		if (i == 4 || (last6 && i == 2) ) continue;
		cnt += dfs(dep-1,i == 6,up_limited && i == up);
	}
	if (!up_limited) f[dep][last6] = cnt;
	return cnt;
}
int solve(int x) {
	memset(num,0,sizeof(num));
	int k = 0;
	while (x) {
		num[++k] = x % 10;
		x /= 10;
	}
	return dfs(k,false,true);
}
int main() {
	while (scanf("%d%d",&a,&b) == 2) {
		if (a == 0 && b == 0) break;
		int ans = solve(b) - solve(a-1);
		printf("%d\n",ans);
	}
	return 0;
}
