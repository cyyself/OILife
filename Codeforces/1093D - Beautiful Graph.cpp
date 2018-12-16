/*
很好想但是很坑的一道题
说两个坑点
WA   2: 数据中图不一定连通
TLE 22: 因为T很大，当n很小的时候每次memset清空数组很花时间，改for循环即可
*/
#include <bits/stdc++.h>
using namespace std;
struct edge {
	int v;
	int next;
}e[600005];
int head[300005];
int ecnt;
void addedge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int cnt[2];
int vis[300005];//-1:未访问 0:以偶数方式访问 1:以奇数方式访问
bool exist;
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= 998244353;
		}
		a *= a;
		a %= 998244353;
		b >>= 1;
	}
	return ret;
}
void dfs(int u,bool odd) {
	vis[u] = odd;
	cnt[odd] ++;
	for (int i=head[u];i != -1 && exist;i=e[i].next) {
		int v = e[i].v;
		if (vis[v] == -1) dfs(v,!odd);
		else if (vis[v] != !odd) exist = false;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		ecnt = 0;
		exist = true;
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) head[i] = -1;
		for (int i=1;i<=n;i++) vis[i] = -1;
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		long long ans = 1;
		for (int i=1;i<=n && exist;i++) {
			if (vis[i] == -1) {
				memset(cnt,0,sizeof(cnt));
				dfs(i,0);
				ans *= qpow(2,cnt[0]) + qpow(2,cnt[1]);
				ans %= 998244353;
			}
		}
		if (!exist) printf("0\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
