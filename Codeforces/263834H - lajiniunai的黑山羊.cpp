#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
pair <int,int> p[maxn];
multiset <int,greater<int> > s;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		s.clear();
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].first,&p[i].second);
		sort(p,p+n);
		long long ssum = 0;
		int ptr = 0;
		int val = p[0].first;
		int cnt = 0;
		long long ans = 0;
		while (cnt < n) {
			while (ptr < n && p[ptr].first == val) {
				s.insert(p[ptr].second);
				ssum += p[ptr].second;
				ptr ++;
			}
			ssum -= *s.begin();
			s.erase(s.begin());
			ans += ssum;
			cnt ++;
			if (!s.empty()) {
				val ++;
			}
			else val = p[ptr].first;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
