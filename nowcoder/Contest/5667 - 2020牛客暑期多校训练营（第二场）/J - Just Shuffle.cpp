#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
bool vis[maxn];
vector <int> s[maxn];
int ans[maxn];
int to[maxn],pre[maxn];
int main() {
	int n;
	long long k;
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int scnt = 0;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		s[scnt].push_back(i);
		vis[i] = true;
		int cur = a[i];
		while (!vis[cur]) {
			vis[cur] = true;
			s[scnt].push_back(cur);
			cur = a[cur];
		}
		scnt ++;
	}
	for (int i=0;i<scnt;i++) {
		for (int j=0;j<s[i].size();j++) to[(j*k)%s[i].size()] = j;
		for (int j=0;j<s[i].size();j++) pre[j] = s[i][to[j]];
		for (int j=0;j<s[i].size();j++) ans[pre[j]] = pre[(j+1)%s[i].size()];
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
