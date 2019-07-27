#include <bits/stdc++.h>
using namespace std;

int s,t,n,m,k;
struct DATA {
	int u;
	int w;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.w > b.w;
	}
};
struct Edge {
	int v,w;
	int next;
}e[5000005];
int head[2000005];
int dis[2000005];
int ecnt;
//vector <pair<int,int> > g[2000005];
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void dijkstra(){
	priority_queue <DATA> q;
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	q.push({s,0});
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.w) continue;
		for (int i=head[u];i!=-1;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({v,dis[u]+w});
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&k);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int j=0;j<=k;j++){
			addedge(a+n*j,b+n*j,c);
			addedge(b+n*j,a+n*j,c);
			if(j<k){
				addedge(a+n*j,b+n*(j+1),0);
				addedge(b+n*j,a+n*(j+1),0);
			}
		}
	}
	dijkstra();
	int ans=0x3f3f3f3f;
	for(int i=0;i<=k;i++) ans=min(ans,dis[t+n*i]);
	printf("%d\n",ans);
	return 0;
}