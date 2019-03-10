#include <bits/stdc++.h>
using namespace std;
long long ans;
long long w;
long long c[9];
void dfs(long long dep,long long cur) {
	if (dep == 0) ans = max(ans,cur);
	else {
		for (long long i=min((w-cur)/dep,c[dep]),cnt=9;i>=0 && cnt >= 0;i--,cnt--) {
			dfs(dep-1,cur+i*dep);
		}
	}
}
int main() {
	scanf("%lld",&w);
	for (int i=1;i<=8;i++) scanf("%lld",&c[i]);
	dfs(8,0);
	printf("%lld\n",ans);
	return 0;
}
