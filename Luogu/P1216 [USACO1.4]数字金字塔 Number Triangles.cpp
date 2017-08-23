#include <iostream>
#include <cstdio>
using namespace std;
int map[1001][1001] = {{0}};
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for (int i=n-2;i>=0;i--){
        for (int j=0;j<=i;j++){
            map[i][j] += max(map[i+1][j],map[i+1][j+1]);
        }
    }
    cout << map[0][0];
}