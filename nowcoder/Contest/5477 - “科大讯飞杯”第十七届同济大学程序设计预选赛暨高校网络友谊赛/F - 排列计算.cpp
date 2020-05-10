#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
long long cnt[maxn];
long long d[maxn];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    while (m --) {
        int l,r;
        scanf("%d%d",&l,&r);
        d[l] ++;
        d[r+1] --;
    }
    for (int i=1;i<=n;i++) {
        cnt[i] = cnt[i-1] + d[i];
    }
    sort(cnt+1,cnt+1+n);
    long long ans = 0;
    for (int i=1;i<=n;i++) {
        ans += cnt[i] * i;
    }
    printf("%lld\n",ans);
    return 0;
}
