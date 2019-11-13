#include <bits/stdc++.h>
using namespace std;
int h[20];
vector <int> st[20];
int n,m,k;
struct UnionSet {
	int f[20];
	void init(int sz) {
		for (int i=0;i<sz;i++) f[i] = i;
	}
	int find(int x) {
		if (f[x] == x) return x;
		else return f[x] = find(f[x]);
	}
	void uni(int x,int y) {
		f[find(x)] = find(y);
	}
}us;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[20*20*50*2*2];
int ecnt;
int head[51*20*51];
void _addedge(int u,int v,int c) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void addedge(int u,int v,int c) {
	_addedge(u,v,c);
	_addedge(v,u,0);
}
int dis[51*20*51];
bool bfs(int s,int t) {//划分层次，同时判断是否可到达
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 1;
	queue <int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == t) return 1;
		for (int i=head[u];i!=-1;i = e[i].next) {
			int v = e[i].v;
			if (e[i].f != 0 && dis[v] == INF) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[t] != INF;
}

int dfs(int u,int t,int curflow) {//curflow=>当前可增广的最大流量
	if (curflow == 0 || u == t) return curflow;
	if (dis[u] >= dis[t]) return 0;
	int ret = 0;
	for (int i=head[u];i!=-1 && ret < curflow;i=e[i].next) {
		int v = e[i].v;
		int f = e[i].f;
		if (dis[v] == dis[u] + 1 && f != 0) {
			int pushflow = min(curflow-ret,f);
			int chflow = dfs(v,t,pushflow);
			if (chflow > 0) {
				e[ i ].f -= chflow;//偶数+1,奇数-1，很巧妙的位运算
				e[i^1].f += chflow;
				ret += chflow;
			}
			else dis[v] = -1;
		}
	}
	if (ret == 0) dis[u] = -1;
	return ret;
}
int dinic(int s,int t) {
	int ans = 0;
	while(bfs(s,t)) ans += dfs(s,t,INF);
	return ans;
}
void addtime(int x) {
	addedge(1019,x*(n+2)+1,k);
	for (int i=0;i<n+2;i++) {
		addedge((x-1)*(n+2)+i,x*(n+2)+i,INF);
	}
	for (int i=0;i<m;i++) {
		int curpos = x % st[i].size();
		int lastpos = (x - 1 + st[i].size()) % st[i].size();
		addedge((x-1)*(n+2)+st[i][lastpos],x*(n+2)+st[i][curpos],h[i]);
	}
}
bool check(int x) {
	memset(head,-1,sizeof(head));
	ecnt = 0;
	addedge(1019,1,k);
	for (int i=1;i<=x;i++) addtime(i);
	return dinic(1019,x*(n+2)) >= k;
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) {
		scanf("%d",&h[i]);
		int r;
		scanf("%d",&r);
		while (r --) {
			int x;
			scanf("%d",&x);
			x ++;
			//moon:0,earth:1,other:2-n+1
			st[i].push_back(x);
		}
	}
	us.init(n+2);
	for (int i=0;i<m;i++) {
		for (int j=1;j<st[i].size();j++) us.uni(st[i][j],st[i][j-1]);
	}
	if (us.find(0) != us.find(1)) printf("0\n");
	else {
		int time = 1;
		while (!check(time)) time ++;
		printf("%d\n",time);
	}
	return 0;
}
