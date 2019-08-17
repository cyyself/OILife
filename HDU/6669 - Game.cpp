#include <bits/stdc++.h>
using namespace std;
pair <int,int> t[1005];
pair <int,int> p[1005];
int cnt;
int pos[1005][4];
int f[1005][4];
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        cnt = 0;
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&t[i].first,&t[i].second);
        int l=0,r=1000001;
        for (int i=1;i<=n;i++) {
            if (t[i].second < l || t[i].first > r) {
                p[cnt++] = {l,r};
                l = 0;
                r = 1000001;
                l = max(l,t[i].first);
                r = min(r,t[i].second);
            }
            else {
                l = max(l,t[i].first);
                r = min(r,t[i].second);
            }
        }
        p[cnt++] = {l,r};
        for (int i=0;i<cnt;i++) {
            pos[i][0] = pos[i][1] = p[i].first;
            pos[i][3] = pos[i][2] = p[i].second;
            if (p[i].second - p[i].first != 0) {
                pos[i][1] = pos[i][0] + 1;
                pos[i][2] = pos[i][3] - 1;
            }
        }
        f[0][0] = f[0][1] = f[0][2] = f[0][3] = 0;
        for (int i=1;i<cnt;i++) {
            for (int j=0;j<4;j++) {
                f[i][j] = 0x3f3f3f3f;
                for (int k=0;k<4;k++) f[i][j] = min(f[i][j],f[i-1][k]+(abs(pos[i][j]-pos[i-1][k])+1)/2);
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i=0;i<4;i++) ans = min(ans,f[cnt-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
