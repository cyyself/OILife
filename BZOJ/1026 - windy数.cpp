#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[15][10];
int digit[15];
int dfs(int dep,int pre,bool uplimited,bool downlimited) {
	if (dep < 0) return 1;
	if (!downlimited && !uplimited && f[dep][pre] != INF) return f[dep][pre];
	int up = 9;
	if (uplimited) up = digit[dep];
	int cur = 0;
	for (int i=0;i<=up;i++) {
		if (!downlimited && abs(i - pre) <= 1) continue;
		cur += dfs(dep-1,i,uplimited && i == up,downlimited && i == 0);
	}
	if (!uplimited && !downlimited) f[dep][pre] = cur;
	return cur;
}
int solve(int x) {
	int cnt = 0;
	while (x) {
		digit[cnt ++] = x % 10;
		x /= 10;
	}
	return dfs(cnt-1,0x3f3f3f3f,true,true);
}
int main() {
	memset(f,0x3f,sizeof(f));
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",solve(b)-solve(a-1));
	return 0;
}
