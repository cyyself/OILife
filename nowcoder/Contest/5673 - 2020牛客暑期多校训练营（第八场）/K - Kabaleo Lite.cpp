#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
int a[maxn],b[maxn];
__int128 pre[maxn];
void write(__int128 x) {
	if (x == 0) printf("0");
	else if (x < 0) {
		printf("-");
		x = -x;
	}
	int buflen = 0;
	char buf[50];
	while (x) {
		buf[buflen++] = '0' + x % 10;
		x /= 10;
	}
	buf[buflen] = 0;
	reverse(buf,buf+buflen);
	printf("%s",buf);
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			pre[i] = pre[i-1] + a[i];
		}
		b[0] = inf;
		for (int i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			b[i] = min(b[i],b[i-1]);
		}
		__int128 ans = 0;
		int last = n+1;
		int d = 0;
		priority_queue <pair<long long,int> > q;
		for (int i=1;i<=n;i++) q.push({pre[i],i});
		while (!q.empty()) {
			auto cur = q.top();
			q.pop();
			int pos = cur.second;
			if (pos >= last) continue;
			__int128 sz = b[pos] - d;
			ans += sz * pre[pos];
			d += sz;
			last = pos;
		}
		printf("Case #%d: %d ",cas,b[1]);
		write(ans);
		printf("\n");
	}
	return 0;
}
