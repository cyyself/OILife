#include <bits/stdc++.h>
using namespace std;
struct edge {
        int u,v;
        int next;
        bool link;
}e[8*8*2];
int ecnt;
int head[9];
void addedge(int u,int v) {
        e[ecnt].u = u;
        e[ecnt].v = v;
        e[ecnt].next = head[u];
        e[ecnt].link = false;
        head[u] = ecnt;
        ecnt ++;
}
void add(int u,int v) {
        addedge(u,v);
        addedge(v,u);
}
int ans;
int n,m;
void dfs(int u) {
        if (u <= 0) {
                ans ++;
                return;
        }
        else {
                int avail[8];
                int availcnt = 0;
                int cur = 0;
                int deg = 0;
                for (int i=head[u];i != -1;i=e[i].next) {
                        deg ++;
                        if (e[i].link) cur ++;
                        else if (e[i].v < u) avail[availcnt++] = i;
                }
                if (cur * 2 > deg) return;
                for (int i=0;i<(1<<availcnt);i++) {
                        if ( (__builtin_popcount(i) + cur) * 2 == deg) {
                                for (int j=0;j<availcnt;j++) {
                                        if (i & (1 << j)) {
                                                e[avail[j]  ].link = true;
                                                e[avail[j]^1].link = true;
                                        }
                                }
                                dfs(u-1);
                                for (int j=0;j<availcnt;j++) {
                                        if (i & (1 << j)) {
                                                e[avail[j]  ].link = false;
                                                e[avail[j]^1].link = false;
                                        }
                                }
                        }
                }
        }
}
int main() {
        int T;
        scanf("%d",&T);
        while (T --) {
                memset(head,-1,sizeof(head));
                ecnt = 0;
                ans = 0;
                scanf("%d%d",&n,&m);
                for (int i=0;i<m;i++) {
                        int u,v;
                        scanf("%d%d",&u,&v);
                        add(u,v);
                }
                dfs(n);
                printf("%d\n",ans);
        }
        return 0;
}
