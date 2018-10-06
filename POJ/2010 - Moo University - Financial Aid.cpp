#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct cow {
	int s,a;
	friend bool operator < (const cow &a,const cow &b) {
		return a.s < b.s;
	}
}c[100005];
int l[100005];
int r[100005];
int main() {
	int N,C,F;
	scanf("%d%d%d",&N,&C,&F);
	int len = (N-1) / 2;
	for (int i=0;i<C;i++) scanf("%d%d",&c[i].s,&c[i].a);
	sort(c,c+C);
	int sum = 0;
	priority_queue <int> q;
	for (int i=0;i<C;i++) {
		q.push(c[i].a);
		sum += c[i].a;
		if (q.size() > len) {
			sum -= q.top();
			q.pop();
		}
		l[i] = sum;
	}
	sum = 0;
	while (!q.empty()) q.pop();
	for (int i=C-1;i>=0;i--) {
		q.push(c[i].a);
		sum += c[i].a;
		if (q.size() > len) {
			sum -= q.top();
			q.pop();
		}
		r[i] = sum;
	}
	int ans = -1;
	for (int i=len;i<C-len;i++) if (c[i].a + l[i-1] + r[i+1] <= F) ans = c[i].s;
	printf("%d\n",ans);
	return 0;
}
