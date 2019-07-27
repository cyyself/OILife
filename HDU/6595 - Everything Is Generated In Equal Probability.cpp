#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
long long qpow(long long a,long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1) {
            ret *= a;
            ret %= mo;
        }
        a *= a;
        a %= mo;
        b >>= 1;
    }
    return ret;
}
long long inv(long long x) {
    return qpow(x,mo-2);
}
int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        long long sum = 0;
        for (int i=1;i<=n;i++) {
            sum += 1LL * i * (i - 1LL);
        }
        sum *= inv(3*n);
        sum %= mo;
        printf("%lld\n",sum);
    }
    return 0;
}
