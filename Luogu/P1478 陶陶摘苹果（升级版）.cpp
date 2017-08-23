#include <cstdio>
#include <algorithm>
using namespace std;
struct apple {
	int x,y;
	friend bool operator < (const apple &a,const apple &b) {
		if (a.y < b.y) return true;
		else return false;
	}
}a[5005];
int n=0,s,maxh;
int main() {
	int t,t1,t2;
	scanf("%d%d%d%d",&t,&s,&t1,&t2);
	maxh = t1 + t2;
	while(t --) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (x <= maxh) {
			a[n].x = x;
			a[n].y = y;
			n++;
		}
	}
	sort(a,a+n);
	int ans = 0;
	for (int i=0;i<n;i++) {
		if (s >= a[i].y) {
			s -= a[i].y;
			ans ++;
		}
	}
	printf("%d\n",ans);
	return 0;
}