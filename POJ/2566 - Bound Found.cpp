#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
int n;
int a[100000];
int pre[100000];
pair <int,int> p[100001];//前缀和,pos
void work(int t) {
	int ans_d = 0x3f3f3f3f;
	int ans,ans_l,ans_r;
	int l = 0;
	int r = 1;
	while (r <= n) {
		int cur = p[r].first - p[l].first;
		if (abs(cur-t) < ans_d) {
			ans_d = abs(cur-t);
			ans = cur;
			ans_l = p[r].second;
			ans_r = p[l].second;
			if (ans_l > ans_r) swap(ans_l,ans_r);
		}
		if (cur < t) r ++;
		if (cur > t) l ++;
		if (cur == t) break;
		if (l == r) r ++;
	}
	printf("%d %d %d\n",ans,1+ans_l+1,1+ans_r);
}
int main() {
	int k;
	while (scanf("%d%d",&n,&k) == 2 && n) {
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<n;i++) {
			pre[i] = (i==0?0:pre[i-1]) + a[i];
			p[i] = make_pair(pre[i],i);
		}
		p[n] = make_pair(0,-1);
		sort(p,p+n+1);
		while (k --) {
			int t;
			scanf("%d",&t);
			work(t);
		}
	}
	return 0;
}
