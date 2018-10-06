#include <cstdio>
#include <algorithm>
using namespace std;
struct B {
	int h,c,a;
	friend bool operator < (const B &a,const B &b) {
		return a.a < b.a;
	}
}blk[405];
int f[40005];
int main() {
	int n;
	scanf("%d",&n);
	int maxh = 0;
	for (int i=0;i<n;i++) {
		scanf("%d%d%d",&blk[i].h,&blk[i].a,&blk[i].c);
		maxh = max(maxh,blk[i].a);
	}
	sort(blk,blk+n);
	int ans = 0;
	for (int i=0;i<n;i++) {
		int c = 1;
		while (c < blk[i].c) {
			int h = c * blk[i].h;
			for (int j=blk[i].a;j>=h;j--) f[j] = max(f[j],f[j-h]+h);
			blk[i].c -= c;
			c <<= 1;
		}
		int h = blk[i].c * blk[i].h;
		for (int j=blk[i].a;j>=h;j--) f[j] = max(f[j],f[j-h]+h);
	}
	for (int i=0;i<=maxh;i++) ans = max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
