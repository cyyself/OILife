#include <bits/stdc++.h>
using namespace std;
long long v[28][28];
long long suf[28];
int n;
struct Call {
	int dep,s;
	long long cur;
}s[1005];
int main() {
	int n;
	scanf("%d",&n);
	long long ans = 0;
	for (int i=0;i<2*n;i++) {
		long long tmp[28];
		for (int j=0;j<2*n;++j) {
			scanf("%lld",&v[i][j]);
			tmp[j] = v[i][j];
		}
		sort(tmp,tmp+2*n);
		for (int j=2*n-1;j>=n;j--) suf[i] += tmp[j];
	}
	for (int i=2*n-2;i>=0;i--) suf[i] += suf[i+1];
	int top = -1;
	s[++top] = {0,0,0};
	while (top >= 0) {
		register Call cur = s[top];
		top --;
		int cnt = __builtin_popcount(cur.s);
		if (cnt < n) {
			register long long add = 0;
			for (register int j=0;j<cur.dep;++j) if (!((cur.s>>j)&1)) add += v[cur.dep][j];
			if (cur.dep + 1 == 2 * n) {
				if (cur.cur + add > ans) ans = cur.cur + add;
			}
			else if (cur.cur+add+suf[cur.dep+1] >= ans) s[++top] = {cur.dep+1,cur.s|(1<<cur.dep),cur.cur+add};
		}
		if (cnt + (2 * n - cur.dep - 1) >= n) {
			register long long add = 0;
			for (register int j=0;j<cur.dep;++j) if (((cur.s>>j)&1)) add += v[cur.dep][j];
			if (cur.dep + 1 == 2 * n) {
				if (cur.cur + add > ans) ans = cur.cur + add;
			}
			else if (cur.cur+add+suf[cur.dep+1] >= ans) s[++top] = {cur.dep+1,cur.s,cur.cur+add};
		}
	}
	printf("%lld\n",ans);
	return 0;
}