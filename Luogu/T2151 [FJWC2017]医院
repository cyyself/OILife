#include <cstdio>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cstring>
using namespace std;
int n,k;
vector <int> g1[1005];//向上连接
vector <int> g2[1005];//向下连接
vector <int> P[1005];//P[i]存储可以用普通护士取代的专科护士
bitset <1005> H[1005];//H[i]表示编号为H的护士必须要的护士
struct Rela {//Relationship，表示两位护士相互依存的关系
    int u,v;
};
vector <Rela> ans;
void SearchP(int s) {
    //寻找可以用普通护士取代的专科护士，因为题目已经给出
    queue <int> q;
    bool vis[1005];
    memset(vis,false,sizeof(vis));
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {//以这个护士离开后向上DFS
        int curr = q.front();
        q.pop();
        if (curr > k) P[s].push_back(curr);//找到了一个可以替代他的普通护士
        for (unsigned int i=0;i<g1[curr].size();i++) {
            int v = g1[curr][i];
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}
void Searchleave(int l) {//搜索哪些护士在这位护士离开后无法被替代
    //l->leave->离开的护士
    queue <int> q;
    bool vis[1005];
    memset(vis,false,sizeof(vis));
    for (int i=k+1;i<=n;i++) {
        if (i != l) {
            q.push(i);//由于没有根节点，因此首先把每个护士都加入队列中广搜
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (unsigned int i=0;i<g2[curr].size();i++) {
            int v = g2[curr][i];
            if (v == l) continue;//同样，广搜时遇到这个护士也要排除
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    //找出没被遍历到的护士名单，用bitset存储
    for (int i=1;i<=n;i++) if (!vis[i]) H[i].set(l);
}
int main() {
    //freopen("hospital.in","r",stdin);
    //freopen("hospital.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;i++) {
        int d;
        scanf("%d",&d);
        for (int j=0;j<d;j++) {
            int v;
            scanf("%d",&v);
            g1[i].push_back(v);
            g2[v].push_back(i);
            //有向图，正反都存一次
        }
    }
    for (int i=1;i<=k;i++) SearchP(i);//只需寻找专科护士即可
    for (int i=1;i<=n;i++) Searchleave(i);
    int tot = 0;
    for (int i=1;i<=k;i++) if (P[i].size() == 0) tot ++;
    //输出不能请假的护士数量和他们的人数
    printf("%d\n",tot);
    for (int i=1;i<=k;i++) if (P[i].size() == 0) printf("%d\n",i);
    for (int i=1;i<=n;i++) {//注意遍历的字典序
        if (i <= k && P[i].size() == 0) continue;
        for (int j=i+1;j<=n;j++) {
            if (j <= k && P[j].size() == 0) continue;
            bitset <1005> t = H[i] & H[j];
            //一个普通护士只能去取代一个专科护士的位置，有交集时无法找到普通护士取代他们的位置
            if (t.any()) ans.push_back((Rela){i,j});
        }
    }
    printf("%lu\n",ans.size());
    if (ans.size() <= 10000) for (unsigned int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].u,ans[i].v);
    return 0;
}
