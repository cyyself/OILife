#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int main() {
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int t = 0;
	while (n--) {
		int w;
		scanf("%d",&w);
		q.push(w);
	}
	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		cur -= b;
		q.push(cur);
		if (q.top() <= a * t) break;
		t ++;
	}
	printf("%d\n",t);
	return 0;
}
