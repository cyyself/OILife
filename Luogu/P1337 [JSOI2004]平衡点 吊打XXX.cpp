#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int maxn = 1005;
pair <pair<int,int>,int> p[maxn];
int n;
double cal(double x,double y) {
	double res = 0;
	for (int i=1;i<=n;i++) {
		double dx = p[i].x.x - x;
		double dy = p[i].x.y - y;
		res += sqrt(dx * dx + dy * dy) * p[i].y;
	}
	return res;
}
const double eps = 1e-15;
void sa(double &x,double &y) {
	double t = 10000;
	const double dt = 0.95;
	double last_res = cal(x,y);
	for (int i=0;i<2000;i++) {
		double nx = x + (rand()-RAND_MAX/2) * t;
		double ny = y + (rand()-RAND_MAX/2) * t;
		double res = cal(nx,ny);
		if (res < last_res || (exp(-(res-last_res)/t) * RAND_MAX > rand())) {
			x = nx;
			y = ny;
			last_res = res;
		}
		t *= dt;
	}
}
int main() {
	scanf("%d",&n);
	double x = 0, y = 0;
	for (int i=1;i<=n;i++) {
		scanf("%d%d%d",&p[i].x.x,&p[i].x.y,&p[i].y);
		x += p[i].x.x;
		y += p[i].x.y;
	}
	x /= n;
	y /= n;
	for (int i=0;i<20;i++) sa(x,y);
	printf("%0.3lf %0.3lf\n",x,y);
	return 0;
}
