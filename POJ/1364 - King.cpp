#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50005;
int head[maxn];
struct Edge {
	int v,w;
	int next;
}e[maxn*3];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n;
 
bool inq[maxn];
int dis[maxn];
int cnt[maxn];

bool spfa() {
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	dis[0] = 0;
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		for (register int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					if (cnt[v] >= n) {
						return false;
					}
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return true;
}
int arr[205];
struct _Edge {
	int u,v,w;
	_Edge() {}
	_Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w) {}
}_e[105];
int main() {
	while (scanf("%d",&n) == 1 && n) {
		int m;
		scanf("%d",&m);
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<m;i++) {
			int u,v;
			char s[5];
			int k;
			scanf("%d%d%s%d",&u,&v,s,&k);
			v = u + v;
			u --;
			arr[i*2] = u;
			arr[i*2+1] = v;
			if (s[0] == 'g') _e[i] = _Edge(u,v,-(k+1));
			else _e[i] = _Edge(v,u,k-1);
		}
		sort(arr,arr+m*2);
		int lscnt = unique(arr,arr+m*2) - arr;
		for (int i=0;i<m;i++) {
			int lsu = lower_bound(arr,arr+lscnt,_e[i].u) - arr + 1;
			int lsv = lower_bound(arr,arr+lscnt,_e[i].v) - arr + 1;
			addedge(lsu,lsv,_e[i].w);
		}
		for (int i=1;i<=lscnt;i++) addedge(0,i,0);
		if (spfa()) printf("lamentable kingdom\n");
		else printf("successful conspiracy\n");
	}
	return 0;
}
