#include <bits/stdc++.h>
using namespace std;
int f[105][2];
int n,k,d;
int dfs(int rem,bool exist) {
	if (~f[rem][exist]) return f[rem][exist];
	if (rem == 0 && exist) return f[rem][exist] = 1;
	int cur = 0;
	for (int i=1;i<=min(rem,k);i++) {
		cur += dfs(rem-i,exist || (i >= d));
		cur %= 1000000007;
	}
	f[rem][exist] = cur;
	return f[rem][exist];
}
int main() {
	memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&k,&d);
	printf("%d\n",dfs(n,false));
	return 0;
}
