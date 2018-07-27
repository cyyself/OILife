#include <bits/stdc++.h>
using namespace std;
struct Pos {
	double x,y;
	friend bool operator < (const Pos &a,const Pos &b) {
		if (a.x < b.x) return true;
		if (a.x == b.x && a.y < b.y) return true;
		return false;
	}
}p[10005];
double getdis(int i,int j) {
	double dx = p[i].x - p[j].x;
	double dy = p[i].y - p[j].y;
	return sqrt(dx*dx+dy*dy);
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p,p+n);
	double ans = getdis(0,n-1);//数据保证n大于等于2
	for (int i=1;i<=n-2;i++) {
		for (int j=i-1;j>=0 && fabs(p[i].x-p[j].x) < ans;j--) ans = min(ans,getdis(i,j));
		for (int j=i+1;j<n  && fabs(p[i].x-p[j].x) < ans;j++) ans = min(ans,getdis(i,j));
	}
	printf("%0.4lf\n",ans);
	return 0;
}
