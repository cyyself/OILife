#include <bits/stdc++.h>
using namespace std;
struct DATA {
	double x_1,y_1,x_2,y_2;
}r[105];
struct scanline {
	double x;
	int y_1,y_2;
	int d;//1:开始,-1:结束
	friend bool operator < (const scanline &a,const scanline &b) {
		if (a.x == b.x) return a.d < b.d;
		else return a.x < b.x;
	}
}l[205];
vector <double> y;
int main() {
	int n;
	int cas = 0;
	while (scanf("%d",&n) == 1 && n) {
		y.clear();
		for (int i=0;i<n;i++) {
			scanf("%lf%lf%lf%lf",&r[i].x_1,&r[i].y_1,&r[i].x_2,&r[i].y_2);
			y.push_back(r[i].y_1);
			y.push_back(r[i].y_2);
		}
		sort(y.begin(),y.end());
		auto it = unique(y.begin(),y.end());
		y.erase(it,y.end());
		unsigned int len = y.size();
		for (unsigned int i=1;i<len;i++) y.push_back((y[i]+y[i-1])/2.0);
		y.push_back(1e9);
		sort(y.begin(),y.end());//方便离散化之后的连续问题
		int lcnt = 0;
		for (int i=0;i<n;i++) {
			int y_1 = lower_bound(y.begin(),y.end(),r[i].y_1)-y.begin();
			int y_2 = lower_bound(y.begin(),y.end(),r[i].y_2)-y.begin();
			l[lcnt++] = (scanline){r[i].x_1,y_1,y_2,1};
			l[lcnt++] = (scanline){r[i].x_2,y_1,y_2,-1};
		}
		sort(l,l+lcnt);
		double ans = 0;
		int cnt[405];
		memset(cnt,0,sizeof(cnt));
		double lastx = -1e9;
		for (int i=0;i<lcnt;i++) {
			if (l[i].x != lastx) {
				double dx = l[i].x - lastx;
				double lasty = -1e9;
				for (unsigned int j=0;j<y.size();j++) {
					if (cnt[j]) {
						if (lasty == -1e9) lasty = y[j];
					}
					else {
						if (lasty != -1e9) ans += dx * (y[j-1] - lasty);
						lasty = -1e9;
					}
				}
				lastx = l[i].x;
			}
			for (int j=l[i].y_1;j<=l[i].y_2;j++) cnt[j] += l[i].d;
		}
		printf("Test case #%d\nTotal explored area: %0.2lf\n\n",++cas,ans);
	}
	return 0;
}
