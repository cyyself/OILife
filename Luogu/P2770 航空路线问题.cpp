#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u;
	int v;
	int f;
	int c;
	int next;
}e[100005];
int head[205];
int pre[205];
int n,m,s,t;
int ecnt;
inline void AddEdge(int _u,int _v,int _f,int _c) {
	e[ecnt].next = head[_u];
	head[_u] = ecnt;
	e[ecnt].u = _u;
	e[ecnt].v = _v;
	e[ecnt].f = _f;
	e[ecnt].c = _c;
	ecnt++;
}
inline void Add(int _u,int _v,int _f,int _c) {
	AddEdge(_u,_v,_f,_c);
	AddEdge(_v,_u,0,-_c);
}
int dis[205];
bool inq[205];
bool SPFA(int s,int t) {
	queue <int> q;
	q.push(s);
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	inq[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i = head[cur];i != -1;i = e[i].next) {
			if (e[i].f > 0 && dis[e[i].v] > dis[cur] + e[i].c) {
				dis[e[i].v] = dis[cur] + e[i].c;
				pre[e[i].v] = i;
				if (!inq[e[i].v]) {
					inq[e[i].v] = true;
					q.push(e[i].v);
				}
			}
		}
	}
	return dis[t] != INF;
}
vector <int> ans[2];
void MICMAF(int s,int t,int &flow,int &cost) {
	flow = 0;
	cost = 0;
	while (SPFA(s,t)) {
		int minF = INF;
		for (int i=pre[t];i != -1;i=pre[e[i].u]) {
			minF = min(minF,e[i].f);
			if (ans[flow].size() == 0 || e[i].v != ans[flow][ans[flow].size()-1]-1) ans[flow].push_back(e[i].v);
		}
		flow += minF;
		for (int i=pre[t];i != -1;i=pre[e[i].u]) {
			e[i].f -= minF;
			e[i^1].f += minF;
		}
		cost += dis[t] * minF;
	}
}
vector <int> path[2];
void dfs(int u,int p) {
	for (int i=head[u];~i;i=e[i].next) {
		if ( (i & 1) == 0 && e[i].f == 0) {
			if (e[i].v == (u ^ 1) ) path[p].push_back(e[i].u/2);
			dfs(e[i].v,p);
		}
	}
}
void debug() {

}
int main() {
	memset(head,-1,sizeof(head));
	int n,m;
	cin >> n >> m;
	ecnt = 0;
	unordered_map <string,int> h;
	unordered_map <int,string> h2;
	for (int i=1;i<=n;i++) {
		string t;
		cin >> t;
		h[t] = i;
		h2[i] = t;
		Add(i*2,i*2+1,(i==1||i==n)?2:1,-1);
	}
	for (int i=0;i<m;i++) {
		string u,v;
		cin >> u >> v;
		if (h[u] > h[v]) swap(u,v);
		Add(h[u]*2+1,h[v]*2,1,0);
		if (h[u] == 1 && h[v] == n) Add(h[u]*2+1,h[v]*2,1,0);
	}
	int f,c;
	MICMAF(1*2,2*n+1,f,c);
	if (f == 2) {
		int p = 0;
		for (int i=head[1*2+1];~i;i=e[i].next) {
			if ( (i & 1) == 0 && e[i].f == 0) dfs(e[i].v,p++);
		}
		reverse(path[1].begin(),path[1].end());
		cout << path[0].size() + path[1].size() << "\n";
		cout << h2[1] << "\n";
		for (auto x:path[0]) cout << h2[x] << "\n";
		path[1].erase(path[1].begin());
		for (auto x:path[1]) cout << h2[x] << "\n";
		cout << h2[1] << "\n";
	}
	else printf("No Solution!\n");
	return 0;
}
