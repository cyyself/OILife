#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 30;
map <long long,bool> exist;
int main() {
	queue <long long> q;
	q.push(1);
	while (!q.empty()) {
		long long cur = q.front();
		q.pop();
		exist[cur] = true;
		if (cur * 2 < INF && !exist[cur*2]) {
			q.push(cur*2);
			exist[cur*2] = true;
		}
		if (cur * 3 < INF && !exist[cur*3]) {
			q.push(cur*3);
			exist[cur*3] = true;
		}
		if (cur * 4 < INF && !exist[cur*4]) {
			q.push(cur*4);
			exist[cur*4] = true;
		}
		if (cur * 5 < INF && !exist[cur*5]) {
			q.push(cur*5);
			exist[cur*5] = true;
		}
	}
	long long ans = 0;
	int cnt = 0;
	for (auto x:exist) {
		ans = x.first;
		if (++cnt == 1500) break;
	}
	printf("The 1500'th ugly number is %lld.\n",ans);
	return 0;
}
