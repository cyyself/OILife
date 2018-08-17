#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct cata {
	int v,k,c,l;
	friend bool operator < (const cata &a,const cata &b) {
		return a.v < b.v;
	}
}c[1005];
int f[1005];//f[i]表示前i组的最小花费
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i=1;i<=n;i++) scanf("%d%d%d%d",&c[i].v,&c[i].k,&c[i].c,&c[i].l);
		sort(c+1,c+1+n);
		memset(f,0x3f,sizeof(f));
		f[0] = 0;
		for (int i=1;i<=n;i++) {
			int cur = c[i].k + c[i].c * c[i].l;
			int pre = f[i-1];
			int replace = 0;
			for (int j=i-1;j>=1;j--) {
				replace += c[j].l;
				pre = min(pre,replace * c[i].c + f[j-1]);
			}
			f[i] = cur + pre;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
