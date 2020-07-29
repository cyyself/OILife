#include <bits/stdc++.h>
using namespace std;
namespace Geometry {
	const double eps = 1e-5;
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
	};
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
		double length() {
			return sqrt(d.x * d.x + d.y * d.y);
		}
		friend bool operator < (const Line &a,const Line &b) {
			if (eq(a.deg,b.deg)) return sgn((a.v-a.u) ^ (b.v-a.u)) > 0;
			//第二个确实是a.u不是b.u，这里没打错
			return a.deg < b.deg;
		}
	};
	template <typename T> 
	class mydeque : public deque <T> {
	public:
		T front_sec() {
			T tmp = this->front();
			this->pop_front();
			T res = this->front();
			this->push_front(tmp);
			return res;
		}
		T back_sec() {
			T tmp = this->back();
			this->pop_back();
			T res = this->back();
			this->push_back(tmp);
			return res;
		}
	};
	Point inter(Line a,Line b) {
		Point c = b.u - a.u;
		return b.u + ((c^a.d) / (a.d^b.d)) * b.d;
	}
	bool check(Point p,Line l) {
		return sgn(l.d ^ (p-l.u)) > 0;//点在直线左侧
	}
	double poly_area(const vector <Point> &p) {//p需按照极角排序
		if (p.size() < 3) return 0;
		//Point fi = *p.begin();
		double sum = 0;
		for (int i=0;i<p.size();i++) {
			sum += p[i] ^ p[(i+1)%p.size()];
		}
		return sum / 2;
	}

}
using namespace Geometry;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		double L,x,y,vx,vy;
		long long k;
		scanf("%lf%lf%lf%lf%lf%lld",&L,&x,&y,&vx,&vy,&k);
		double H = sqrt((double)3) * L / 2;
		double v = sqrt(vx * vx + vy * vy);
		Line line[3] = {
			Line(
				Point(-L/2,0),
				Point(L/2,0)
			),
			Line(
				Point(L/2,0),
				Point(0,H)
			),
			Line(
				Point(0,H),
				Point(-L/2,0)
			)
		};
		Point src = Point(x,y);
		Point vv = Point(vx,vy);
		double l = 0, r = 1e10;
		for (int i=0;i<500;i++) {
			double mid = (l + r) / 2;
			Point dst = src + (mid * vv);
			long long kk = 0;
			for (int i=0;i<3;i++) {
				kk += floor(abs(((line[i].u-dst) ^ (line[i].v - dst)) / line[i].length()) / H);
				if (sgn((line[i].u - dst) ^ (line[i].v - dst)) != sgn((line[i].u - src) ^ (line[i].v - src))) {
					kk ++;
				}
			}
			if (kk < k) {
				l = mid;
			}
			else r = mid;
		}
		printf("%0.10lf\n",l);
	}
	return 0;
}
