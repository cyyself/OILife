#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const long long mo = 1e9+7;
char s[maxn][15];
int f[maxn];
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%s",s[i]);
        f[0] = 1;
        f[1] = 1;
        for (int i=2;i<=n;i++) f[i] = (1ll*f[i-1] + 1ll*(strcmp(s[i],s[i-1])!=0?f[i-2]:0)) % mo;
        printf("%d\n",f[n]);
    }
    return 0;
}
