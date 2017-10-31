#include <bits/stdc++.h>
using namespace std;
double ans = 1e9;
struct pos {
	double x,y;
	bool used;
}a[20];
int n;
inline double dis(pos a,pos b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
void DFS(int depth,pos last,double cur) {
	if (depth == n) {
		ans = min(ans,cur);
		return;
	}
	for (int i=0;i<n;i++) {
		if (cur > ans) return;
		if (a[i].used) continue;
		a[i].used = true;
		DFS(depth+1,a[i],cur+dis(last,a[i]));
		a[i].used = false;
	}
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	pos tmp;
	tmp.x = 0;
	tmp.y = 0;
	DFS(0,tmp,0);
	printf("%0.2lf\n",ans);
	return 0;
}
