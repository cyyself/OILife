#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
    int u;
    int v;
    int f;
    long long c;
    int next;
}e[100005];
int head[6005];
int pre[6005];
int ecnt;
inline void addedge(int _u,int _v,int _f,long long _c) {
    e[ecnt].next = head[_u];
    head[_u] = ecnt;
    e[ecnt].u = _u;
    e[ecnt].v = _v;
    e[ecnt].f = _f;
    e[ecnt].c = _c;
    ecnt++;
}
inline void add(int _u,int _v,int _f,long long _c) {
    addedge(_u,_v,_f,_c);
    addedge(_v,_u,0,-_c);
}
long long dis[6005];
bool inq[6005];
bool SPFA(int s,int t) {
    queue <int> q;
    q.push(s);
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    memset(pre,-1,sizeof(pre));
    inq[s] = true;
    dis[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inq[cur] = false;
        for (int i = head[cur];i != -1;i = e[i].next) {
            if (e[i].f > 0 && dis[e[i].v] > dis[cur] + e[i].c) {
                dis[e[i].v] = dis[cur] + e[i].c;
                pre[e[i].v] = i;
                if (!inq[e[i].v]) {
                    inq[e[i].v] = true;
                    q.push(e[i].v);
                }
            }
        }
    }
    return dis[t] != INF;
}
void MICMAF(int s,int t,int &flow,long long &cost) {
    flow = 0;
    cost = 0;
    SPFA(s,t);
    int minF = 1;
    for (int i=pre[t];i != -1;i=pre[e[i].u]) minF = min(minF,e[i].f);
    flow += minF;
    for (int i=pre[t];i != -1;i=pre[e[i].u]) {
        e[i].f -= minF;
        e[i^1].f += minF;
    }
    cost += dis[t] * minF;
}
map <long long,int> mem;
int lscnt;
int lsv(long long x) {
    if (mem[x] == 0) return mem[x] = lscnt++;
    else return mem[x];
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        memset(head,-1,sizeof(head));
        ecnt = 0;
        mem.clear();
        lscnt = 100;
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            long long a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            if (m <= 110) {
                for (long long j=1;j<=m;j++) add(i,lsv(j),1,a*j*j+b*j+c);
            }
            else {
                long long mid = -b / (2 * a);
                if (mid < 51) mid = 51;
                if (mid > m - 50) mid = m - 50;
                for (long long j=mid-50;j<=mid+50;j++) {
                    add(i,lsv(j),1,a*j*j+b*j+c);
                }
            }
        }
        for (int i=1;i<=n;i++) add(51,i,1,0);
        for (auto x:mem) add(x.second,52,1,0);
        long long ans = 0;
        for (int i=1;i<=n;i++) {
            int f;
            long long c;
            MICMAF(51,52,f,c);
            ans += c;
            printf("%lld%c",ans,i==n?'\n':' ');
        }
    }
    return 0;
}
