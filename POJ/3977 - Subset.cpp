#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
using std::lower_bound;
int n;
long long a[35];
struct DATA {
	long long sum;
	int cnt;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.sum < b.sum;
	}
}d1[1<<17],d2[1<<18];
long long myabs(long long x) {
	if (x < 0) return -x;
	return x;
}
int main() {
	while (scanf("%d",&n) == 1 && n) {
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		for (int i=0;i<n;i++) scanf("%lld",&a[i]);
		for (int s=1;s<(1<<(n/2));s++) {
			for (int j=0;j<n/2;j++) if (s & (1 << j)) {
				d1[s].cnt ++;
				d1[s].sum += a[j];
			}
		}
		for (int s=1;s<(1<<((n+1)/2));s++) {
			for (int j=0;j<(n+1)/2;j++) if (s & (1 << j)) {
				d2[s].cnt ++;
				d2[s].sum += a[n/2+j];
			}
		}
		sort(d1+1,d1+(1<<(n/2)));
		sort(d2+1,d2+(1<<((n+1)/2)));
		long long ans = 0x7fffffffffffffff;
		int ans_cnt = 0;
		for (int i=1;i<(1<<(n/2));i++) {
			if (myabs(d1[i].sum) < ans || (myabs(d1[i].sum) == ans && d1[i].cnt < ans_cnt)) {
				ans = myabs(d1[i].sum);
				ans_cnt = d1[i].cnt;
			}
			DATA* ptr = lower_bound(d2,d2+(1<<((n+1)/2)),(DATA){-d1[i].sum,0});
			if (ptr - 1 >= d2) {
				if (myabs((ptr-1)->sum + d1[i].sum) < ans || (myabs((ptr-1)->sum + d1[i].sum) == ans && d1[i].cnt + (ptr-1)->cnt < ans_cnt)) {
					ans = myabs((ptr-1)->sum + d1[i].sum);
					ans_cnt = d1[i].cnt + (ptr-1)->cnt;
				}
			}
			if (ptr >= d2 && ptr < d2+(1<<((n+1)/2))) {
				if (myabs(ptr->sum + d1[i].sum) < ans || (myabs(ptr->sum + d1[i].sum) == ans && d1[i].cnt + ptr->cnt < ans_cnt)) {
					ans = myabs(ptr->sum + d1[i].sum);
					ans_cnt = d1[i].cnt + ptr->cnt;
				}
			}
			if (ptr + 1 < d2+(1<<((n+1)/2))) {
				if (myabs((ptr+1)->sum + d1[i].sum) < ans || (myabs((ptr+1)->sum + d1[i].sum) == ans && d1[i].cnt + (ptr+1)->cnt < ans_cnt)) {
					ans = myabs((ptr+1)->sum + d1[i].sum);
					ans_cnt = d1[i].cnt + (ptr+1)->cnt;
				}
			}
		}
		for (int i=1;i<(1<<((n+1)/2));i++) {
			if (myabs(d2[i].sum) < ans || (myabs(d2[i].sum) == ans && d2[i].cnt < ans_cnt)) {
				ans = myabs(d2[i].sum);
				ans_cnt = d2[i].cnt;
			}
		}
		printf("%lld %d\n",ans,ans_cnt);
	}
	return 0;
}
