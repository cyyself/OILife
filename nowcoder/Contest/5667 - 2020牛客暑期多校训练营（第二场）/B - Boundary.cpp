#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

const int maxn=2005;

const double eps=1e-3;

struct Point {
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y) {}
} a[maxn];

Point tcircle(Point pt1, Point pt2, Point pt3, double &radius) {
	double x1 = pt1.x, x2 = pt2.x, x3 = pt3.x;
	double y1 = pt1.y, y2 = pt2.y, y3 = pt3.y;
	double a = x1 - x2;
	double b = y1 - y2;
	double c = x1 - x3;
	double d = y1 - y3;
	double e = ((x1 * x1 - x2 * x2) + (y1 * y1 - y2 * y2)) / 2.0;
	double f = ((x1 * x1 - x3 * x3) + (y1 * y1 - y3 * y3)) / 2.0;
	double det = b * c - a * d;
	if( fabs(det) < eps) {
		radius = -1;
		return Point(0,0);
	}

	double x0 = -(d * e - b * f) / det;
	double y0 = -(a * f - c * e) / det;
	radius = hypot(x1 - x0, y1 - y0);
	return Point(x0, y0);
}

int dcmp(double x,double y) {
	if(fabs(x-y)<eps)return 0;
	return x<y?-1:1;
}

struct node {
	double x,y,r;
	node(double _x=0,double _y=0,double _r=0):x(_x),y(_y),r(_r) {}
	bool operator < (const node &b) const {
		if (fabs(r-b.r) < eps && fabs(x-b.x) < eps && fabs(y-b.y) < eps) return false;//equal
		return dcmp(r,b.r)<0||(dcmp(r,b.r)==0&&dcmp(x,b.x)<0)||(dcmp(r,b.r)==0&&dcmp(x,b.x)==0&&dcmp(y,b.y)<0);
	}
};

//map<node,int> M;
int n;
node mem[4000000];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	if(n==1) {
		puts("1");
		return 0;
	}
	int memcnt = 0;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++) {
			double r=0;
			Point tmp=tcircle(a[i],a[j],Point(0,0),r);
			if(r==-1)continue;
			node tmpp=node(tmp.x,tmp.y,r);
			mem[memcnt++] = tmpp;
			//M[tmpp]++;
		}
	sort(mem,mem+memcnt);
	int curcnt = 0;
	int st = 0;
	int ans = 1;
	node x;
	for (int i=0;i<memcnt;i++) {
		if (i == 0) {
			curcnt = 1;
		}
		else {
			bool eq = !(mem[i] < mem[i-1]) && !(mem[i-1] < mem[i]);
			if (eq) {
				curcnt ++;
			}
			else {
				if (curcnt > ans) {
					ans = curcnt;
					x = mem[st];
				}
				curcnt = 1;
				st = i;
			}
		}
	}
	if (curcnt > ans) {
		ans = curcnt;
		x = mem[st];
	}
	if(ans==1)printf("%d\n",ans);
	else {
		int cnt=0;
		for(int i=1; i<=n; i++)if(dcmp((a[i].x-x.x)*(a[i].x-x.x)+(a[i].y-x.y)*(a[i].y-x.y),x.r*x.r)==0)cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
