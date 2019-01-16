#include <bits/stdc++.h>
using namespace std;
int a[200005];
int p[200005];
priority_queue <pair<int,int> > q;
int check(int mid) {
	int ans = 0;
	if (a[mid] == 255) {
		//偶回文
		int lastl = 255;
		int l = mid - 1;
		int r = mid + 1;
		while (a[l] == a[r] && l > 0 && a[l] <= lastl) {
			lastl = a[l];
			ans += 2;
			l -= 2;
			r += 2;
		}
	}
	else {
		//奇回文
		ans = 1;
		int lastl = a[mid];
		int l = mid - 2;
		int r = mid + 2;
		while (a[l] == a[r] && l > 0 && a[l] <= lastl) {
			lastl = a[l];
			ans += 2;
			l -= 2;
			r += 2;
		}
	}
	return ans;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		a[0] = -1;
		for (int i=1;i<=n*2;i+=2) {
			scanf("%d",&a[i]);
			a[i+1] = 255;
		}
		int id = 0;
		int mx = 0;
		for (int i=1;i<=n*2;i++) {
			if (i < mx) p[i] = min(p[2*id-i],mx-i);
			else p[i] = 1;
			while (i-p[i] >= 0 && a[i-p[i]] == a[i+p[i]]) p[i] ++;
			if (mx < i + p[i]) {
				id = i;
				mx = i + p[i];
			}
			q.push(make_pair(p[i],i));
		}
		int ans = 1;
		while (!q.empty()) {
			auto cur = q.top();
			q.pop();
			if (cur.first < ans) break;
			ans = max(ans,check(cur.second));
		}
		printf("%d\n",ans);
	}
	return 0;
}
