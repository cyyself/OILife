#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int NINF = 0x80000000;
struct rec {
	int x1,y1,x2,y2;
	rec() {
		x1 = NINF;
		y1 = NINF;
		x2 = INF;
		y2 = INF;
	}
}r[132674];
rec pre[132674];
rec suf[132674];
rec RecAnd(rec a,rec b) {
	rec ret;
	ret.x1 = max(a.x1,b.x1);
	ret.y1 = max(a.y1,b.y1);
	ret.x2 = min(a.x2,b.x2);
	ret.y2 = min(a.y2,b.y2);
	return ret;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
	pre[0] = r[0];
	for (int i=1;i<n;i++) pre[i] = RecAnd(pre[i-1],r[i]);
	suf[n-1] = r[n-1];
	for (int i=n-2;i>=0;i--) suf[i] = RecAnd(suf[i+1],r[i]);
	bool ans = false;
	for (int i=0;i<n && !ans;i++) {
		rec cur;
		if (i < n - 1) cur = RecAnd(cur,suf[i+1]);
		if (i >   0  ) cur = RecAnd(cur,pre[i-1]);
		if (cur.x1 <= cur.x2 && cur.y1 <= cur.y2) {
			printf("%d %d\n",cur.x1,cur.y1);
			ans = true;
		}
	}
	return 0;
}
