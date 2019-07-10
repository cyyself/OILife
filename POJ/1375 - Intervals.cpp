//C++ AC,G++ OLE
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
pair <double,double> ans[500];
const double eps = 1e-5;
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		int x,y;
		scanf("%d%d",&x,&y);
		for (int i=0;i<n;i++) {
			int _x,_y;
			double r;
			scanf("%d%d%lf",&_x,&_y,&r);
			double dx = x - _x;
			double dy = y - _y;
			double l = sqrt(dx * dx + dy * dy);
			double l2 = sqrt(l * l - r * r);
			double deg = atan2(dy,dx);
			double degdiff = atan2(l2,r);
			double p1_x = _x + r * cos(deg+degdiff);
			double p1_y = _y + r * sin(deg+degdiff);
			double p2_x = _x + r * cos(deg-degdiff);
			double p2_y = _y + r * sin(deg-degdiff);
			double deg1 = atan2(p1_y-y,p1_x-x);
			double deg2 = atan2(p2_y-y,p2_x-x);
			double r1 = -p1_y / sin(deg1);
			double r2 = -p2_y / sin(deg2);
			double x1 = p1_x + r1 * cos(deg1);
			double x2 = p2_x + r2 * cos(deg2);
			if (x2 < x1) {
				swap(x1,x2);
				//printf("(debug)(warning)%0.2lf %0.2lf\n",x1,x2);
			}
			ans[i] = make_pair(x1,x2);
		}
		sort(ans,ans+n);
		//for (int i=0;i<n;i++) printf("(debug)%0.2lf %0.2lf\n",ans[i].first,ans[i].second);
		double prel = ans[0].first;
		double lastr = ans[0].second;
		for (int i=1;i<n;i++) {
			if (ans[i].first <= lastr + eps) {
				lastr = max(lastr,ans[i].second);
			}
			else {
				printf("%0.2lf %0.2lf\n",prel,lastr);
				prel = ans[i].first;
				lastr = ans[i].second;
			}
		}
		printf("%0.2lf %0.2lf\n",prel,lastr);
		puts("");
	}
	return 0;
}
