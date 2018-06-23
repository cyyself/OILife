#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long tmp = qpow(a,b/2);
    if (b % 2) return tmp * tmp * a;
    else return tmp * tmp;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        long long n;
        scanf("%lld",&n);
        printf("%lld",n);
        bool exist = false;
        if (n != 1) {
            for (int i=2;i<=63;i++) {
                double a = pow(n,(double)1.0/i) + 0.5;
                if (qpow(a,i) == n) {
                    if (!exist) {
                        exist = true;
                    }
                    printf("=%lld^%d",(long long)a,i);
                }
            }
        }
        if (!exist) printf(" is powerless.");
        printf("\n");
    }
    return 0;
}