#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
	long long v,pos;
	void read() {
		scanf("%lld%lld",&v,&pos);
	}
	friend bool operator < (const DATA &a,const DATA &b) {
		if (a.v != b.v) return a.v < b.v;
		else return a.pos < b.pos;
	}
}a[20005];
int n;
struct tree_array {
	long long arr[20005];
	inline int lowbit(int x) {
		return x & (-x);
	}
	inline long long query(int pos) {
		long long ret = 0;
		for (int i=pos;i>=1;i-=lowbit(i)) ret += arr[i];
		return ret;
	}
	inline void add(int pos,long long d) {
		for (int i=pos;i<=20000;i+=lowbit(i)) arr[i] += d;
	}
}pos_sum,exist_sum;
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) a[i].read();
	sort(a,a+n);
	long long ans = 0;
	for (int i=0;i<n;i++) {
		long long lower_cnt = exist_sum.query(a[i].pos);
		long long lower_sum = pos_sum.query(a[i].pos);
		long long upper_cnt = i - lower_cnt;
		long long upper_sum = pos_sum.query(20000) - lower_sum;
		ans += a[i].v * (lower_cnt * a[i].pos - lower_sum);
		ans -= a[i].v * (upper_cnt * a[i].pos - upper_sum);
		pos_sum.add(a[i].pos,a[i].pos);
		exist_sum.add(a[i].pos,1);
	}
	printf("%lld\n",ans);
	return 0;
}
