#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const long long mo = 1e9+7;
int f[maxn];
long long cnt[maxn][2];
long long cntall[2];
int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        cntall[0] = 0;
        cntall[1] = 0;
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            cnt[i][0] = cnt[i][1] = 0;
            f[i] = i;
        }
        for (int i=1;i<=n;i++) {
            int tmp;
            scanf("%d",&tmp);
            cnt[i][tmp-1] ++;
            cntall[tmp-1] ++;
        }
        long long ans = 0;
        if (cntall[1] >= 3) {
            ans += (cntall[1] * (cntall[1] - 1) * (cntall[1] - 2) / 6) % mo;
            ans %= mo;
        }
        if (cntall[1] >= 2 && cntall[0] >= 1) {
            ans += (cntall[0] * cntall[1] * (cntall[1] - 1) / 2) % mo;
            ans %= mo;
        }
        printf("%lld\n",ans);
        for (int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            u = find(u);
            v = find(v);
            if (u == v) printf("%lld\n",ans);
            else {
                long long d = 0;
                long long other_0 = cntall[0] - cnt[u][0] - cnt[v][0];
                if (cnt[u][1] >= 1 && cnt[v][1] >= 1 && other_0 >= 1) {
                    d += cnt[u][1] * cnt[v][1] * other_0;
                    d %= mo;
                }
                long long other_1 = cntall[1] - cnt[u][1] - cnt[v][1];
                if (cnt[u][0] >= 1 && cnt[v][1] >= 1 && other_1 >= 1) {
                    d += cnt[u][0] * cnt[v][1] * other_1;
                    d %= mo;
                }
                if (cnt[u][1] >= 1 && cnt[v][0] >= 1 && other_1 >= 1) {
                    d += cnt[u][1] * cnt[v][0] * other_1;
                    d %= mo;
                }
                if (cnt[u][1] >= 1 && cnt[v][1] >= 1 && other_1 >= 1) {
                    d += cnt[u][1] * cnt[v][1] * other_1;
                    d %= mo;
                }
                ans = (ans - d + mo) % mo;
                f[u] = v;
                cnt[v][0] += cnt[u][0];
                cnt[v][1] += cnt[u][1];
                printf("%lld\n",ans);
            }
        }
    } 
    return 0;
}
