#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
const double eps = 1e-8;
int n;
struct wall {
	double x,a1,b1,a2,b2;
}w[25];
struct link {
	int head[100];
	int v[1000005];
	int next[1000005];
	double w[1000005];
	int cnt;
	inline void init() {
		memset(head,-1,sizeof(next));
		cnt = 0;
	}
	inline void AddEdge(int _u,int _v,double _w) {
		next[cnt] = head[_u];
		head[_u] = cnt;
		v[cnt] = _v;
		w[cnt] = _w;
		cnt ++;
	}
	double spfa() {
		double dis[100];
		bool inq[100];
		for (int i=0;i<100;i++) dis[i] = 1e9;
		memset(inq,false,sizeof(inq));
		queue <int> q;
		q.push(0);
		dis[0] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			for (int e=head[cur];e!=-1;e=next[e]) {
				if (dis[cur] + w[e] - eps < dis[v[e]]) {
					dis[v[e]] = dis[cur] + w[e];
					if (!inq[v[e]]) {
						q.push(v[e]);
						inq[v[e]] = true;
					}
				}
			}
		}
		return dis[4*n+1];
	}
}l;
struct pos {
	double x,y;
	pos(double _x=0,double _y=0):x(_x),y(_y) {

	}
};
inline double dis(pos a,pos b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx+dy*dy);
}
inline bool judgewall(int _w,double h) {//输入在这堵墙的h坐标时是否被这堵墙阻挡，没阻挡为true
	return (h+eps > w[_w].a1 && h-eps < w[_w].b1) || (h + eps > w[_w].a2 && h - eps < w[_w].b2);
}
inline bool judge(pos s,pos e) {
	if (abs(e.x - s.x) < eps) return false;
	if (s.x > e.x) swap(s,e);
	double k = (e.y-s.y)/(e.x-s.x);
	double b = s.y - k * s.x;
	for (int i=0;i<n;i++) if (w[i].x - eps > s.x && w[i].x + eps < e.x) 
		if (!judgewall(i,w[i].x*k+b)) return false;
	return true;
}
inline void build_link(int node,double x,double y) {
	//起点编号为0，其他点编号为4*w+{1,2,3,4}，终点编号为4*n+1
	pos s = pos(x,y);
	pos e;
	for (int i=0;i<n;i++) {
		e = pos(w[i].x,w[i].a1);
		if (judge(s,e)) l.AddEdge(node,i*4+1,dis(s,e));
		e = pos(w[i].x,w[i].b1);
		if (judge(s,e)) l.AddEdge(node,i*4+2,dis(s,e));
		e = pos(w[i].x,w[i].a2);
		if (judge(s,e)) l.AddEdge(node,i*4+3,dis(s,e));
		e = pos(w[i].x,w[i].b2);
		if (judge(s,e)) l.AddEdge(node,i*4+4,dis(s,e));
	}
	e = pos(10,5);
	if (judge(s,e)) l.AddEdge(node,4*n+1,dis(s,e));
}

int main() {
	while (scanf("%d",&n) == 1 && n >= 0) {
		for (int i=0;i<n;i++) cin >> w[i].x >> w[i].a1 >> w[i].b1 >> w[i].a2 >> w[i].b2;
		//scanf("%lf%lf%lf%lf%lf",&w[i].x,&w[i].a1,&w[i].b1,&w[i].a2,&w[i].b2);
		l.init();
		build_link(0,0,5);
		for (int i=0;i<n;i++) {
			build_link(4*i+1,w[i].x,w[i].a1);
			build_link(4*i+2,w[i].x,w[i].b1);
			build_link(4*i+3,w[i].x,w[i].a2);
			build_link(4*i+4,w[i].x,w[i].b2);
		}
		cout<<fixed<<setprecision(2)<<l.spfa()<<endl;
		//printf("%0.2f\n",);
	}
	return 0;
}
