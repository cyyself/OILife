#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
struct Pos{
    int x;
    int y;
};
Pos NewPos(int x,int y){
    Pos temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int dfs(Pos From, Pos To, bool available[6][6]){
    if (From.x == To.x && From.y == To.y){
        return 1;
    }
    int ans=0;
    available[From.x][From.y] = false;
    const int dx[4] = {1,0,0,-1};
    const int dy[4] = {0,1,-1,0};
    for (int i=0;i<4;i++){
        int x,y;
        x = From.x + dx[i];
        y = From.y + dy[i];
        if ( 1 <= x && x <= n && 1 <= y && y <= m){//是否越界
            if (available[x][y]){
                ans += dfs(NewPos(x,y),To,available);
                available[x][y] = true;
            }
        }
    }
    return ans;
}
int main(){
    int T;
    cin >> n >> m >> T;
    bool available[6][6];
    memset(available,true,sizeof(available));
    int startx,starty,endx,endy;
    cin >> startx >> starty >> endx    >> endy;
    for (int i=1;i<=T;i++){
        int x,y;
        cin >> x >> y;
        available[x][y] = false;
    }
    if (!available[endx][endy]){
        cout << 0 << endl;
        return 0;
    }
    cout << dfs(NewPos(startx,starty),NewPos(endx,endy),available) << endl;
    return 0;
}