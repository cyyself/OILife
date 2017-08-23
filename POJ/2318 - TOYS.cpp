#include <cstdio>
int n,m,x1,y1,x2,y2;
struct cb {//cardboard
	int u,l;//(u,y1)->(l,y2)
	int t;//tot
}c[5005];
double cp(double x1,double y1,double x2,double y2) {
	return x1 * y2 - x2 * y1;
}
int find(int x,int y) {
	int l = 0;
	int r = n;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (cp(c[mid].l-c[mid].u,y2-y1,x-c[mid].u,y-y1) < 0) r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	return ans;
}
int main() {
	while (scanf("%d",&n) == 1 && n) {
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		c[0].u = c[0].l = x1;
		c[0].t = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d",&c[i].u,&c[i].l);
			c[i].t = 0;
		}
		while (m--) {
			int x,y;
			scanf("%d%d",&x,&y);
			c[find(x,y)].t ++;
		}
		for (int i=0;i<=n;i++) {
			printf("%d: %d\n",i,c[i].t);
		}
		printf("\n");
	}
	return 0;
}
