#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct Pos{
	int x;
	int y;
}P[1005];
struct Edge{
	int u,v;
	double w;
};
vector <Edge> e;
int father[1005];
int n,m;
int find(int x) {
	if (father[x] == x) return x;
	else {
		father[x] = find(father[x]);
		return father[x];
	}
}
inline void uni(int x,int y) {
	father[find(x)] = find(y);
}
bool comp(const Edge &a,const Edge &b) {
	if (a.w < b.w) return true;
	return false;
}
inline double gougu(int dx,int dy) {
	return sqrt((double)dx * dx + (double)dy * dy);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) father[i] = i;
	for (int i=1;i<=n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		P[i] = (Pos){x,y};
		for (int j=1;j<i;j++) e.push_back((Edge){i,j,gougu(P[i].x-P[j].x,P[i].y-P[j].y)});
	}
	int edgen = 0;
	for (int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		//e.push_back((Edge){u-1,v-1,0});
		if (find(u) != find(v)) {
			edgen++;
			uni(u,v);
		}
	}
	double totw = 0;
	sort(e.begin(),e.end(),comp);
	/*
	for (int i=0;i<e.size();i++) {
		printf("Edge:%d,%d,%lf\n",e[i].u,e[i].v,e[i].w);
	}
	*/
	for (int i=0;i<e.size();i++) {
		if (find(e[i].u) != find(e[i].v)) {
			uni(e[i].u,e[i].v);
			totw += e[i].w;
			edgen++;
		}
		if (edgen >= n - 1) break;
	}
	printf("%.2lf\n",totw);
	return 0;
}