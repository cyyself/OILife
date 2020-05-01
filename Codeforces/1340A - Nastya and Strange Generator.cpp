#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int cnt[maxn];
int pos[maxn];
int f[maxn];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void uni(int x,int y) {
	f[find(x)] = find(y);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		multiset<int> s;
		for (int i=1;i<=n;i++) {
			int t;
			scanf("%d",&t);
			pos[t] = i;
			cnt[i] = 1;
			s.insert(1);
			f[i] = i;
		}
		f[n+1] = n+1;
		bool ans = true;
		for (int i=1;i<=n && ans;i++) {
			if (cnt[pos[i]] == *s.rbegin()) {
				uni(pos[i],pos[i]+1);
				s.erase(prev(s.end()));
				int up = find(pos[i]);
				if (up != n+1) {
					auto x = s.find(cnt[up]);
					s.erase(x);
					cnt[up] += cnt[pos[i]];
					s.insert(cnt[up]);
				}
				cnt[pos[i]] = 0;
			}
			else ans = false;
		}
		if (ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
