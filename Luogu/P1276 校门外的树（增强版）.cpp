#include <cstdio>
using namespace std;
int main(){
    int road[10001];//0:空 1:树 2:树苗
    int cnt = 0;//种上又被砍掉的树苗
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++) road[i] = 1;
    for (int i=0;i<m;i++){
        int status,from,to;
        scanf("%d%d%d",&status,&from,&to);
        for (int j=from;j<=to;j++){
            if (road[j] == 1) road[j] = status;//是树的地方要么保持是树，要么被砍掉，因此直接=status
            if (road[j] == 0 && status == 1) road[j] = 2;
            if (road[j] == 2 && status == 0){
                cnt ++;
                road[j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        if (road[i] == 2) ans ++;
    }
    printf("%d\n%d\n",ans,cnt);
    return 0;
}