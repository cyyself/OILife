#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
const long long mo = 1000000007;
map <int,int> ca,cb;
int dfs(int *arr,int i) {
	int t = arr[i];
	arr[i] = -1;
	int ret = 1 + (t!=-1?dfs(arr,t):0);
	return ret;
}
int main() {
	int n,m;
	int cas = 1;
	while (scanf("%d%d",&n,&m) == 2) {
		ca.clear();
		cb.clear();
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<m;i++) scanf("%d",&b[i]);
		for (int i=0;i<n;i++) if (a[i] != -1) {
			int t = dfs(a,i) - 1;
			//printf("(debug) a%d\n",t);
			ca[t] ++;
		}
		for (int i=0;i<m;i++) if (b[i] != -1) {
			int t = dfs(b,i) - 1;
			//printf("(debug) b%d\n",t);
			cb[t] ++;
		}
		long long ans = 1;
		for (auto x:ca) {
			long long cur = 0;
			for (auto y:cb) {
				if (x.first % y.first == 0) {
					cur += (long long)y.first * y.second;
					cur %= mo;
				}
			}
			for (int i=0;i<x.second;i++) {
				ans *= cur;
				ans %= mo;
			}
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
	return 0;
}
