#include <bits/stdc++.h>
using namespace std;
int n,m;
const int INF = 0x3f3f3f3f;
vector <pair<int,int> > _g[2][10005];
long long d[2][10005];
struct DATA {
    int u,v,f,next;
}e[20005];
int head[10005];
int ecnt;
void _addedge(int u,int v,int cap) {
    e[ecnt].u = u;
    e[ecnt].v = v;
    e[ecnt].f = cap;
    e[ecnt].next = head[u];
    head[u] = ecnt;
    ecnt ++;
}
void addedge(int u,int v,int cap) {
    _addedge(u,v,cap);
    _addedge(v,u,0);
}
void dijkstra(int s,int g,long long *dis) {
    priority_queue <pair<long long,int> > q;
    memset(dis,0x3f,sizeof(long long) * (n + 1));
    q.push({0,s});
    dis[s] = 0;
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int u = cur.second;
        if (dis[u] < cur.first) continue;
        for (auto x:_g[g][u]) {
            int v = x.first;
            int w = x.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
}
int dis[10005];
bool bfs(int s,int t) {//划分层次，同时判断是否可到达
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
            if (e[i].f != 0 && dis[v] == INF) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[t] != INF;
}

int dfs(int u,int t,int curflow) {//curflow=>当前可增广的最大流量
    if (curflow == 0 || u == t) return curflow;
    if (dis[u] >= dis[t]) return 0;
    int ret = 0;
    for (int i=head[u];i!=-1 && ret < curflow;i=e[i].next) {
        int v = e[i].v;
        int f = e[i].f;
        if (dis[v] == dis[u] + 1 && f != 0) {
            int pushflow = min(curflow-ret,f);
            int chflow = dfs(v,t,pushflow);
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
int dinic(int s,int t) {
    int ans = 0;
    while(bfs(s,t)) ans += dfs(s,t,INF);
    return ans;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            _g[0][i].clear();
            _g[1][i].clear();
            head[i] = -1;
        }
        for (int i=1;i<=m;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            _g[0][u].push_back({v,c});
            _g[1][v].push_back({u,c});
        }
        dijkstra(1,0,d[0]);
        if (d[0][n] == 0x3f3f3f3f3f3f3f3f) {
            printf("0\n");
            continue;
        }
        dijkstra(n,1,d[1]);
        ecnt = 0;
        for (int u=1;u<=n;u++) {
            for (auto x:_g[0][u]) {
                int v = x.first;
                int w = x.second;
                if (d[0][u] + w + d[1][v] != d[0][n]) continue;
                addedge(u,v,w);
            }
        }
        printf("%d\n",dinic(1,n));
    }
    return 0;
}
