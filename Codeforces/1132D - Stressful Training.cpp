#pragma GCC optimize(s)
#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
long long c;
int n,k;
struct DATA {
	long long t,i,x;
	void cal() {
		t = (a[i] + x * c) / b[i];
	}
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.t > b.t;
	}
};
bool judge() {
	priority_queue <DATA> q;
	for (int i=0;i<n;i++) {
		DATA cur;
		cur.i = i;
		cur.x = 0;
		cur.cal();
		q.push(cur);
	}
	int t = 0;
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		if (cur.t >= k) return true;
		if (cur.t <  t) return false;
		cur.x ++;
		cur.cal();
		q.push(cur);
		t ++;
	}
	return false;
}
long long read() {
	long long ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
int main() {
	n = read();
	k = read();
	k --;
	long long l = 0;
	long long r = 0;
	for (int i=0;i<n;i++) a[i] = read();
	for (int i=0;i<n;i++) {
		b[i] = read();
		r = max(r,k * b[i]);
	}
	c = r;
	if (judge()) {
		long long ans = -1;
		while (l <= r) {
			c = (l + r) >> 1;
			if (judge()) {
				r = c - 1;
				ans = c;
			}
			else l = c + 1;
		}
		printf("%lld\n",ans);
	}
	else puts("-1");
	return 0;
}
