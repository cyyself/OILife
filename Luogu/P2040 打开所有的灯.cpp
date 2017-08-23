#include <iostream>
#include <cstring>
using namespace std;
bool g[3][3];
bool vis[3][3];
int ans = 10;//先赋一个很大的数，当出现更少的步数时更新，至于为什么是10，可以参考优化过程。
bool check(){
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (!g[i][j]) return false;
    return true;
}
bool change(int x,int y){
    const int npx[] = {1,0,0,0,-1};
    const int npy[] = {0,1,0,-1,0};
    for (int i=0;i<5;i++){
        int px = x + npx[i];
        int py = y + npy[i];
        if (px < 0 || py < 0 || px >= 3 || py >= 3) continue;
        g[px][py] = !g[px][py];
    }
}
void DFS(int layer){
    if (layer >= ans) return;
    if (check()) ans = layer;
    else
    {
        for (int i=0;i<3;i++) for (int j=0;j<3;j++){
            if (!vis[i][j]){
                vis[i][j] = true;
                change(i,j);
                DFS(layer+1);
                vis[i][j] = false;
                change(i,j);//恢复到之前状态 
            }
        }
    }
}
int main(){
    memset(vis,0,sizeof(vis));
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) cin >> g[i][j];
    DFS(0);
    cout << ans << endl; 
    return 0;
}