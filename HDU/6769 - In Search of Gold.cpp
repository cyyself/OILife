#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
vector <pair <int,pair<int,int> > > g[maxn];
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long f[maxn][21];
long long tmp[21];
int sz[maxn];
int n,k;
void dfs(int u,int fa,long long mid) {
    for (int i=0;i<=k;i++) f[u][i] = inf;
    f[u][0] = 0;
    sz[u] = 1;
    for (auto x:g[u]) {
        int v = x.first;
        auto w = x.second;
        if (v == fa) continue;
        dfs(v,u,mid);
        for (int i=0;i<=min(k,sz[u]+sz[v]);i++) tmp[i] = inf;
        for (int i=0;i<=min(k,sz[u]);i++) {
            for (int j=0;j<=min(k,sz[v]) && i+j <= min(k,sz[u]+sz[v]);j++) {
                if (f[v][j] + f[u][i] + w.second <= mid) tmp[i+j] = min(tmp[i+j],max(f[u][i],f[v][j]+w.second));
                if (i+j+1<=k && f[v][j] + f[u][i] + w.first <= mid) tmp[i+j+1] = min(tmp[i+j+1],max(f[u][i],f[v][j]+w.first));
            }
        }
        sz[u] += sz[v];
        for (int i=0;i<=min(k,sz[u]);i++) f[u][i] = tmp[i];
    }
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<n;i++) {
            int u,v,a,b;
            scanf("%d%d%d%d",&u,&v,&a,&b);
            g[u].push_back(make_pair(v,make_pair(a,b)));
            g[v].push_back(make_pair(u,make_pair(a,b)));
        }
        int rt = 1;
        while (g[rt].size() == 1) rt ++;
        long long l = 1, r = 2e14;
        long long ans = -1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            dfs(rt,-1,mid);
            if (f[rt][k] <= mid) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
