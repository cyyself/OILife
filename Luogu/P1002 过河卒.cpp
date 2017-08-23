#include <iostream>
#include <math.h>
using namespace std;
struct Point {
    int x;
    int y;
};
int main(int argc, const char * argv[]) {
    Point M,B;
    cin >> B.x;
    cin >> B.y;
    cin >> M.x;
    cin >> M.y;
    long long map[30][30] = {0};//路径数地图
    bool mmap [30][30] = {0};//马地图
    map[0][0] = 1;
    //填充马点{
    mmap[M.x][M.y] = 1;
    for (int x=-2;x<=2;x++){
        for (int y=-2;y<=2;y++){
            if (x != 0 && y != 0 && abs(x) != abs(y) && M.x+x >= 0 && M.y+y >= 0){
                mmap[M.x+x][M.y+y] = 1;
            }
        }
    }
    //}
    for (int x=0;x<=B.x;x++){
        for (int y=0;y<=B.y;y++){
            if(mmap[x][y] == 0 && (x+y) > 0){//跳过(0,0)点和马点，因为马点无法到达，因此不必计算路径数，即为默认值0。
                map[x][y] = map[x-1][y] + map[x][y-1];
            }
        }
    }
    cout << map[B.x][B.y];
    return 0;
}