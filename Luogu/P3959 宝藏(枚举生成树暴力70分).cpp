#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
    int v,w;
};
vector <edge> g[15];
int n,m;
int ans = INF;
bool vis[15];
void dfs(int u,int cost,int _dis[15],int _hop[15]) {
    int dis[15],hop[15];
    memcpy(dis,_dis,sizeof(dis));
    memcpy(hop,_hop,sizeof(hop));
    vis[u] = true;
    for(auto e:g[u]) {
        if (!vis[e.v] && dis[e.v] > (hop[u]+1) * e.w ) {
            dis[e.v] = (hop[u]+1) * e.w;
            hop[e.v] = hop[u] + 1;
        }
    }
    int v = -1;
    for (int i=1;i<=n;i++) {
        if (!vis[i] && dis[i] != INF) {
            v = i;
            dfs(v,cost+dis[i],dis,hop);
        }
    }
    if (v == -1) ans = min(ans,cost);
    vis[u] = false;
}
int main() {
    scanf("%d%d",&n,&m);
    while (m--) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back((edge){v,w});
        g[v].push_back((edge){u,w});
    }
    int dis[15],hop[15];
    memset(dis,0x3f,sizeof(dis));
    memset(hop,0,sizeof(hop));
    for (int i=1;i<=n;i++) {
        dfs(i,0,dis,hop);
    }
    printf("%d\n",ans);
    return 0;
}
