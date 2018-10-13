#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};
char g[25][25];
bool vis[25][25];
int main() {
	int h,w;
	while (scanf("%d%d",&w,&h) == 2 && w && h){
		memset(vis,false,sizeof(vis));
		for (int i=0;i<h;i++) scanf("%s",&g[i][0]);
		int sx = -1;
		int sy = -1;
		for (int i=0;i<h;i++) 
			for (int j=0;j<w;j++) if (g[i][j] == '@') {
				sx = i;
				sy = j;
			}
		//printf("%d %d\n",sx,sy);
		queue < pair<int,int> > q;
		q.push(make_pair(sx,sy));
		vis[sx][sy]  = true;
		int ans = 1;
		while (!q.empty()) {
			pair <int,int> cur = q.front();
			q.pop();
			for (int i=0;i<4;i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (g[nx][ny] != '.') continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = true;
				ans ++;
				q.push(make_pair(nx,ny));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
