#include <bits/stdc++.h>
using namespace std;
int lb[1000000][30],pos[1000000][30];
void lb_push(int x,int p) {
    for (int i=0;i<30;i++) {
        lb[p][i] = lb[p-1][i];
        pos[p][i] = pos[p-1][i];
    }
    int cur = p;
    for (int i=29;i>=0;i--) if ((x >> i) & 1) {
        if (!lb[p][i]) {
            lb[p][i] = x;
            pos[p][i] = cur;
            break;
        }
        else {
            if (cur > pos[p][i]) {
                swap(cur,pos[p][i]);
                swap(x,lb[p][i]);
            }
            x ^= lb[p][i];
        }
    }
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            lb_push(x,i);
        }
        int lastans = 0;
        while (m --) {
            int op;
            scanf("%d",&op);
            if (op) {
                int x;
                scanf("%d",&x);
                x ^= lastans;
                lb_push(x,++n);
            }
            else {
                int l,r;
                scanf("%d%d",&l,&r);
                l = (l ^ lastans) % n + 1;
                r = (r ^ lastans) % n + 1;
                if (l > r) swap(l,r);
                lastans = 0;
                for (int i=29;i>=0;i--) if (pos[r][i] >= l) lastans = max(lastans,lastans^lb[r][i]);
                printf("%d\n",lastans);
            }
        }
    }
    return 0;
}
