#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long f[20][4];
int digit[20];
long long dfs(int dep,int avail,bool uplimited) {
	if (dep == 0) return 1;
	if (!uplimited && f[dep][avail] != INF) return f[dep][avail];
	int up = 9;
	if (uplimited) up = digit[dep];
	long long cur = 0;
	for (int i=0;i<=up;i++) {
		if (i == 0) cur += dfs(dep-1,avail,i == up && uplimited);
		else if (avail > 0) cur += dfs(dep-1,avail-1,i == up && uplimited);
	}
	if (!uplimited) f[dep][avail] = cur;
	return cur;
}
long long solve(long long x) {
	memset(f,0x3f,sizeof(f));
	int cnt = 0;
	while (x) {
		digit[++cnt] = x % 10;
		x /= 10;
	}
	return dfs(cnt,3,true);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
