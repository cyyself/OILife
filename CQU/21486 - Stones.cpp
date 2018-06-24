#include <bits/stdc++.h>
using namespace std;
struct stone {
	int p;
	int d;
	friend bool operator < (const stone &a,const stone &b) {
		if (a.p < b.p) return false;
		if (a.p == b.p && a.d < b.d) return false;
		return true;
	}
};
priority_queue <stone> q;
int main() {
	int T;
	scanf("%d",&T);
	bool odd = true;
	while (T--) {
		int n;
		scanf("%d",&n);
		while (n--) {
			int p,d;
			scanf("%d%d",&p,&d);
			q.push((stone){p,d});
		}
		int last = -1;
		while (!q.empty()) {
			stone cur = q.top();
			q.pop();
			last = cur.p;
			if (odd) q.push((stone){cur.p+cur.d,cur.d});
			odd = !odd;
		}
		printf("%d\n",last);
	}
	return 0;
}
