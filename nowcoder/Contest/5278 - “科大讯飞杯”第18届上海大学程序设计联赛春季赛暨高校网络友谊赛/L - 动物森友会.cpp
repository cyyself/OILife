#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
namespace dinic {
	const long long INF = 0x3f3f3f3f3f3f3f3f;
	struct Edge{
		int v,next;
		long long f;
	}e[200005];
	int ecnt;
	int head[150];
	void _AddEdge(int u,int v,long long c) {
		e[ecnt].v = v;
		e[ecnt].f = c;
		e[ecnt].next = head[u];
		head[u] = ecnt;
		ecnt ++;
	}
	void AddEdge(int u,int v,long long c) {
		_AddEdge(u,v,c);
		_AddEdge(v,u,0);
	}
	int dis[150];
	bool bfs(int s,int t) {
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
				if (e[i].f != 0 && dis[v] == 0x3f3f3f3f) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		return dis[t] != 0x3f3f3f3f;
	}
	long long dfs(int u,int t,long long curflow) {
		if (curflow == 0 || u == t) return curflow;
		if (dis[u] >= dis[t]) return 0;
		long long ret = 0;
		for (int i=head[u];i!=-1 && ret < curflow;i=e[i].next) {
			int v = e[i].v;
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
	long long dinic(int s,int t) {
		long long ans = 0;
		while(bfs(s,t)) ans += dfs(s,t,INF);
		return ans;
	}
	void clear() {
		memset(head,-1,sizeof(head));
		ecnt = 0;
	}
}
int cnt[1<<7];
int f[1<<7];
int n,e;
bool check(long long x) {
	dinic::clear();
	long long full = 0;
	for (int i=1;i<(1<<7);i++) {
		if (cnt[i] == 0) continue;
		full += cnt[i];
		dinic::AddEdge(0,i,cnt[i]);
		for (int j=1;j<=7;j++) if (i & (1<<(j-1))) dinic::AddEdge(i,130+j,cnt[i]);
	}
	for (int j=1;j<=7;j++) dinic::AddEdge(130+j,140,e*(x/7+(j<=x%7)));
	int flow = dinic::dinic(0,140);
	return flow == full;
}
int main() {
	scanf("%d%d",&n,&e);
	for (int i=1;i<=n;i++) {
		int c,m;
		scanf("%d%d",&c,&m);
		int stat = 0;
		for (int j=0;j<m;j++) {
			int x;
			scanf("%d",&x);
			stat |= (1 << (x - 1));
		}
		cnt[stat] += c;
	}
	long long l = 1, r = 1e9;
	long long ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld\n",ans);
	return 0;
}
