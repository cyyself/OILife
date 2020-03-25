#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
bool vis[maxn];
int p[maxn],c[maxn];
vector <int> tmp;
bool check(int sz) {
	for (int i=0;i<sz;i++) {
		bool ok = true;
		int initc = c[tmp[i]];
		for (int j=i+sz;j<tmp.size();j+= sz) {
			if (c[tmp[j]] != initc) {
				ok = false;
				break;
			}
		}
		if (ok) return true;
	}
	return false;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&p[i]);
			vis[i] = false;
		}
		for (int i=1;i<=n;i++) scanf("%d",&c[i]);
		int ans = n;
		for (int i=1;i<=n;i++) {
			if (vis[i]) continue;
			tmp.clear();
			int cur = i;
			while (!vis[cur]) {
				tmp.push_back(cur);
				vis[cur] = true;
				cur = p[cur];
			}
			for (int i=1;i*i<=tmp.size();i++) {
				if (i >= ans) continue;
				if (tmp.size() % i) continue;
				if (check(i)) ans = i;
				if (tmp.size() / i < ans && check(tmp.size()/i)) ans = tmp.size() / i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
