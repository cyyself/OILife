#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}
long long k,m;
long long f(long long x,long long y) {
    long long cnt = 0;
    long long cur = x + 1;
    while (cnt < y) {
        if (gcd(x,cur) == 1) cnt ++;
        cur ++;
    }
    return cur - 1;
}
map <pair<long long,long long>,long long> mem;
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld%lld",&k,&m);
        if (mem.find({k,m}) != mem.end()) printf("%lld\n",mem[{k,m}]);
        else {
            bool ans = false;
            for (long long n=max(k-3000,1LL);n<=k+3000;n++) {
                long long fs = (k ^ n) + n;
                if (fs < n + m) continue;
                long long fv = f(n,m);
                if (fs == fv) {
                    mem[{k,m}] = n;
                    ans = true;
                    break;
                }
            }
            if (!ans) mem[{k,m}] = -1;
            printf("%lld\n",mem[{k,m}]);
        }
    }
    return 0;
}
