#include <iostream>
using namespace std;
int g[1005][1005];
int dist[1005];
bool flag[1005];//用于记录该节点是否被包括在这棵生成树中
int main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        int x,y,t;
        cin >> x >> y >> t;
        g[x][y] = t;
        g[y][x] = t;
        //邻接矩阵
    }
    for (int i=1;i<=n;i++) dist[i] = 0x7fffffff;
    flag[1] = true;
    int k = 1;
    int ans = 0;
    for (int i=1;i<n;i++) {
        for (int j=1;j<=n;j++)
            if (g[k][j] != 0 && !flag[j])
                if (g[k][j] < dist[j]) dist[j] = g[k][j];
        int t = 0x7fffffff;
        for (int j=1;j<=n;j++)
            if (dist[j] < t && !flag[j]) {
                t = dist[j];
                k = j;
            }
        flag[k] = true;
        if (t > ans) ans = t;
    }
    for (int i=1;i<=n;i++) {
        if (!flag[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}