#include <bits/stdc++.h>
using namespace std;
long long h[3001][3001];
long long r[3001][3001];
int main() {
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	long long g0,x,y,z;
	scanf("%lld%lld%lld%lld",&g0,&x,&y,&z);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		h[i][j] = g0;
		g0 = (g0 * x + y) % z;
	}
	for (int i=1;i<=n;i++) {
		deque <pair<int,int> > q;
		for (int j=m;j>=m-b+2;j--) {
			while (!q.empty()) {
				auto cur = q.back();
				if (cur.first >= h[i][j]) q.pop_back();
				else break;
			}
			q.push_back(make_pair(h[i][j],j));
		}
		for (int j=m-b+1;j>=1;j--) {
			while (!q.empty()) {
				auto cur = q.front();
				if (cur.second > j + b -1) q.pop_front();
				else break;
			}
			while (!q.empty()) {
				auto cur = q.back();
				if (cur.first >= h[i][j]) q.pop_back();
				else break;
			}
			q.push_back(make_pair(h[i][j],j));
			auto cur = q.front();
			r[i][j] = cur.first;
		}
	}
	long long ans = 0;
	for (int j=1;j<=m-b+1;j++) {
		deque <pair<int,int> > q;
		for (int i=n;i>=n-a+2;i--) {
			while (!q.empty()) {
				auto cur = q.back();
				if (cur.first >= r[i][j]) q.pop_back();
				else break;
			}
			q.push_back(make_pair(r[i][j],i));
		}
		for (int i=n-a+1;i>=1;i--) {
			while (!q.empty()) {
				auto cur = q.front();
				if (cur.second > i + a -1) q.pop_front();
				else break;
			}
			while (!q.empty()) {
				auto cur = q.back();
				if (cur.first >= r[i][j]) q.pop_back();
				else break;
			}
			q.push_back(make_pair(r[i][j],i));
			auto cur = q.front();
			ans += cur.first;
		}
	}
	cout << ans << endl;
	return 0;
}
