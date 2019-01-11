#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100005];
int n;
long long k;
bool judge(long long t) {
	long long cnt = 0;//烘干机使用次数
	for (int i=0;i<n && cnt <= t;i++) {
		cnt += (max(a[i]-t,0LL) + k - 1LL) / k;
	}
	return cnt <= t;
}
int main() {
	while(scanf("%d",&n) == 1) {
		long long l = 0;
		long long r = 0;
		for (int i=0;i<n;i++) {
			scanf("%lld",&a[i]);
			r = max(r,a[i]);
		}
		scanf("%lld",&k);
		if (k == 1) {
			printf("%lld\n",r);
		}
		else {
			k--;
			long long ans = -1;
			while (l <= r) {
				long long mid = (l + r) >> 1;
				if (judge(mid)) {
					ans = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
