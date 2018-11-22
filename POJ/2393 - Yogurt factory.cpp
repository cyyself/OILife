#include <cstdio>
#include <algorithm>
using namespace std;
int c[10005];
int y[10005];
int main() {
	int n,s;
	while (scanf("%d%d",&n,&s) == 2) {
		for (int i=0;i<n;i++) scanf("%d%d",&c[i],&y[i]);
		long long ans = c[0] * y[0];
		for (int i=1;i<n;i++) {
			c[i] = min(c[i],c[i-1]+s);
			ans += c[i] * y[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
