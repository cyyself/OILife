#include <bits/stdc++.h>
using namespace std;
const double inf = 1e18;
int lsx[405],lsy[405],xcnt,ycnt;
struct DATA {
    int x1,y1,x2,y2;
}r[205];
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,1,-1,0};
int cnt[405][405][4];//表示每个点附近4条边被覆盖的次数，顺序：下、右、左、上
struct Edge {
    int v;
    double w;
};
vector <Edge> g[200000];
inline int id(int x,int y) {
    return x * ycnt + y;
}
struct qdata {
    int u;
    double w;
    friend bool operator < (const qdata &a,const qdata &b) {
        return a.w > b.w;
    }
};
double ans[200000];
void dijkstra(int s) {
    ans[s] = 0;
    priority_queue <qdata> q;
    q.push({s,0});
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int u = cur.u;
        if (cur.w > ans[u]) continue;
        for (auto x:g[u]) {
            int v = x.v;
            double w = x.w;
            if (ans[u] + w < ans[v]) {
                ans[v] = ans[u] + w;
                q.push({v,ans[v]});
            }
        }
    }
}
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        xcnt = 0;
        ycnt = 0;
        for (int i=0;i<n;i++) {
            scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
            lsx[xcnt++] = r[i].x1;
            lsx[xcnt++] = r[i].x2;
            lsy[ycnt++] = r[i].y1;
            lsy[ycnt++] = r[i].y2;
        }
        int xa,xb,ya,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        lsx[xcnt++] = xa;
        lsx[xcnt++] = xb;
        lsy[ycnt++] = ya;
        lsy[ycnt++] = yb;
        sort(lsx,lsx+xcnt);
        sort(lsy,lsy+ycnt);
        xcnt = unique(lsx,lsx+xcnt) - lsx;
        ycnt = unique(lsy,lsy+ycnt) - lsy;
        xa = lower_bound(lsx,lsx+xcnt,xa) - lsx;
        xb = lower_bound(lsx,lsx+xcnt,xb) - lsx;
        ya = lower_bound(lsy,lsy+ycnt,ya) - lsy;
        yb = lower_bound(lsy,lsy+ycnt,yb) - lsy;
        for (int i=0;i<n;i++) {
            //离散化替换
            r[i].x1 = lower_bound(lsx,lsx+xcnt,r[i].x1) - lsx;
            r[i].x2 = lower_bound(lsx,lsx+xcnt,r[i].x2) - lsx;
            r[i].y1 = lower_bound(lsy,lsy+ycnt,r[i].y1) - lsy;
            r[i].y2 = lower_bound(lsy,lsy+ycnt,r[i].y2) - lsy;
            //左边上下
            for (int x=r[i].x1;x<r[i].x2;x++) cnt[x][r[i].y1][0] ++;
            for (int x=r[i].x1+1;x<=r[i].x2;x++) cnt[x][r[i].y1][3] ++;
            for (int x=r[i].x1+1;x<r[i].x2;x++) cnt[x][r[i].y1][1] ++;//向右
            //右边上下
            for (int x=r[i].x1;x<r[i].x2;x++) cnt[x][r[i].y2][0] ++;
            for (int x=r[i].x1+1;x<=r[i].x2;x++) cnt[x][r[i].y2][3] ++;
            for (int x=r[i].x1+1;x<r[i].x2;x++) cnt[x][r[i].y2][2] ++;//向左
            //上边左右
            for (int y=r[i].y1;y<r[i].y2;y++) cnt[r[i].x1][y][1] ++;
            for (int y=r[i].y1+1;y<=r[i].y2;y++) cnt[r[i].x1][y][2] ++;
            for (int y=r[i].y1+1;y<r[i].y2;y++) cnt[r[i].x1][y][0] ++;//向下
            //下边左右
            for (int y=r[i].y1;y<r[i].y2;y++) cnt[r[i].x2][y][1] ++;
            for (int y=r[i].y1+1;y<=r[i].y2;y++) cnt[r[i].x2][y][2] ++;
            for (int y=r[i].y1+1;y<r[i].y2;y++) cnt[r[i].x2][y][3] ++;//向上
            //中间部分
            for (int x=r[i].x1+1;x<r[i].x2;x++) 
                for (int y=r[i].y1+1;y<r[i].y2;y++) 
                    for (int k=0;k<4;k++) cnt[x][y][k] ++;
        }
        //然后根据cnt建图
        for (int x=0;x<xcnt;x++) for (int y=0;y<ycnt;y++) {
            int u = id(x,y);
            g[u].clear();
            ans[u] = inf;
            for (int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= xcnt || ny >= ycnt) continue;
                int v = id(nx,ny);
                double dis = abs(lsx[x] - lsx[nx]) + abs(lsy[y] - lsy[ny]);
                g[u].push_back({v,dis/(cnt[x][y][k]+1)});
            }
        }
        dijkstra(id(xa,ya));
        printf("%0.5lf\n",ans[id(xb,yb)]);
    }
    return 0;
}
