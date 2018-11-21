#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
const double eps = 1e-5;
pair <double,double> p[1005];
int main() {
	int n;
	double d;
	int cas = 0;
	while (scanf("%d%lf",&n,&d) == 2 && n) {
		bool flag = true;
		for (int i=0;i<n;i++) {
			double x,y;
			scanf("%lf%lf",&x,&y);
			if (y > d) {
				flag = false;
			}
			double dx = sqrt(d * d - y * y);
			p[i].second = x - dx;
			p[i].first = x + dx;
		}
		sort(p,p+n);
		if (!flag) {
			printf("Case %d: -1\n",++cas);
			continue;
		}
		double cur = p[0].first;
		int ans = 1;
		for (int i=1;i<n;i++) {
			if (p[i].second > cur) {
				cur = p[i].first;
				ans ++;
			}
		}
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}
