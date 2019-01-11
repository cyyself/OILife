#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue <int> q;
struct DATA {
	int a,b;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.a < b.a;
	}
	void read() {
		scanf("%d%d",&a,&b);
	}
}e[10005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) e[i].read();
	int k,f;
	scanf("%d%d",&k,&f);
	for (int i=0;i<n;i++) e[i].a = k - e[i].a;
	sort(e,e+n);
	int ptr = 0;
	int time = f;
	int ans = 0;
	while (time < k) {
		while (ptr < n && e[ptr].a <= time) {
			q.push(e[ptr].b);
			ptr ++;
		}
		if (!q.empty()) {
			time += q.top();
			q.pop();
			ans ++;
		}
		else break;
	}
	if (time < k) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
