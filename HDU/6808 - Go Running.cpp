#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
pair <bool,int> id[maxn*2];
int idcnt;

struct Edge{
    int f,v,next;
}e[maxn*10];
int ecnt;
int head[maxn*2];
void _AddEdge(int u,int v,int c) {
    e[ecnt].v = v;
    e[ecnt].f = c;
    e[ecnt].next = head[u];
    head[u] = ecnt;
    ecnt ++;
}
void AddEdge(int u,int v,int c) {
    _AddEdge(u,v,c);
    _AddEdge(v,u,0);
}
int dis[maxn*2];
bool bfs(int s,int t) {//划分层次，同时判断是否可到达
    for (int i=0;i<=idcnt+2;i++) dis[i] = INF;
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
pair <int,int> p[maxn];
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n;
        scanf("%d",&n);
        idcnt = 0;
        for (int i=0;i<n;i++) {
            scanf("%d%d",&p[i].first,&p[i].second);
            id[idcnt++] = make_pair(true,p[i].second - p[i].first);
            id[idcnt++] = make_pair(false,p[i].second + p[i].first);
        }
        sort(id,id+idcnt);
        idcnt = unique(id,id+idcnt) - id;
        ecnt = 0;
        for (int i=0;i<=idcnt+2;i++) head[i] = -1;
        for (int i=0;i<idcnt;i++) {
            if (id[i].first) AddEdge(idcnt,i,1);
            else AddEdge(i,idcnt+1,1);
        }
        for (int i=0;i<n;i++) {
            int u = lower_bound(id,id+idcnt,make_pair(true,p[i].second - p[i].first)) - id;
            int v = lower_bound(id,id+idcnt,make_pair(false,p[i].second + p[i].first)) - id;
            AddEdge(u,v,1);
        }
        printf("%d\n",dinic(idcnt,idcnt+1));
    }
    return 0;
}
