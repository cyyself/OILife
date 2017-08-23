#include <iostream>
#include <cstring>
using namespace std;
#define INF 0x7f7f7f7f
int g[5005][5005];
int dis[5005];
bool flag[5005];//用于记录该节点是否被包括在这棵生成树中
int main() {
	memset(g,0x7f,sizeof(g));
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        if (g[x][y] > z){//重边检查
        	g[x][y] = z;
        	g[y][x] = z;
        	//邻接矩阵
        }
    }
    memset(dis,0x7f,sizeof(dis));
    flag[1] = true;
    int k = 1;
    int ans = 0;
    for (int i=1;i<n;i++) {
        for (int j=1;j<=n;j++)
            if (g[k][j] != INF && !flag[j])
                if (g[k][j] < dis[j]) dis[j] = g[k][j];
        int t = INF;
        for (int j=1;j<=n;j++)
            if (dis[j] < t && !flag[j]) {
                t = dis[j];
                k = j;
            }
        flag[k] = true;
        ans += t;
    }
    for (int i=1;i<=n;i++) {
        if (!flag[i]) {
            cout << "orz" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}