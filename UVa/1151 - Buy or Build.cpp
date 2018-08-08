#include <bits/stdc++.h>
using namespace std;
struct pos {
	int x,y;
}p[1005];
struct edge {
	int u,v,w;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w < b.w;
	}
};
vector <edge> e;
struct network {
	int n,c;
	vector <int> v;
}qi[10];
int n,q;
int f[1005];
int find(int x) {
	if (f[x] == x) return x;
	else {
		f[x] = find(f[x]);
		return f[x];
	}
}
void uni(int x,int y) {
	f[find(x)] = find(y);
}
int getdis(int i,int j) {
	int dx = p[i].x - p[j].x;
	int dy = p[i].y - p[j].y;
	return dx * dx + dy * dy;
}
int main() {
	int T;
	scanf("%d",&T);
	bool first = true;
	while (T--) {
		if (!first) printf("\n");
		first = false;
		e.clear();
		scanf("%d%d",&n,&q);
		for (int i=0;i<q;i++) {
			scanf("%d%d",&qi[i].n,&qi[i].c);
			qi[i].v.clear();
			for (int j=0;j<qi[i].n;j++) {
				int t;
				scanf("%d",&t);
				qi[i].v.push_back(t);
			}
		}
		for (int i=1;i<=n;i++) {
			scanf("%d%d",&p[i].x,&p[i].y);
			for (int j=1;j<i;j++) e.push_back((edge){i,j,getdis(i,j)});
		}
		sort(e.begin(),e.end());
		int ans = 0x3f3f3f3f;;
		for (int stat=0;stat < (1<<q);stat++) {
			int curans = 0;
			for (int i=1;i<=n;i++) f[i] = i;
			for (int i=0;i<q;i++) if (stat & (1 << i) ) {
				curans += qi[i].c;
				for (int j=1;j<qi[i].v.size();j++) uni(qi[i].v[0],qi[i].v[j]);
			}
			for (auto ee:e) {
				if (find(ee.u) != find(ee.v)) {
					uni(ee.u,ee.v);
					curans += ee.w;
				}
			}
			ans = min(ans,curans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
