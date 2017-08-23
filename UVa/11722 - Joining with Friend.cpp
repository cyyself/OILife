#include <bits/stdc++.h>
using namespace std;
double t1,t2,s1,s2;
double width,height;
double getarea(double w) {
	double tx = s2 - w;
	double bx = s1 - w;
	double ly = t1 + w;
	double ry = t2 + w;
	bool left = (ly <= s2 && ly >= s1);
	bool right = (ry <= s2 && ry >= s1);
	bool top = (tx <= t2 && tx >= t1);
	bool bottom = (bx <= t2 && bx >= t1);
	if (left && top) return (tx - t1) * (s2 - ly) * 0.5;
    if (left && right) return ((tx - t1) * (s2 - ly) - (tx - t2) * (s2 - ry)) * 0.5;
    if (top && bottom) return ((tx - t1) * (s2 - ly) - (s1 - ly) * (bx - t1)) * 0.5;
    if (bottom && right) return (height * width) - (t2 - bx) * (ry - s1) * 0.5;
    if (ly <= s1) return (height * width);
    return 0;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas ++) {
		double w;
		scanf("%lf%lf%lf%lf%lf",&t1,&t2,&s1,&s2,&w);
		width = t2 - t1;
		height = s2 - s1;
		printf("Case #%d: %.8lf\n", cas, (getarea(-w) - getarea(w)) / (width * height));
	}
	return 0;
}
