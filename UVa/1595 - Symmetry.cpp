#include <bits/stdc++.h>
using namespace std;
pair <int,int> p[1005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		map <pair<int,int>,bool> exist;
		int n;
		scanf("%d",&n);
		int l = 0x7fffffff;
		int r = 0x80000000;
		for (int i=0;i<n;i++) {
			scanf("%d%d",&p[i].first,&p[i].second);
			p[i].first *= 2;
			l = min(p[i].first,l);
			r = max(p[i].first,r);
			exist[p[i]] = true;
		}
		int mid = (l + r) >> 1;
		bool ans = true;
		for (int i=0;i<n && ans;i++) {
			int x = mid + (mid - p[i].first);
			if (p[i].first > mid) x = mid - (p[i].first - mid);
			int y = p[i].second;	
			if (!exist[make_pair(x,y)]) ans = false;
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
