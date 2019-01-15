#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int x,h;
	int seq;
	void read() {
		scanf("%d%d",&x,&h);
	}
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.x < b.x;
	}
}d[100005];
int ans[100005];
stack <int> s;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		d[i].read();
		d[i].seq = i;
	}
	sort(d,d+n);
	for (int i=n-1;i>=0;i--) {
		while (!s.empty() && d[i].x + d[i].h - 1 >= d[s.top()].x) {
			s.pop();
		}
		ans[d[i].seq] = s.empty()?n-i:s.top() - i;
		s.push(i);
	}
	printf("%d",ans[0]);
	for (int i=1;i<n;i++) printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
