#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 50000+5;
int ed[maxn],w[maxn],h[maxn];
int l[maxn],r[maxn];
int n;
void work_R() {
	stack <int> s;
	for (int i=1;i<=n;i++) {
		while (!s.empty()) {
			if (h[s.top()] > h[i]) {
				r[s.top()] = ed[i] - w[i];
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		r[s.top()] = ed[n];
		s.pop();
	}
}
void work_L() {
	stack <int> s;
	for (int i=n;i>=1;i--) {
		while (!s.empty()) {
			if (h[s.top()] > h[i]) {
				l[s.top()] = ed[i];
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		l[s.top()] = 0;
		s.pop();
	}
}
int main() {
	while (scanf("%d",&n) == 1 && n > 0)  {
		int e = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d",&w[i],&h[i]);
			ed[i] = ed[i-1] + w[i];
		}
		work_R();
		work_L();
		int ans = 0;
		for (int i=1;i<=n;i++) ans = max(ans,h[i]*(r[i]-l[i]));
		printf("%d\n",ans);
	}
	return 0;
}
