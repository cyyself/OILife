#include <bits/stdc++.h>
using namespace std;
char g[2005][2005];
bool vis[2005][2005];
struct Pos {
	int x,y;
	int reml,remr;
	friend bool operator < (const Pos &a,const Pos &b) {
		return a.reml + a.remr < b.reml + b.remr;
	}
};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int s_x,s_y;
	scanf("%d%d",&s_x,&s_y);
	s_x --;
	s_y --;
	int stepl,stepr;
	scanf("%d%d",&stepl,&stepr);
	for (int i=0;i<n;i++) scanf("%s",&g[i][0]);
	priority_queue <Pos> q;//普通队列：WA40 优先队列：AC
	q.push((Pos){s_x,s_y,stepl,stepr});
	vis[s_x][s_y] = true;
	int ans = 0;
	while (!q.empty()) {
		ans ++;
		Pos cur = q.top();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (g[nx][ny] != '.' || vis[nx][ny]) continue;
			int nsl = cur.reml - (i == 3);
			int nsr = cur.remr - (i == 2);
			if (nsl < 0 || nsr < 0) continue;
			vis[nx][ny] = true;
			q.push((Pos){nx,ny,nsl,nsr});
		}
	}
	printf("%d\n",ans);
	return 0;
}
