#include <bits/stdc++.h>
using namespace std;
struct edge {
    int a,b,c,d;
    int next;
}e[55];
int head[55];
int ecnt;
void addedge(int t,int a,int b,int c,int d) {
    e[ecnt].a = a;
    e[ecnt].b = b;
    e[ecnt].c = c;
    e[ecnt].d = d;
    e[ecnt].next = head[t];
    head[t] = ecnt;
    ecnt ++;
}
long long ans;
int prea[55],preb[55],prec[55],pred[55];
void dfs(int dep,long long a,long long b,long long c,long long d) {
    if (dep == 0) {
        ans = max(ans,a*b*c*d);
    }
    else {
        if (head[dep] == -1) dfs(dep-1,a,b,c,d);
        else {
            for (int i=head[dep];~i;i=e[i].next) {
                long long tmp = (a + e[i].a + prea[dep-1]) * (b + e[i].b + preb[dep-1]) * (c + e[i].c + prec[dep-1]) * (d + e[i].d + pred[dep-1]);
                if (tmp <= ans) continue;
                dfs(dep-1,a+e[i].a,b+e[i].b,c+e[i].c,d+e[i].d);
            }
        }
    }
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        ans = 0;
        memset(head,-1,sizeof(head));
        ecnt = 0;
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=0;i<=k;i++) {
            prea[i] = preb[i] = prec[i] = pred[i] = 0;
        }
        for (int i=0;i<n;i++) {
            int t,a,b,c,d;
            scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
            prea[t] = max(prea[t],a);
            preb[t] = max(preb[t],b);
            prec[t] = max(prec[t],c);
            pred[t] = max(pred[t],d);
            addedge(t,a,b,c,d);
        }
        for (int i=1;i<=k;i++) {
            prea[i] += prea[i-1];
            preb[i] += preb[i-1];
            prec[i] += prec[i-1];
            pred[i] += pred[i-1];
        }
        dfs(k,100,100,100,100);
        printf("%lld\n",ans);
    }
    return 0;
}
