#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int a[4000],b[4000],c[4000],d[4000];
int ab[16000000];
int main() {
	int n;
	scanf("%d",&n);
	int ans = 0;
	for (int i=0;i<n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		ab[i*n+j] = a[i] + b[j];
	}
	sort(ab,ab+n*n);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		int cur = c[i] + d[j];
		int* p1 = lower_bound(ab,ab+n*n,-cur);
		if (*p1 != -cur) continue;
		int* p2 = upper_bound(ab,ab+n*n,-cur);
		ans += p2 - p1;
	}
	printf("%d\n",ans);
	return 0;
}
