#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9+7;
long long sum[100005];
long long f1cnt[100005];
long long f2cnt[100005];
long long x[100005];
long long f[100005];
long long a,b;
struct query{
	int x;
	int type;//0开始，!0
	friend bool operator < (const query &a,const query &b) {
		if (a.x < b.x) {
			return true;
		}
		else {
			if (a.x == b.x) return a.type < b.type;
			else return false;
		}
	}
}qu[100005];
int main() {
	freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T --) {
		memset(sum,0,sizeof(sum));
		memset(f1cnt,0,sizeof(f1cnt));
		memset(f2cnt,0,sizeof(f2cnt));
		int n,q;
		scanf("%d%d",&n,&q);
		scanf("%lld%lld",&f[1],&f[2]);
		scanf("%lld%lld",&a,&b);
		for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
		f[1] %= mo;
		f[2] %= mo;
		for (int i=3;i<=n;i++) {
			f[i] = a * f[i-2] + b * f[i-1];
			f[i] %= mo;
		}
		int qcnt = 0;
		while (q --) {
			int l,r;
			scanf("%d%d",&l,&r);
			if (l == r) {
				x[l] += f[1];
				x[l] %= mo;
			}
			else {
				if (l + 1 == r) {
					x[l] += f[1];
					x[l] %= mo;
					x[r] += f[2];
					x[r] %= mo;
				}
				else {
					qu[qcnt++] = (query){l,0};
					qu[qcnt++] = (query){r,r-l+1};
				}
			}
		}
		sort(qu,qu+qcnt);
		int head = 0;
		for (int i=1;i<=n;i++) {
			while (head < qcnt && qu[head].x == i && qu[head].type == 0) {
				f1cnt[i]   ++;
				f2cnt[i+1] ++;
				head ++;
			}
			if (i == 1) sum[i] = f1cnt[i] * f[1];
			else sum[i] = b * (sum[i-1] - f1cnt[i-1] * f[1]) + a * sum[i-2] + f1cnt[i] * f[1] + f2cnt[i] * f[2];
			sum[i] += mo;
			sum[i] %= mo;
			x[i] += sum[i];
			x[i] %= mo;
			while (head < qcnt && qu[head].x == i && qu[head].type != 0) {
				sum[i] -= f[qu[head].type];
				sum[i] += mo;
				sum[i] %= mo;
				sum[i-1] -= f[qu[head].type-1];
				sum[i-1] += mo;
				sum[i-1] %= mo;
				head ++;
			}
		}
		for (int i=1;i<=n;i++) {
			if (i != 1) printf(" ");
			printf("%lld",x[i]);
		}
		printf("\n");
	}
	return 0;
}
