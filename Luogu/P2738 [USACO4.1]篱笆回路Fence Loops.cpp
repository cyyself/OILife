/*
大致做法：
将每个篱笆视为一个端点，篱笆的长度当做端点的权值，然后篱笆两边所连的点分别建图
（可以用两个邻接表，或者vector）
然后枚举两个相连的篱笆，记为s与t
每次屏蔽s所连t的那一端的所有点，跑一遍Dijkstra或者SPFA，记录s到t经过的点的权值总和
（这个权值总和包含s和t点，因此我们可以在跑Dijkstra的时候，设dis[s] = w[s]）
最后把dis[s][t]取个最小值作为答案就可以了
*/
#include <bits/stdc++.h>
using namespace std;
vector <int> g[105][2];//将每个篱笆视为一个端点，其两端所连接的其它篱笆分开存储
int w[105];
struct DATA {
	int dis,u;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
int dis[105];
int dij(int s,int type,int t) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = w[s];
	priority_queue <DATA> q;
	q.push((DATA){dis[s],s});
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		if (cur.dis > dis[cur.u]) continue;
		if (cur.u == t) return dis[t];
		for (int typ=0;typ<2;typ++) {
			//判断屏蔽条件
			if (cur.u == s && typ == type) continue;
			for (auto v:g[cur.u][typ]) {
				if (dis[cur.u] + w[v] < dis[v]) {
					dis[v] = dis[cur.u] + w[v];
					q.push((DATA){dis[v],v});
				}
			}
		}
	}
	return 0x3f3f3f3f;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		//将篱笆当做一个点
		int u,l,n1,n2;
		scanf("%d%d%d%d",&u,&l,&n1,&n2);
		w[u] = l;//篱笆的长度
		while (n1 --) {
			int v;
			scanf("%d",&v);
			g[u][0].push_back(v);
			//将一个篱笆所连接的两端分别存储
		}
		while (n2 --) {
			int v;
			scanf("%d",&v);
			g[u][1].push_back(v);
		}
	}
	int ans = 0x3f3f3f3f;
	for (int u=1;u<=n;u++) {
		//枚举两个篱笆u,v，并把他们两相连的那一端的所有点屏蔽，跑Dijkstra获得从u到v的距离
		for (auto v:g[u][0]) ans = min(ans,dij(u,0,v));
		for (auto v:g[u][1]) ans = min(ans,dij(u,1,v));
	}
	printf("%d\n",ans);
	return 0;
}
