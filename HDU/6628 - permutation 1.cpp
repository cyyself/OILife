#include <bits/stdc++.h>
using namespace std;
set <int> s;
int n;
int ans[25];
long long jc[25];
void dfs(int dep,long long k) {
	if (dep == n + 1) return;
	else {
		int st = *s.rbegin() - n + 1;
		int ed = *s.begin() + n - 1;
		for (int cur=st;cur<=ed;cur++) if (s.find(cur) == s.end()) {
			s.insert(cur);
			long long range = (n - (*s.rbegin() - *s.begin())) * jc[n - dep];
			if (range < k) {
				k -= range;
				s.erase(cur);
			}
			else {
				ans[dep] = cur;
				dfs(dep+1,k);
				break;
			}
		}
		assert(true);
	}
}
int main() {
	jc[0] = 1;
	for (int i=1;i<=20;i++) jc[i] = jc[i-1] * i;
	int T;
	scanf("%d",&T);
	while (T --) {
		s.clear();
		s.insert(0);
		long long k;
		scanf("%d%lld",&n,&k);
		dfs(2,k);
		int a1 = n - *s.rbegin();
		printf("%d",a1);
		for (int i=2;i<=n;i++) printf(" %d",a1 + ans[i]);
		printf("\n");
	}
	return 0;
}
