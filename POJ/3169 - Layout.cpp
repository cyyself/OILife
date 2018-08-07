#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int v,w;
};
vector<edge> g[1005];
int dis[1005];
int cnt[1005];
bool inq[1005];
int n;
void spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(inq,false,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	queue <int> q;
	dis[s] = 0;
	inq[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		if (cnt[u] > n) {
			dis[n] = -1;
			break;
		}
		for (vector<edge>::iterator it=g[u].begin();it != g[u].end();it++) {
			int v = it->v;
			int w = it->w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	if (dis[n] == INF) dis[n] = -2;
}
int main() {
	int ml,md;
	scanf("%d%d%d",&n,&ml,&md);
	while (ml --) {
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		g[a].push_back((edge){b,d});
	}
	while (md --) {
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		g[b].push_back((edge){a,-d});
	}
	spfa(1);
	printf("%d\n",dis[n]);
	return 0;
}
