#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-6;
const long double num_1 = 1,num_2 = 2,num_3 = 3;
struct pos {
	long double x,y;
}p[100005];
int n;
bool exist_postive;
bool exist_negative;
/*
long double getr(long double x) {
	long double l = 0;
	long double r = 1;
	while (1) {
		long double mid = r;
		long double y = mid;
		if (exist_negative) y = -y;
		bool flag = true;
		for (int i=0;i<n && flag;i++) {
			long double dx = p[i].x-x;
			long double dy = p[i].y-y;
			if (sqrt(dx*dx+dy*dy) > mid) {
				flag = false;
			}
		}
		if (flag) break;
		else r *= 2;
	}
	while (r - l > eps) {
		long double mid = (l + r) / num_2;
		long double y = mid;
		bool flag = true;
		for (int i=0;i<n && flag;i++) {
			long double dx = p[i].x-x;
			long double dy = p[i].y-y;
			if (sqrt(dx*dx+dy*dy) > mid) {
				flag = false;
			}
		}
		if (flag) r = mid;
		else l = mid;
	}
	return l;
}
*/
long double getr(long double x) {
	long double r = 0;
	for (int i=0;i<n;i++) {
		long double dx = x - p[i].x;
		long double dy = p[i].y;
		r = max(r,(dx*dx+dy*dy)/2/dy);
	}
	return r;
}
int main() {
	cin >> n;
	exist_postive = false;
	exist_negative = false;
	for (int i=0;i<n;i++) {
		cin >> p[i].x >> p[i].y;
		if (p[i].y > 0) exist_postive = true;
		if (p[i].y < 0) exist_negative = true;
		if (exist_postive && exist_negative) {
			printf("-1\n");
			return 0;
		}
	}
	if (exist_negative) for (int i=0;i<n;i++) p[i].y = - p[i].y;
	//long double il = -4,ir = 4;
	long double il = -1e7,ir = 1e7;
	//long double il = -1e7,ir = 1e7;
	double ans;
	while (ir - il > eps) {
		//printf("il=%Lf ir=%Lf\n",il,ir);
		long double mid_1 = il + num_1 * (ir - il) / num_3;
		long double mid_2 = il + num_2 * (ir - il) / num_3;
		long double r_1 = getr(mid_1);
		long double r_2 = getr(mid_2);
		if (r_1 < r_2) {
			ir = mid_2;
			ans = r_1;
		}
		else {
			il = mid_1;
			ans = r_2;
		}
	}
	printf("%0.7lf\n",ans);
	return 0;
}
