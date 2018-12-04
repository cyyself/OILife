#include <cstdio>
#include <algorithm>
using namespace std;
struct money {
	long long v,b;
	long long cur_cnt;
	friend bool operator < (const money &a,const money &b) {
		return a.v > b.v;
	}
}m[25];
int main() {
	int n;
	long long c;
	scanf("%d%lld",&n,&c);
	long long sum = 0;
	for (int i=0;i<n;i++) {
		scanf("%lld%lld",&m[i].v,&m[i].b);
		sum += m[i].v * m[i].b;
	}
	sort(m,m+n);
	long long ans = 0;
	while (sum >= c) {
		long long cur_sum = c;
		for (int i=0;i<n && cur_sum > 0;i++) {
			long long &cur_cnt = m[i].cur_cnt = 0;
			cur_cnt = min(cur_sum / m[i].v,m[i].b);
			cur_sum -= cur_cnt * m[i].v;
		}
		for (int i=n-1;i>=0 && cur_sum > 0;i--) {
			long long d_cur_cnt = min((cur_sum+m[i].v-1)/m[i].v,m[i].b-m[i].cur_cnt);
			//(cur_sum+m[i].v-1)/m[i].v = ceil(cur_sum/m[i].v) //向上取整
			m[i].cur_cnt += d_cur_cnt;
			cur_sum -= d_cur_cnt * m[i].v;
		}
		long long cur_tot = 0x3f3f3f3f3f3f3f3f;
		for (int i=0;i<n;i++) if (m[i].cur_cnt) cur_tot = min(cur_tot,m[i].b / m[i].cur_cnt);
		for (int i=0;i<n;i++) if (m[i].cur_cnt) m[i].b -= cur_tot * m[i].cur_cnt;
		ans += cur_tot;
		sum -= cur_tot * (c - cur_sum);
	}
	printf("%lld\n",ans);
	return 0;
}
