#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long maxn = 105;
const long long maxe = 105*105;
struct Edge{
	long long f,used,v,next;
}e[maxe];
long long ecnt;
long long head[maxn];
void _AddEdge(long long u,long long v,long long c,long long used) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].used = used;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void AddEdge(long long u,long long v,long long c,long long used = 0) {
	_AddEdge(u,v,c,used);
	_AddEdge(v,u,0,used);
}
long long dis[maxn];
bool bfs(long long s,long long t) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 1;
	queue <int> q;
	q.push(s);
	while(!q.empty()) {
		long long u = q.front();
		q.pop();
		if (u == t) return 1;
		for (long long i=head[u];i!=-1;i = e[i].next) {
			long long v = e[i].v;
			if (e[i].f != 0 && dis[v] == INF) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[t] != INF;
}
 
long long dfs(long long u,long long t,long long curflow) {
	if (curflow == 0 || u == t) return curflow;
	if (dis[u] >= dis[t]) return 0;
	long long ret = 0;
	for (long long i=head[u];i!=-1 && ret < curflow;i=e[i].next) {
		long long v = e[i].v;
		long long f = e[i].f;
		if (dis[v] == dis[u] + 1 && f != 0) {
			long long pushflow = min(curflow-ret,f);
			long long chflow = dfs(v,t,pushflow);
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
long long dinic(long long s,long long t) {
	long long ans = 0;
	while(bfs(s,t)) ans += dfs(s,t,INF);
	return ans;
}
long long d[maxn];
void addedge(long long u,long long v,long long f_min,long long f_max) {
	AddEdge(u,v,f_max-f_min,f_min);
	d[u] += f_min;
	d[v] -= f_min;
}
void build(long long s,long long t,long long ss,long long tt,long long &need) {
	for (long long i=s;i<=t;i++) {
		if (d[i] < 0) AddEdge(ss,i,-d[i]);
		else {
			need += d[i];
			AddEdge(i,tt,d[i]);
		}
	}
}
int main() {
	long long n,m;
	memset(head,-1,sizeof(head));
	ecnt = 0;
	scanf("%lld%lld",&n,&m);
	for (long long i=0;i<m;i++) {
		long long u,v,z,c;
		scanf("%lld%lld%lld%lld",&u,&v,&z,&c);
		u++;v++;
		if (c) addedge(u,v,z,z);
		else addedge(u,v,0,z);
	}
	long long need = 0;
	AddEdge(1,2,INF);
	AddEdge(n+1,n+2,INF);
	build(1,n+2,0,n+3,need);
	AddEdge(n+2,1,INF);
	if (dinic(0,n+3) == need) {
		long long ans = e[ecnt-1].f;
		e[ecnt-1].f = 0;
		e[ecnt-2].f = 0;
		ans -= dinic(n+2,1);
		printf("%lld\n",ans);
		for (long long i=0;i<m;i++) {
			printf("%lld%c",e[i*2+1].f+e[i*2+1].used,i==m-1?'\n':' ');
		}
	}
	else printf("Impossible\n");
	return 0;
}
