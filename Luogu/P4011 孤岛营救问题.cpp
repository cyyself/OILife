#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int INF = 0x3f3f3f3f;
int dis[1<<10][10][10];
int n,m,p;
int key[10][10];
int type[10][10][4];
struct DATA {
	int stat,x,y;
	int dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
void spfa() {
	memset(dis,0x3f,sizeof(dis));
	priority_queue <DATA> q;
	dis[0][0][0] = 0;
	q.push((DATA){0,0,0,0});
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		if (dis[cur.stat][cur.x][cur.y] < cur.dis) continue;
		int nstat = cur.stat | key[cur.x][cur.y];
		for (int i=0;i<4;i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (type[cur.x][cur.y][i] != -1 && (nstat & type[cur.x][cur.y][i]) == 0)
				continue;
			if (dis[cur.stat][cur.x][cur.y] + 1 < dis[nstat][nx][ny]) {
				dis[nstat][nx][ny] = dis[cur.stat][cur.x][cur.y] + 1;
				fflush(stdout);
				q.push((DATA){nstat,nx,ny,dis[nstat][nx][ny]});
			}
		}
	}
}
int main() {
	memset(type,-1,sizeof(type));
	scanf("%d%d%d",&n,&m,&p);
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int x1,y1,x2,y2,g;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
		x1 --;
		y1 --;
		x2 --;
		y2 --;
		int dir = 0;
		while (x2 != x1 + dx[dir] || y2 != y1 + dy[dir]) dir ++;
		if (g == 0) {
			type[x1][y1][dir] = 0;
			type[x2][y2][(dir+2)%4] = 0;
		}
		else {
			type[x1][y1][dir] = 1<<(g-1);
			type[x2][y2][(dir+2)%4] = 1<<(g-1);
		}
	}
	int s;
	scanf("%d",&s);
	for (int i=0;i<s;i++) {
		int x,y,q;
		scanf("%d%d%d",&x,&y,&q);
		x --;
		y --;
		key[x][y] |= 1 << (q - 1);
	}
	spfa();
	int ans = INF;
	for (int i=0;i<(1<<p);i++) ans = min(ans,dis[i][n-1][m-1]);
	printf("%d\n",ans==INF?-1:ans);
	return 0;
}
