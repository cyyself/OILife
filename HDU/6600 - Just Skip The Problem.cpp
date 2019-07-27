#include <bits/stdc++.h>
using namespace std;
int jc[1000004];
int main() {
    jc[0] = 1;
    for (int i=1;i<=1000003;i++) jc[i] = (1LL * jc[i-1] * i) % 1000003LL;
    int n;
    while (scanf("%d",&n) == 1) {
        if (n > 1000003) printf("0\n");
        else printf("%d\n",jc[n]);
    }
    return 0;
}
