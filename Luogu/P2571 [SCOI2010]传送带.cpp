#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
double ax,ay,bx,by;
double cx,cy,dx,dy;
double p,q,r;
inline bool equal(double a,double b) {
	if (abs(a-b) < eps) return true;
	else return false;
}
inline double dis(double ax,double ay,double bx,double by) {
	return sqrt((ay-by) * (ay-by) + (ax-bx) * (ax-bx));
}
inline double getcdcost(double x,double y) {//给定ab上定点，求q和r段的最小时间。
	double cdxl = cx,cdxr = dx;
	double cdyl = cy,cdyr = dy;
	double m1cost=0,m2cost=1e9;
	while (!equal(m1cost,m2cost)) {
		double m1x = cdxl + 1 * (cdxr-cdxl) / 3;
		double m2x = cdxl + 2 * (cdxr-cdxl) / 3;
		double m1y = cdyl + 1 * (cdyr-cdyl) / 3;
		double m2y = cdyl + 2 * (cdyr-cdyl) / 3;
		m1cost = dis(x,y,m1x,m1y) / r + dis(m1x,m1y,dx,dy) / q;
		m2cost = dis(x,y,m2x,m2y) / r + dis(m2x,m2y,dx,dy) / q;
		//printf("\tm1x=%lf,m1y=%lf,m2x=%lf,m2y=%lf\n",m1x,m1y,m2x,m2y);
		//printf("\tcdxl=%lf,cdxr=%lf,cdyl=%lf,cdyr=%lf\n",cdxl,cdxr,cdyl,cdyr);
		//printf("\tm1cost=%lf,m2cost=%lf\n\n",m1cost,m2cost);
		if (m1cost < m2cost) {
			cdxr = m2x;
			cdyr = m2y;
		}
		else {
			cdxl = m1x;
			cdyl = m1y;
		}
	}
	return m1cost;
}
int main() {
	scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
	scanf("%lf%lf%lf%lf",&cx,&cy,&dx,&dy);
	scanf("%lf%lf%lf",&p,&q,&r);
	double abxl = ax,abxr = bx;
	double abyl = ay,abyr = by;
	double m1cost=0,m2cost=1e9;
	while (!equal(m1cost,m2cost)) {
		double m1x = abxl + 1 * (abxr-abxl) / 3;
		double m2x = abxl + 2 * (abxr-abxl) / 3;
		double m1y = abyl + 1 * (abyr-abyl) / 3;
		double m2y = abyl + 2 * (abyr-abyl) / 3;
		//printf("m1x=%lf,m1y=%lf,m2x=%lf,m2y=%lf\n",m1x,m1y,m2x,m2y);
		//printf("abxl=%lf,abxr=%lf,abyl=%lf,abyr=%lf\n",abxl,abxr,abyl,abyr);
		m1cost = dis(ax,ay,m1x,m1y) / p + getcdcost(m1x,m1y);
		m2cost = dis(ax,ay,m2x,m2y) / p + getcdcost(m2x,m2y);
		//printf("m1cost=%lf,m2cost=%lf\n\n",m1cost,m2cost);
		if (m1cost < m2cost) {
			abxr = m2x;
			abyr = m2y;
		}
		else {
			abxl = m1x;
			abyl = m1y;
		}
	}
	printf("%0.2lf\n",m1cost);
	return 0;
}
