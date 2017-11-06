#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m;
int head[300005];
struct Edge {
	int v,w,next;
}e[600005];
int ecnt = 0;
inline void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
struct Task{
	int u,v,len,lca;
	friend bool operator < (const Task &a,const Task &b){
		if (a.len < b.len) return true;
		else return false;
	}
}t[300005];
int qhead[300005];
struct Query {
	int v,next;
}q[600005];
int qcnt = 0;
inline void AddQuery(int u,int v) {
	q[qcnt].v = v;
	q[qcnt].next = qhead[u];
	qhead[u] = qcnt;
	qcnt ++;
}
int f[300005];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
inline void uni(int x,int y) {
	f[find(x)] = find(y);
}
int dis[300005];
int pre[300005];
void tarjan(int u) {
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		if (dis[v] == inf) {
			dis[v] = dis[u] + e[i].w;
			pre[v] = i;
			tarjan(v);
			uni(v,u);
		}
	}
	for (int i=qhead[u];~i;i=q[i].next) {
		int v = q[i].v;
		int op = i >> 1;
		if (dis[v] != inf) {
			t[op].lca = find(v);
			t[op].len = dis[t[op].u] + dis[t[op].v] - dis[t[op].lca] * 2;
		}
	}
}
int cnt;
int pass[300005];
int maxw;
bool vis[300005];
int dfs(int u) {
	vis[u] = true;
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) pass[u] += dfs(v);
	}
	if (pass[u] == cnt) maxw = max(e[pre[u]].w,maxw);
	return pass[u];
}
inline bool judge(int maxcost) {
	int i;
	memset(pass,0,sizeof(pass));
	memset(vis,0,sizeof(vis));
	cnt = 0;
	maxw = 0;
	for (i=0;i<m;i++) if (t[i].len > maxcost) break;
	if (i == m-1 && t[m-1].len <= maxcost) return true;//不需要改造
	//改造是否达标
	for (i;i<m;i++) {
		pass[t[i].u] ++;
		pass[t[i].v] ++;
		pass[t[i].lca] -= 2;
		cnt ++;
	}
	dfs(1);
	if (t[m-1].len > maxcost + maxw) return false;//改造了也不够
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i] = i;
	memset(head,-1,sizeof(head));
	memset(qhead,-1,sizeof(qhead));
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<n;i++) {
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		AddEdge(a,b,w);
		AddEdge(b,a,w);
	}
	for (int i=0;i<m;i++) {
		scanf("%d%d",&t[i].u,&t[i].v);
		AddQuery(t[i].u,t[i].v);
		AddQuery(t[i].v,t[i].u);
	}
	dis[1] = 0;
	tarjan(1);
	sort(t,t+m);
	int l = 0;
	int r = 1e9;
	int ans = -1;
	while (l <= r) {
		int mid = (l+r) >> 1;
		if (judge(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n",ans);
	return 0;
}
