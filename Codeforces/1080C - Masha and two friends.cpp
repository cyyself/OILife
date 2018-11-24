#include <bits/stdc++.h>
using namespace std;
struct rec {
	long long x1,y1,x2,y2;
	long long dx,dy;
	void read() {
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		dx = x2 - x1 + 1;
		dy = y2 - y1 + 1;
	}
}r[3];
long long cur_white,cur_black;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,m;
		scanf("%lld%lld",&n,&m);
		r[0].read();
		r[1].read();
		cur_white = (n * m + 1) / 2;
		cur_black = (n * m) / 2;
		//printf("%lld %lld\n",cur_white,cur_black);
		cur_black -= (r[0].dx * r[0].dy + (r[0].x1 + r[0].y1) % 2) / 2;
		cur_white += (r[0].dx * r[0].dy + (r[0].x1 + r[0].y1) % 2) / 2;
		//printf("%lld %lld\n",cur_white,cur_black);
		cur_white -= (r[1].dx * r[1].dy + !((r[1].x1 + r[1].y1) % 2)) / 2;
		cur_black += (r[1].dx * r[1].dy + !((r[1].x1 + r[1].y1) % 2)) / 2;
		//printf("%lld %lld\n",cur_white,cur_black);
		r[2].x1 = max(r[0].x1,r[1].x1);
		r[2].x2 = min(r[0].x2,r[1].x2);
		r[2].y1 = max(r[0].y1,r[1].y1);
		r[2].y2 = min(r[0].y2,r[1].y2);
		r[2].dx = r[2].x2 - r[2].x1 + 1;
		r[2].dy = r[2].y2 - r[2].y1 + 1;
		if (r[2].x1 <= r[2].x2 && r[2].y1 <= r[2].y2) {
			cur_white -= (r[2].dx * r[2].dy + ((r[2].x1 + r[2].y1) % 2)) / 2;
			cur_black += (r[2].dx * r[2].dy + ((r[2].x1 + r[2].y1) % 2)) / 2;
		}
		printf("%lld %lld\n",cur_white,cur_black);
	}
	return 0;
}
