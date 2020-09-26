#include <bits/stdc++.h>
using namespace std;
namespace Geometry {
	const double eps = 1e-3;
	bool eq(double x,double y) {
		return abs(x-y) < eps;
	}
	int sgn(double x) {
		if (eq(x,0)) return 0;
		else return x>0?1:-1;
	}
	struct Point {
		double x,y;
		Point() {
			x = 0;
			y = 0;
		}
		Point(double _x,double _y) {
			x = _x;
			y = _y;
		}
		Point spin(double ddeg) {
			double deg = atan2(y,x);
			double r = sqrt(x * x + y * y);
			return Point(r * cos(deg+ddeg),r * sin(deg+ddeg));
		}
		friend Point operator + (const Point &a,const Point &b) {
			return Point(a.x+b.x,a.y+b.y);
		}
		friend Point operator - (const Point &a,const Point &b) {
			return Point(a.x-b.x,a.y-b.y);
		}
		friend double operator * (const Point &a,const Point &b) {
			return a.x * b.x + a.y * b.y;
		}
		friend double operator ^ (const Point &a,const Point &b) {
			return a.x * b.y - a.y * b.x;//cross product
		}
		friend Point operator * (double k,Point p) {
			return Point(p.x*k,p.y*k);
		}
		friend Point operator * (Point p,double k) {
			return Point(p.x*k,p.y*k);
		}
	};
	Point proj(Point a,Point b,Point p) {//点p在直线ab的投影
		Point d = b - a;
		Point r = p - a;
		return a + d * ((r * d)/(d * d));
	}
	double dis(Point a,Point b) {
		double dx = b.x - a.x;
		double dy = b.y - a.y;
		return sqrt(dx * dx + dy * dy);
	}
	struct Line {
		Point u,v;
		Point d;
		double deg;
		Line() {
			deg = 0;
		}
		Line(const Point &_u,const Point &_v) {
			u = _u;
			v = _v;
			d = v - u;
			deg = atan2(d.y,d.x);
		}
		friend bool operator < (const Line &a,const Line &b) {
			if (eq(a.deg,b.deg)) return sgn((a.v-a.u) ^ (b.v-a.u)) > 0;
			return a.deg < b.deg;
		}
	};
}
using namespace Geometry;
Point p[3];
double w;
double calh(Point a,Point b,Point c) {
	Point r = b - a;
	Point t = c - a;
	double ddeg = acos(w/dis(a,b));
	Point d = r.spin(ddeg);
	if (sgn(t^r) != sgn(d^r)) d = r.spin(-ddeg);
	assert(sgn(t^r) == sgn(d^r));
	d = d * (w/dis(a,b));
	Point pp = proj(a,a+d,c);
	if (dis(pp,a) > w+eps || dis(pp,a+d) > w+eps) return 1e12;
	else {
		if (sgn(d^r) == sgn(d^t)) return sqrt(dis(a,b)*dis(a,b) - w * w);
		else return sqrt(dis(a,b)*dis(a,b) - w * w) + dis(pp,c);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		for (int i=0;i<3;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		scanf("%lf",&w);
		//考虑每条边贴着底
		double ans = 1e12;
		for (int i=0;i<3;i++) {
			Point pos = proj(p[i],p[(i+1)%3],p[(i+2)%3]);
			if (dis(pos,p[i]) < w + eps && dis(pos,p[(i+1)%3]) < w + eps && dis(p[i],p[(i+1)%3]) < w + eps) {
				ans = min(ans,dis(pos,p[(i+2)%3]));
				//printf("(debug1)%lf\n",dis(pos,p[(i+2)%3]));
			}
		}
		//考虑每条边旋转
		for (int i=0;i<3;i++) {
			if (dis(p[i],p[(i+1)%3]) > w + eps) {
				ans = min(ans,calh(p[i],p[(i+1)%3],p[(i+2)%3]));
				ans = min(ans,calh(p[(i+1)%3],p[i],p[(i+2)%3]));
				//printf("(debug21)%lf\n",calh(p[i],p[(i+1)%3],p[(i+2)%3]));
				//printf("(debug22)%lf\n",calh(p[(i+1)%3],p[i],p[(i+2)%3]));
			}
		}
		if (ans == 1e12) printf("impossible\n");
		else printf("%0.8lf\n",ans);
	}
	return 0;
}
