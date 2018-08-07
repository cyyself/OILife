#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct edge{
	int v,w;
};
vector <edge> g1[1005];//正向图，用于计算从X出发的距离
vector <edge> g2[1005];//反向图，用于计算到达X点的距离
int dis1[1005];
bool inq[1005];
void spfa_1(int s) {
	queue <int> q;
	memset(dis1,0x3f,sizeof(dis1));
	memset(inq,false,sizeof(inq));
	dis1[s] = 0;
	inq[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (vector<edge>::iterator it=g1[u].begin();it !=g1[u].end();it ++) {
			int v = it->v;
			int w = it->w;
			if (dis1[v] > dis1[u] + w) {
				dis1[v] = dis1[u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int dis2[1005];
void spfa_2(int s) {
	queue <int> q;
	memset(dis2,0x3f,sizeof(dis2));
	memset(inq,false,sizeof(inq));
	dis2[s] = 0;
	inq[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (vector<edge>::iterator it=g2[u].begin();it !=g2[u].end();it ++) {
			int v = it->v;
			int w = it->w;
			if (dis2[v] > dis2[u] + w) {
				dis2[v] = dis2[u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int main() {
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	while (m--) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g1[u].push_back((edge){v,w});
		g2[v].push_back((edge){u,w});
	}
	spfa_1(x);
	spfa_2(x);
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (i == x) continue;
		ans = max(ans,dis1[i]+dis2[i]);
	}
	printf("%d\n",ans);
	return 0;
}
