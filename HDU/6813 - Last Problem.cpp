#include <bits/stdc++.h>
using namespace std;
map <pair<int,int>,int> mem;
void dfs(int x,int y,int n) {
    if (n <= 0) {
        if (mem[{x,y}] != 0) assert(false);
        return;
    }
    if (mem[{x,y}] == n) return;
    else {
        dfs(x+1,y,n-4);
        dfs(x,y+1,n-3);
        dfs(x,y-1,n-2);
        dfs(x-1,y,n-1);
        mem[{x,y}] = n;
        printf("%d %d %d\n",x,y,n);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    dfs(0,0,n);
    return 0;
}
