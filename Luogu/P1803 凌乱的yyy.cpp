#include <cstdio>
#include <algorithm>
using namespace std;
struct comp{
    int start;
    int end;
}c[1000001];
bool com(comp x,comp y){
    if (x.end < y.end) return true;
    if (x.end == y.end && x.start < y.start) return true;
    return false;
}
int n;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&c[i].start,&c[i].end);
    sort(c,c+n,com);
    int ans = 0;
    int rtime = 0;
    for (int i=0;i<n;i++){
        if (rtime <= c[i].start){
            rtime = c[i].end;
            ans ++;
        }
    }
    printf("%d\n",ans);
    return 0;
}