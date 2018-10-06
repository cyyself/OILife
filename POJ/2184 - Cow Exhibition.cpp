#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct cow {
	int s,f;
}c[105];
int n;
int f[200005];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&c[i].s,&c[i].f);
	int center = 1000 * n+1;
	int range = center * 2;
	memset(f,0x80,sizeof(f));
	f[center] = 0;
	for (int i=0;i<n;i++) {
		if (c[i].s >= 0) {
			for (int j=range-1;j>=c[i].s;j--) f[j] = max(f[j],f[j-c[i].s]+c[i].f);
		}
		else {
			for (int j=abs(c[i].s);j-c[i].s<range;j++) f[j] = max(f[j],f[j-c[i].s]+c[i].f);
		}
	}
	int ans = 0;
	for (int i=center;i<range;i++) if (f[i] > 0) ans = max(ans,i-center+f[i]);
	printf("%d\n",ans);
	return 0;
}
