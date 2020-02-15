#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 2005;
int mt[maxn][maxn];
int a[maxn];
int L[maxn],R[maxn];
int n,m;
void work_R() {
	stack <int> s;
	for (int i=1;i<=m;i++) {
		while (!s.empty()) {
			if (a[s.top()] > a[i]) {
				R[s.top()] = i - 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		R[s.top()] = m;
		s.pop();
	}
}
void work_L() {
	stack <int> s;
	for (int i=m;i>=1;i--) {
		while (!s.empty()) {
			if (a[s.top()] > a[i]) {
				L[s.top()] = i + 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		L[s.top()] = 1;
		s.pop();
	}
}
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&mt[i][j]);
		int ans = 0;
		for (int j=1;j<=m;j++) a[j] = 0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) a[j] = mt[i][j]?a[j]+1:0;
			work_R();
			work_L();
			for (int j=1;j<=m;j++) ans = max(ans,a[j]*(R[j]-L[j] + 1));
		}
		printf("%d\n",ans);
	}
	return 0;
}
