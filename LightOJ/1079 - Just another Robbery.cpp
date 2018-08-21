#include <bits/stdc++.h>
using namespace std;
struct bank {
	int m;
	double p;
	friend bool operator < (const bank &a,const bank &b) {
		return a.p < b.p;
	}
}b[105];
double f[10005];
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		for (int i=0;i<10005;i++) f[i] = 0;
		f[0] = 1;
		double p;
		int n;
		scanf("%lf%d",&p,&n);
		p = 1 - p;
		int sum = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d%lf",&b[i].m,&b[i].p);
			b[i].p = 1 - b[i].p;
			sum += b[i].m;
		}
		int ans = 0;
		for (int i=1;i<=n;i++) {
			for (int j=sum;j>=b[i].m;j--) {
				f[j] = max(f[j],f[j-b[i].m]*b[i].p);
				if (f[j] >= p) {
					ans = max(ans,j);
				}
			}
		}
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
