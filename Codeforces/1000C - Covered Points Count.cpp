#include <bits/stdc++.h>
using namespace std;
struct Event{
	long long x;
	int d;
	friend bool operator < (const Event &a,const Event &b) {
		if (a.x < b.x) return true;
		return false;
	}
}e[400005];
int ecnt = 0;
long long ans[200005];
int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		long long a,b;
		cin >> a >> b;
		e[ecnt].d = 1;
		e[ecnt].x = a;
		ecnt ++;
		e[ecnt].d = -1;
		e[ecnt].x = b;
		ecnt ++;
	}
	sort(e,e+ecnt);
	int cur = 0;//从这个点开始线段的数量
	int last = 0;//上个点开始的线段数量
	long long lastpos = 0;//上个点的位置
	int cnt = 0;//该点的线段数
	for (int i=0;i<ecnt;i++) {
		cur += e[i].d;
		if (e[i].d > 0) cnt ++;
		if (i != ecnt-1 && e[i+1].x == e[i].x) continue;
		ans[cnt+last] ++;
		ans[last] += e[i].x - lastpos - 1;
		last = cur;
		lastpos = e[i].x;
		cnt = 0;
	}
	for (int i=1;i<=n;i++) {
		if (i != 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}