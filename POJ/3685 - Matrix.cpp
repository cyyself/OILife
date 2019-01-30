#include <cstdio>
inline long long getnum(long long i,long long j) {
	return i * i + 100000LL * i + j * j - 100000LL * j + i * j;
}
long long n,m;
inline long long cal(long long i,long long upper) {//返回i行有多少个数小于等于upper
	long long l = 1;
	long long r = n;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (getnum(mid,i) <= upper) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
inline bool check(long long upper) {
	long long sum = 0;
	for (int i=1;i<=n;i++) sum += cal(i,upper);
	return sum >= m;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%lld%lld",&n,&m);
		long long l = 0x8000000000000000;
		long long r = 0x7fffffffffffffff;
		long long ans = 0x8000000000000000;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
