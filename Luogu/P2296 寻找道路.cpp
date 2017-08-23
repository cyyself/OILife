#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define N 200001
using namespace std;
vector <int> map[N];
bool available[N];//第一次遍历获得的可用点
bool vis[N];//第二次遍历状态
struct searchparameter{
    int point;
    int weight;
};
searchparameter NewSearchParameter(int point, int weight){
    searchparameter temp;
    temp.point = point;
    temp.weight = weight;
    return temp;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        map[y].push_back(x);//反向存储地图
    }
    int s,t;
    scanf("%d %d",&s,&t);
    memset(available,false,sizeof(available));
    queue <searchparameter> q;
    q.push(NewSearchParameter(t,0));
    while(!q.empty()){//第一次遍历，找出无法到达的点
        searchparameter now = q.front();
        q.pop();
        available[now.point] = true;
        for (int i=0;i<map[now.point].size();i++){
            if (!available[map[now.point][i]]) q.push(NewSearchParameter(map[now.point][i],now.weight+1));
        }
    }
    bool avail[N];
    for (int i=1;i<=n;i++) avail[i] = available[i];
    for (int i=1;i<=n;i++){//排除点
        if (!avail[i]){
            for (int j=0;j<map[i].size();j++){
                available[map[i][j]] = false;
            }
        }
    }
    q.push(NewSearchParameter(t,0));
    memset(vis,false,sizeof(vis));
    vis[t] = true;
    while(!q.empty()){//第二次遍历，寻找最短路径
        searchparameter now = q.front();
        q.pop();
        if (!available[now.point]) continue;
        for (int i=0;i<map[now.point].size();i++){
            if (!vis[map[now.point][i]]){
                q.push(NewSearchParameter(map[now.point][i],now.weight+1));
                if (map[now.point][i] == s){
                    printf("%d\n",now.weight+1);
                    return 0;
                }
            }

        }
    }
    printf("-1\n");
    return 0;
}