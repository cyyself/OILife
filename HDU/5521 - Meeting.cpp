#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge {
	int v;
	long long w;
};
vector <edge> g[200005];
bool inq[200005];
long long dis_s[200005];
void spfa_s(int s) {
	memset(inq,false,sizeof(inq));
	memset(dis_s,0x3f,sizeof(dis_s));
	queue <int> q;
	q.push(s);
	inq[s] = true;
	dis_s[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=0;i<g[u].size();i++) {
			edge e = g[u][i];
			if (dis_s[u] + e.w < dis_s[e.v]) {
				dis_s[e.v] = dis_s[u] + e.w;
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}
		}
	}
}
long long dis_t[200005];
void spfa_t(int s) {
	memset(inq,false,sizeof(inq));
	memset(dis_t,0x3f,sizeof(dis_t));
	queue <int> q;
	q.push(s);
	inq[s] = true;
	dis_t[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=0;i<g[u].size();i++) {
			edge e = g[u][i];
			if (dis_t[u] + e.w < dis_t[e.v]) {
				dis_t[e.v] = dis_t[u] + e.w;
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n+m;i++) g[i].clear();
		for (int i=1;i<=m;i++) {
			long long t;
			int s;
			scanf("%lld%d",&t,&s);
			while (s--) {
				int Ei;
				scanf("%d",&Ei);
				g[n+i].push_back((edge){Ei,t});
				g[Ei].push_back((edge){n+i,t});
			}
		}
		spfa_s(1);
		spfa_t(n);
		long long ans = INF;
		for (int i=1;i<=n;i++) {
			long long cur = max(dis_s[i],dis_t[i]);
			ans = min(cur,ans);
		}
		if (ans >= INF) printf("Case #%d: Evil John\n",c);
		else {
			printf("Case #%d: %lld\n",c,ans>>1);
			vector <int> ans_pos;
			ans_pos.clear();
			for (int i=1;i<=n;i++) {
				if (max(dis_s[i],dis_t[i]) == ans) ans_pos.push_back(i);
			}
			for (int i=0;i<ans_pos.size();i++) {
				if (i != 0) printf(" ");
				printf("%d",ans_pos[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
