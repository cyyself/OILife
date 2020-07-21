#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
struct DATA {
	long long p,a;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.p > b.p || (a.p == b.p && a.a > b.a);
	}
	friend bool operator == (const DATA &a,const DATA &b) {
		return a.p == b.p && a.a == b.a;
	}
}arr[maxn];
class mystack : public stack<int> {
public:
	int sec() {
		int t = top();
		pop();
		int res = top();
		push(t);
		return res;
	}
};
bool del[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%lld%lld",&arr[i].p,&arr[i].a);
			del[i] = 0;
		}
		sort(arr,arr+n);
		int last = -1;
		vector <int> all;
		for (int i=0;i<n;i++) {
			if (i == 0 || !(arr[i] == arr[i-1])) {
				last = i;
			}
			else del[last] = true;
		}
		mystack s;
		for (int i=0;i<n;i++) {
			if (!s.empty() && arr[i].a <= arr[s.top()].a) continue;
			while (s.size() >= 2) {
				long long ds1 = arr[s.sec()].p - arr[s.top()].p;
				long long da1 = arr[s.top()].a - arr[s.sec()].a;
				long long ds2 = arr[s.top()].p - arr[i].p;
				long long da2 = arr[i].a - arr[s.top()].a;
				if (ds2 * da1 <= ds1 * da2) s.pop();
				else break;
			}
			s.push(i);
		}
		int ans = s.size();
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			if (del[cur]) ans --;
		}
		printf("%d\n",ans);
	}
	return 0;
}
