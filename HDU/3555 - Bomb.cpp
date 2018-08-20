#include <bits/stdc++.h>
using namespace std;
long long f[20][2];
int num[20];
long long dfs(int dep,bool exist4,bool uplimited) {
	if (dep == -1) return 1;
	else {
		if (!uplimited && f[dep][exist4] != -1) return f[dep][exist4];
		int up = 9;
		if (uplimited) up = num[dep];
		long long cur = 0;
		for (int i=0;i<=up;i++) {
			if (exist4 && i == 9) continue;
			cur += dfs(dep-1,i == 4,uplimited && i == up);
		}
		if (!uplimited) f[dep][exist4] = cur;
		return cur;
	}
}
long long solve(long long x) {
	int len = 0;
	while (x) {
		num[len++] = x % 10;
		x /= 10;
	}
	return dfs(len-1,false,true);
}
int main() {
	memset(f,-1,sizeof(f));
	int T;
	scanf("%d",&T);
	while (T--) {
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",n-solve(n)+1);
	}
	return 0;
}
