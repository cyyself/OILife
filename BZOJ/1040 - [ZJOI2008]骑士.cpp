#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct Edge {
        int v,next;
}e[MAXN<<1];
int head[MAXN];
int ecnt;
void add(int u,int v) {
        e[ecnt].v = v;
        e[ecnt].next = head[u];
        head[u] = ecnt;
        ecnt ++;
}
int w[MAXN];
bool vis[MAXN];
int cur_u,cur_v,cur_e;
void dfs(int u,int rt) {
        vis[u] = true;
        for (int i=head[u];~i;i=e[i].next) {
                if ((i ^ 1) == rt) continue;//don't go to reverse edge
                int v = e[i].v;
                if (vis[v]) {
                        cur_u = u;
                        cur_e = i;
                        cur_v = v;
                        continue;
                }
                dfs(v,i);
        }
}
long long f[MAXN][2];//1:selectd
void dp(int u,int rt) {
        f[u][0] = 0;//clear
        f[u][1] = w[u];
        for (int i=head[u];~i;i=e[i].next) {
                if ((i ^ 1) == rt || i == cur_e || (i ^ 1) == cur_e) continue;
                int v = e[i].v;
                dp(v,i);
                f[u][0] += max(f[v][0],f[v][1]);
                f[u][1] += f[v][0];
        }
}
int main() {
        memset(head,-1,sizeof(head));
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
                int v;
                scanf("%d%d",&w[i],&v);
                add(i,v);
                add(v,i);
        }
        long long ans = 0;
        for (int i=1;i<=n;i++) {
                if (!vis[i]) {
                        dfs(i,-1);
                        dp(cur_u,-1);
                        long long cur_ans = f[cur_u][0];
                        dp(cur_v,-1);
                        cur_ans = max(cur_ans,f[cur_v][0]);
                        ans += cur_ans;
                }
        }
        printf("%lld\n",ans);
        return 0;
}
