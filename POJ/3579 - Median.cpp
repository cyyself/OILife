#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long m;//有m个差值在range之内
int x[100005];
void cal_m(long long n) {
	long long t = n * (n-1LL);
	t >>= 1;
	m = t - (t>>1);
}
bool judge(int range) {
	long long sum = 0;
	for (int i=0;i<n;i++) sum += upper_bound(x,x+n,x[i]+range) - &x[i] - 1;//去掉x[i]本身
	return sum >= m;
}
int main() {
	while (scanf("%d",&n) == 1) {
		cal_m(n);
		for (int i=0;i<n;i++) scanf("%d",&x[i]);
		sort(x,x+n);
		int l = 0,r=1000000000;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (judge(mid)) {
				r = mid - 1;
				ans = mid;
			}
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
