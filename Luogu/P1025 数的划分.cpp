#include <bits/stdc++.h>
using namespace std;
int f[6][201][201];
int dfs(int dep,int rem,int pre) {
    if (dep == 0) return rem == 0;
    else {
        int &ans = f[dep-1][rem][pre];
        if (ans != -1) return ans;
        ans = 0;
        for (int i=min(rem-dep+1,pre);i>=1;i--) {
            ans += dfs(dep-1,rem-i,i);
        }
        return ans;
    }
}
int main() {
    memset(f,-1,sizeof(f));
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",dfs(k,n,n));
    return 0;
}
