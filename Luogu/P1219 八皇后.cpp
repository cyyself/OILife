#include <iostream>
#include <cstring>
using namespace std;
int answer = 0;//答案数量
int n;
void search(int from,int map[13]){//深搜
    bool available[13];//该行棋盘可填棋子的格子
    memset(available,true,sizeof(available));  
    for (int i=0;i<from;i++){//找出这一行中不可填的棋子
        int value = map[i];//记录当前扫描的这一行放棋子的位置
        //由规则可知，每条纵、横、斜向至多有一个棋子
        available[value] = false;//纵向
        //下面是斜向
        int x = value - (from - i);
        int y = value + (from - i);
        if (x >= 0) available[x] = false;
        if (y <= n-1) available[y] = false;
    }
    if (from == n-1){//如果是最后一行，就要找出所有可行放棋子位置并输出答案了。
        for (int i=0;i<n;i++){
            if (available[i]){
                answer++;
                if (answer <= 3){
                    //输出答案
                    map[n-1] = i;
                    cout << map[0]+1;
                    for (int i=1;i<n;i++) cout << " " << map[i]+1;
                    cout << endl;
                }
            }
        }
    }
    else{
        for (int i=0;i<n;i++){//列举所有之后可放棋子的情况
            if (available[i]){
                map[from] = i;
                search(from+1,map);//继续放下一行棋子
            }
        }
    }
}
int main(){
    cin >> n;
    int map[13];
    memset(map,0,sizeof(map));
    search(0,map);
    cout << answer << endl;
    return 0;
}