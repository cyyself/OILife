#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int dx[] = {0,-1,0,0,1};
const int dy[] = {0,0,-1,1,0};
struct DATA {
	int x,y;
	int step;
	DATA (int _x,int _y,int _step) {
		x = _x;
		y = _y;
		step = _step;
	}
};
int g[305][305];
bool vis[305][305];
int main() {
	int m;
	while (scanf("%d",&m) == 1) {
		memset(g,0x3f,sizeof(g));
		memset(vis,false,sizeof(false));
		for (int i=0;i<m;i++) {
			int x,y,t;
			scanf("%d%d%d",&x,&y,&t);
			for (int j=0;j<5;j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= 305 || ny >= 305) continue;
				g[nx][ny] = min(g[nx][ny],t);
			}
		}
		queue <DATA> q;
		if (g[0][0] >= 1) q.push(DATA(0,0,0));
		vis[0][0] = true;
		int ans = -1;
		while (!q.empty()) {
			DATA cur = q.front();
			//printf("%d %d %d\n",cur.x,cur.y,cur.step);
			q.pop();
			if (g[cur.x][cur.y] == INF) {
				ans = cur.step;
				break;
			}
			g[cur.x][cur.y] = 0;
			for (int i=1;i<5;i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= 305 || ny >= 305) continue;
				if (g[nx][ny] <= cur.step + 1) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = true;
				q.push(DATA(nx,ny,cur.step+1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
