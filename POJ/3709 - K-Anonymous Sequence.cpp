#include <cstdio>
using namespace std;
const int maxn = 500005;
long long f[maxn],a[maxn],pre[maxn];
inline long long calfz(int x,int y) {
	return (f[x] - pre[x] + a[x+1] * x) - (f[y] - pre[y] + a[y+1] * y);
}
inline long long calfm(int x,int y) {
	return a[x+1] - a[y+1];
}
long long q[maxn];
int head,tail;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			pre[i] = pre[i-1] + a[i];
		}
		head = tail = 0;
		q[tail++] = 0;
		for (int i=1;i<=n;i++) {
			while (head+1 < tail && calfz(q[head],q[head+1]) >= i * calfm(q[head],q[head+1])) head ++;
			int j = q[head];
			f[i] = f[j] + pre[i] - pre[j] - a[j+1] * (i - j);
			if (i - k + 1 >= k) {
				int topush = i - k + 1;
				while (head + 1 < tail) {
					int t1 = q[tail-2];
					int t2 = q[tail-1];
					if (calfz(t1,t2) * calfm(t2,topush) >= calfz(t2,topush) * calfm(t1,t2)) tail --;
					else break;
				}
				q[tail++] = topush;
			}
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
