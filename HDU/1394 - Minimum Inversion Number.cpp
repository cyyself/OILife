#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int r[5005];
int tr[5005];
int n;
inline int lowbit(int x) {
	return x & (-x);
}
inline long long sum(int x) {
	long long ret = 0;
	for (int i=x;i>=1;i-=lowbit(i)) ret += tr[i];
	return ret;
}
inline void add(int x,int d) {
	for (int i=x;i<=n;i+=lowbit(i)) tr[i] += d;
}
int main() {
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i=1;i<=n;i++) {
			scanf("%d",&r[i]);
			r[i] ++;
		}
		//因为是1~n的排列所以不用做离散化了
		int ans = INF;
		memset(tr,0,sizeof(tr));
		int cur = 0;
		for (int i=n;i>=1;i--) {
			cur += sum(r[i]-1);
			add(r[i],1);
		}
		ans = min(ans,cur);
		for (int i=1;i<=n;i++) {
			cur -= r[i] - 1;
			cur += n - r[i];
			ans = min(cur,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
