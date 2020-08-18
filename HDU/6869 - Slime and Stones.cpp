#include <bits/stdc++.h>
using namespace std;
long long d;
double getx(double k) {
    return k * (2.0 - d + sqrt((double)d * d + 4.0)) / 2.0;
}
double gety(double k) {
    return k * (2.0 + d + sqrt((double)d * d + 4.0)) / 2.0;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        long long x,y;
        scanf("%lld%lld%lld",&x,&y,&d);
        d ++;
        if (x > y) swap(x,y);
        int l = 0, r = 1e9;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            double res = gety(mid);
            if (floor(res) == y) {
                ans = mid;
                break;
            }
            if (res > y) r = mid - 1;
            else l = mid + 1;
        }
        if (ans == -1) printf("1\n");
        else {
            if (floor(getx(ans)) == x) printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}
