#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
const double eps = 1e-5;
pair <double,double> p[1005];
int main() {
	int n;
	double r;
	int cas = 1;
	while (scanf("%d%lf",&n,&r) == 2 && n) {
		bool err = false;
		for (int i=0;i<n;i++) {
			double x,y;
			scanf("%lf%lf",&x,&y);
			if (y > r) err = true;
			p[i].first  = x - sqrt(r*r - y*y);
			p[i].second = x + sqrt(r*r - y*y);
		}
		if (err) {
			printf("Case %d: -1\n",cas++);
			continue;
		}
		sort(p,p+n);
		int cnt = 1;
		pair <double,double> tmp = p[0];
		for (int i=1;i<n;i++) {
			if (p[i].first > tmp.second) {
				cnt ++;
				tmp = p[i];
			}
			else if (p[i].second < tmp.second) {
				tmp = p[i];
			}
		}
		printf("Case %d: %d\n",cas++,cnt);
	}
	return 0;
}
