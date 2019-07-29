#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int L[100005],R[100005];
int n;
void work_R() {
	stack <int> s;
	for (int i=1;i<=n;i++) {
		while (!s.empty() && a[s.top()] > a[i]) {
			R[s.top()] = i - 1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		R[s.top()] = n;
		s.pop();
	}
}
void work_L() {
	stack <int> s;
	for (int i=n;i>=1;i--) {
		while (!s.empty() && a[s.top()] > a[i]) {
			L[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		L[s.top()] = 1;
		s.pop();
	}
}
int main() {
	while (scanf("%d",&n) == 1 && n) {
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		work_R();
		work_L();
		long long ans = 0;
		for (int i=1;i<=n;i++) ans = max(ans,(R[i]-L[i]+1LL) * a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
