#include <cstdio>
#include <cstring>
int g[105][105];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&g[i][j]);
    int dis[105];
    memset(dis,0x7f,sizeof(dis));
    bool flag[105] = {0};
    int ans = 0;
    int k = 0;
    flag[k] = true;
    while(k != -1) {
        for (int i=0;i<n;i++) if (g[k][i] < dis[i]) dis[i] = g[k][i];
        k = -1;
        int l = 0x7f7f7f7f;
        for (int i=0;i<n;i++) if (!flag[i] && dis[i] < l) {
            l = dis[i];
            k = i;    
        }
        if (k != -1) {
            ans += l;
            flag[k] = true;
        }
    }
    printf("%d\n",ans);
    return 0;
}
