#include <iostream>
#include <cstdio>
using namespace std;
struct Point{
    int x,y;
};
int map[40][40] = {0};
int n = 0;
Point search(int num){
    Point p;
    p.x = -1;
    p.y = -1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (map [i][j] == num){
                p.x = i;
                p.y = j;
                return p;
            }
        }
    }
    return p;
}
int main(){
    cin >> n;
    map [0][n/2] = 1;
    for (int i=2;i<=(n*n);i++){
        Point last = search(i-1);
        if (last.x == 0 && last.y != n-1) map[n-1][last.y+1] = i;
        if (last.y == n-1 && last.x != 0) map[last.x-1][0] = i;
        if (last.x == 0 && last.y == n-1) map[last.x+1][last.y] = i;
        if (last.x != 0 && last.y != n-1){
            if (map[last.x-1][last.y+1] == 0){
                map[last.x-1][last.y+1] = i;
            }
            else{
                map[last.x+1][last.y] = i;
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << map [i][0];
        for (int j=1;j<n;j++) cout <<  " " <<map [i][j];
        cout << endl;
    }
    return 0;
}