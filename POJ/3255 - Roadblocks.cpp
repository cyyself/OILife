#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
	int u,v;
	long long w;
	int next;
}e[200005];
int head[5005];
int ecnt;
void addedge(int u,int v,long long w) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n,r;
long long dis_s[5005];
bool inq[5005];
void spfa_s() {
	queue <int> q;
	memset(dis_s,0x3f,sizeof(dis_s));
	memset(inq,false,sizeof(inq));
	dis_s[1] = 0;
	inq[1] = true;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			if (dis_s[u] + e[i].w < dis_s[v]) {
				dis_s[v] = dis_s[u] + e[i].w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
long long dis_t[5005];
void spfa_t() {
	queue <int> q;
	memset(dis_t,0x3f,sizeof(dis_t));
	memset(inq,false,sizeof(inq));
	dis_t[n] = 0;
	inq[n] = true;
	q.push(n);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			if (dis_t[u] + e[i].w < dis_t[v]) {
				dis_t[v] = dis_t[u] + e[i].w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&r);
	memset(head,-1,sizeof(head));
	ecnt = 0;
	while (r--) {
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	spfa_s();
	spfa_t();
	long long shortest = dis_s[n];
	long long ans = INF;
	for (int i=0;i<ecnt;i++) {
		if (dis_s[e[i].u]+e[i].w+dis_t[e[i].v] > shortest) ans = min(ans,dis_s[e[i].u]+e[i].w+dis_t[e[i].v]);
	}
	printf("%lld\n",ans);
	return 0;
}
