#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        long long n;
        scanf("%lld",&n);
        if (n > 3) printf("15600\n");
        else if (n == 1) printf("26\n");
        else if (n == 2) printf("676\n");
        else if (n == 3) printf("17576\n");
    }
    return 0;
}
