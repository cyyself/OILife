#include <bits/stdc++.h>
using namespace std;
struct pos {
	int x;
	double y;
} c[1005];
int n;
int r;
inline double pow2(double x) {
	return x * x;
}
int main() {
	scanf("%d%d",&n,&r);
	for (int i=0;i<n;i++) {
		scanf("%d",&c[i].x);
		double cury = r;
		for (int j=0;j<i;j++) {
			if (abs(c[i].x - c[j].x) <= 2*r) {
				cury = max(cury,c[j].y+sqrt(pow2(2*r)-pow2(c[i].x-c[j].x)));
			}
		}
		c[i].y = cury;
	}
	printf("%lf\n",c[0].y);
	for (int i=1;i<n;i++) printf("%lf\n",c[i].y);
	return 0;
}