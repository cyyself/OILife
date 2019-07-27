#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
struct Car {
    long long l,s,v;
}a[100001];
long long suf[100001];
int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        for (int i=0;i<=n;i++) scanf("%lld",&a[i].l);
        for (int i=0;i<=n;i++) scanf("%lld",&a[i].s);
        for (int i=0;i<=n;i++) scanf("%lld",&a[i].v);
        reverse(a,a+n+1);
        suf[n] = 0;
        for (int i=n-1;i>=0;i--) suf[i] = suf[i+1] + a[i].l;
        double ans = 0;
        for (int i=0;i<=n;i++) ans = max(ans,(double)(a[i].s + suf[i])/a[i].v);
        printf("%0.7lf\n",ans);
    }
    return 0;
}
