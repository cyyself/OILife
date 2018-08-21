#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge {
	int v,w;
	int next;
}e[20005];
struct p {
	int u;
	int dis;
	friend bool operator < (const p &a,const p &b) {
		return a.dis > b.dis;
	}
	p (int _u,int _dis) {
		u = _u;
		dis = _dis;
	}
};
int ecnt;
int head[20005];
void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int dis[20005];
void getdis(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	priority_queue <p> q;
	q.push(p(s,dis[s]));
	while (!q.empty()) {
		p cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.dis) continue;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(p(v,dis[v]));
			}
		}
	}
}
map <string,int> mem;
int getnum(string name) {
	if (mem[name] == 0) return mem[name] = mem.size() + 1;
	else return mem[name];
}
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		mem.clear();
		if (n == -1) break;
		memset(head,-1,sizeof(head));
		ecnt = 0;
		string s_name,t_name;
		cin >> s_name >> t_name;
		int s = getnum(s_name);
		int t = getnum(t_name);
		for (int i=0;i<n;i++) {
			string a,b;
			int w;
			cin >> a >> b >> w;
			int u = getnum(a);
			int v = getnum(b);
			AddEdge(u,v,w);
			AddEdge(v,u,w);
		}
		getdis(s);
		if (dis[t] == INF) printf("-1\n");
		else printf("%d\n",dis[t]);
	}
	return 0;
}
