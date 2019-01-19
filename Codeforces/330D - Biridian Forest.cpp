#include <bits/stdc++.h>
using namespace std;
queue <pair<int,int> > q;
int dis[1005][1005];
char g[1005][1005];
int vis[1005][1005];
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int main() {
	memset(dis,0x3f,sizeof(dis));
	int r,c;
	scanf("%d%d",&r,&c);
	pair <int,int> S;
	for (int i=0;i<r;i++) {
		scanf("%s",&g[i][0]);
		for (int j=0;j<c;j++) {
			if (g[i][j] == 'E') {
				q.push({i,j});
				vis[i][j] = true;
				dis[i][j] = 0;
			}
			if (g[i][j] == 'S') S = {i,j};
		}
	}
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = cur.first  + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (!vis[nx][ny] && ( (g[nx][ny] >= '0' && g[nx][ny] <= '9') || g[nx][ny] == 'S')) {
				q.push({nx,ny});
				dis[nx][ny] = dis[cur.first][cur.second] + 1;
				vis[nx][ny] = true;
			}
		}
	}
	long long ans = 0;
	for (int i=0;i<r;i++) for (int j=0;j<c;j++) {
		if (g[i][j] >= '0' && g[i][j] <= '9' && dis[i][j] <= dis[S.first][S.second]) ans += g[i][j] - '0'; 
	}
	printf("%lld\n",ans);
	return 0;
}
