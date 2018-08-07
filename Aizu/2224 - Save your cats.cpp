#include <bits/stdc++.h>
using namespace std;
pair <double,double> p[10005];
int f[10005];
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
struct edge {
	int u,v;
	double w;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w > b.w;
	}
};
double dis(int i,int j) {
	double dx = p[i].first - p[j].first;
	double dy = p[i].second - p[j].second;
	return sqrt(dx*dx + dy*dy);
}
vector <edge> e;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=1;i<=n;i++) scanf("%lf%lf",&p[i].first,&p[i].second);
	double sum = 0;
	for (int i=0;i<m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		e.push_back((edge){x,y,dis(x,y)});
		sum += dis(x,y);
	}
	sort(e.begin(),e.end());
	int cnt = 0;
	double ans = sum;
	for (edge cur:e) {
		if (find(cur.u) != find(cur.v)) {
			uni(cur.u,cur.v);
			cnt ++;
			ans -= cur.w;
			if (cnt == n - 1) break;
		}
	}
	printf("%lf\n",ans);
	return 0;
}
