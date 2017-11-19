#include <bits/stdc++.h>
using namespace std;
int n;
long long h,r;
const int maxn = 1010;
const int maxe = maxn*maxn;
const int inf = 0x3f3f3f3f;
int head[maxn];
struct Edge {
	int v;
	int nxt;
}e[maxe];
int ecnt;
inline void AddEdge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].nxt = head[u];
	head[u] = ecnt;
	ecnt ++;
}
struct kongdong {
	long long x,y,z;
}kd[maxn];
inline bool judge(kongdong a,kongdong b) {
	double dis = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
	if (dis <= 2 * r) return true;
	return false;
}
int dis[maxn];
queue <int> q;
bool inq[maxn];
bool spfa() {
	memset(dis,0x3f,sizeof(dis));
	memset(inq,false,sizeof(inq));
	dis[n+1] = 0;
	q.push(n+1);
	inq[n+1] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];i != -1;i=e[i].nxt) {
			int v = e[i].v;
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return dis[n+2] != inf;
}
int main() {
	//freopen("cheese.in","r",stdin);
	//freopen("cheese.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		scanf("%d%lld%lld",&n,&h,&r);
		for (int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&kd[i].x,&kd[i].y,&kd[i].z);
			for (int j=1;j<i;j++) {
				if (judge(kd[j],kd[i])) {
					AddEdge(i,j);
					AddEdge(j,i);
				}
			}
			if (kd[i].z <= r) AddEdge(n+1,i);
			if (kd[i].z >= h - r) AddEdge(i,n+2);
		}
		if (spfa()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
