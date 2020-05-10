#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        if (n == 2) {
            printf("No\n");
        }
        else if (n == 3) {
            printf("Yes\n");
        }
        else {
            int x = __gcd(a,b);
            if ((n / x) & 1) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
