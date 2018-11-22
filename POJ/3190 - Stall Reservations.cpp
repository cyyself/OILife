#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct cow{
	int l,r;
	int seq;
	friend bool operator < (const cow &a,const cow &b) {
		return a.l < b.l;
	}
}c[50005];
struct DATA {
	int num;
	int end;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.end > b.end;
	}
};
int ans[50005];
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		for (int i=0;i<n;i++) {
			scanf("%d%d",&c[i].l,&c[i].r);
			c[i].seq = i;
		}
		sort(c,c+n);
		priority_queue <DATA> q;
		q.push((DATA){1,c[0].r});
		ans[c[0].seq] = 1;
		for (int i=1;i<n;i++) {
			DATA cur = q.top();
			if (c[i].l <= cur.end) {
				q.push((DATA){q.size()+1,c[i].r});
				ans[c[i].seq] = q.size();
			}
			else {
				q.pop();
				q.push((DATA){cur.num,c[i].r});
				ans[c[i].seq] = cur.num;
			}
		}
		printf("%lu\n",q.size());
		for (int i=0;i<n;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
