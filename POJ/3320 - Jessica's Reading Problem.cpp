#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int a[1000000];
int ls[1000000];
int cnt[1000000];
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			ls[i] = a[i];
		}
		sort(ls,ls+n);
		int len = unique(ls,ls+n) - ls;
		int c = 0;
		int ans = n;
		queue <int> q;
		for (int i=0;i<n;i++) {
			int x = lower_bound(ls,ls+len,a[i]) - ls;
			q.push(x);
			if (cnt[x] == 0) c ++;
			cnt[x] ++;
			while (c == len) {
				ans = min(ans,(int)q.size());
				cnt[q.front()] --;
				if (cnt[q.front()] == 0) c --;
				q.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
