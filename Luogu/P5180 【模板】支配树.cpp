#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector <int> g[3][N]; // 0: original graph, 1: reverse graph, 2: auxiliary graph

int dfn[N], dfnrev[N];
int up[N];
int fa[N], minn[N];
int sdom[N], idom[N];

void dfs(int u) {
    static int cnt = 0;
    dfn[u] = ++cnt;
    dfnrev[cnt] = u;
    for (int v : g[0][u]) {
        if (!dfn[v]) {
            up[v] = u;
            dfs(v);
        }
    }
}

int find(int x) {
    if (x == fa[x]) return x;
    int y = fa[x];
    fa[x] = find(fa[x]);
    if (dfn[sdom[minn[y]]] < dfn[sdom[minn[x]]]) {
        minn[x] = minn[y];
    }
    return fa[x];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int s = 1;
    for (int i = 1; i <= n; i++) {
        minn[i] = sdom[i] = idom[i] = fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }
    dfs(s);
    for (int i = n; i >= 2; i--) {
        int u = dfnrev[i];
        int sdomdfn = n;
        for (int v : g[1][u]) {
            if (!dfn[v]) continue;
            find(v);
            if (dfn[v] < dfn[u]) {
                sdomdfn = min(sdomdfn, dfn[v]);
            } else {
                sdomdfn = min(sdomdfn, dfn[sdom[minn[v]]]);
            }
        }
        sdom[u] = dfnrev[sdomdfn];
        fa[u] = up[u];
        g[2][sdom[u]].push_back(u);
        for (int v : g[2][up[u]]) {
            find(v);
            if (sdom[minn[v]] == up[u]) {
                idom[v] = up[u];
            } else {
                idom[v] = minn[v];
            }
        }
        g[2][up[u]].clear();
    }
    for (int i = 2; i <= n; i++) {
        int u = dfnrev[i];
        if (idom[u] != sdom[u]) {
            idom[u] = idom[idom[u]];
        }
    }
    vector <int> ans(n + 1);
    for (int i = n; i >= 2; i--) {
        int u = dfnrev[i];
        ans[u] ++;
        ans[idom[u]] += ans[u];
    }
    ans[s] = n;
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}