#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long f[1005][1005][2];
long long p[1005];
long long t[1005];
struct DATA {
    int l,r,s;
    DATA(int _l,int _r,int _s) {
        l = _l;
        r = _r;
        s = _s;
    }
};
queue <DATA> q;
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
    int m = 0;
    for (int i=1;i<=n;i++) {
        scanf("%lld",&t[i]);
        if (t[i] == 0) m = i;
    }
    assert(m != 0);
    memset(f,0x3f,sizeof(f));
    q.push((DATA){0,0,0});
    f[0][0][0] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int pos = cur.s?m+cur.r:m-cur.l;
        if (cur.l + 1 < m) {
            long long curt = f[cur.l][cur.r][cur.s] + p[pos] - p[m-(cur.l+1)];
            if (curt <= t[m-(cur.l+1)] && curt < f[cur.l+1][cur.r][0]) {
                if (f[cur.l+1][cur.r][0] == inf) q.push((DATA){cur.l+1,cur.r,0});
                f[cur.l+1][cur.r][0] = curt;
            }
        }
        if (m + cur.r + 1 <= n) {
            long long curt = f[cur.l][cur.r][cur.s] + p[m+(cur.r+1)] - p[pos];
            if (curt <= t[m+(cur.r+1)] && curt < f[cur.l][cur.r+1][1]) {
                if (f[cur.l][cur.r+1][1] == inf) q.push((DATA){cur.l,cur.r+1,1});
                f[cur.l][cur.r+1][1] = curt;
            }
        }
    }
    long long ans = min(f[m-1][n-m][0],f[m-1][n-m][1]);
    if (ans == inf) printf("-1\n");
    else printf("%lld\n",ans);
    return 0;
}
