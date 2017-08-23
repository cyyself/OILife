#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
int head[405];
int ecnt;
struct edge {
	int u,v;
	int f,c;
	int next;
} e[1605];
void addedge(int u,int v,int f,int c) {
	e[ecnt].next = head[u];
	head[u] = ecnt;
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].f = f;
	e[ecnt].c = c;
	ecnt ++;
}
void add(int u,int v,int f,int c) {
	addedge(u,v,f,c);
	addedge(v,u,0,-c);
}
int s,t;
int dis[405];
bool inq[405];
int pre[405];
bool spfa() {
	memset(dis,0x7f,sizeof(dis));
	memset(inq,false,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i=head[cur];i != -1;i = e[i].next) {
			int v = e[i].v;
			if (e[i].f > 0 && dis[cur] + e[i].c < dis[v]) {
				dis[v] = dis[cur] + e[i].c;
				pre[v] = i;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return dis[t] != INF;
}
void micmaf(int &flow,int &cost) {
	flow = 0;
	cost = 0;
	while (spfa()) {
		int minF = INF;
		for (int i=pre[t];i != -1;i = pre[e[i].u]) minF = min(e[i].f,minF);
		flow += minF;
		for (int i=pre[t];i != -1;i = pre[e[i].u]) {
			e[i].f -= minF;
			e[i^1].f += minF;
		}
		cost += dis[t] * minF;
	}
}
struct interval{
	int a,b,w;
} inter[205];
int arr[405];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		int n,k;
		int lscnt = 0;
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) {
			scanf("%d%d%d",&inter[i].a,&inter[i].b,&inter[i].w);
			arr[++lscnt] = inter[i].a;
			arr[++lscnt] = inter[i].b;
		}
		sort(arr+1,arr+lscnt+1);
		int j=1;
		for (int i=2;i<=lscnt;i++) if (arr[j] != arr[i]) arr[++j] = arr[i];
		lscnt = j + 1;
		add(0,1,k,0);
		for (int i=1;i<=lscnt;i++) add(i,i+1,k,0);
		for (int i=0;i<n;i++) 
			add(
			lower_bound(arr+1,arr+lscnt,inter[i].a)-arr,
			lower_bound(arr+1,arr+lscnt,inter[i].b)-arr,
			1,
			-inter[i].w);
		s = 0;
		t = lscnt - 1;
		int f,c;
		micmaf(f,c);
		printf("%d\n",-c);
	}
	return 0;
}
