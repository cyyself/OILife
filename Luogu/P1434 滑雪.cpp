#include <iostream>
using namespace std;
int r,c;
int a[100][100] = {0},b[100][100],z[4]={0,1,0,-1},d[4]={1,0,-1,0};
int snow(int x,int y){
    if(a[x][y] > 0) return a[x][y];
    int max=1;
    for(int i=0;i<4;i++){
        int e,f;
        e=x+z[i];
        f=y+d[i];
        if(e >= 0 && f >= 0 && e <= r-1 && f <= c-1 && b[x][y] > b[e][f]){
            int temp = snow(e,f) + 1;
            if(temp >max) max=temp;
        }
    }
    a[x][y]=max;
    return max;
}
int main(){
    int plus=0;
    cin>>r>>c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) cin>>b[i][j];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            int t = snow(i,j);
            if (t > plus) plus = t;
        }
    cout<<plus << endl;
    return 0;
}