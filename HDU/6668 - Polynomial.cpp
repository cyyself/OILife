#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int gcd(int a,int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        int pos = n;
        while (a[pos] == 0 && b[pos] == 0) pos --;
        if (a[pos] == 0) {
            printf("0/1\n");
        }
        else if (b[pos] == 0) {
            printf("1/0\n");
        }
        else {
            int g = gcd(a[pos],b[pos]);
            printf("%d/%d\n",a[pos]/g,b[pos]/g);
        }
    }
    return 0;
}
