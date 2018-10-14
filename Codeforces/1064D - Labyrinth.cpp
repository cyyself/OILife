#include <bits/stdc++.h>
using namespace std;
char g[2005][2005];
bool vis[2005][2005];
int dy[2] = {1,-1};
struct Pos {
	int x,y;
	int reml,remr;
};
int main() {
	int n,m;
	int s_x,s_y;
	int stepl,stepr;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s_x,&s_y);
	scanf("%d%d",&stepl,&stepr);
	for (int i=0;i<n;i++) scanf("%s",&g[i][0]);

	queue <Pos> q;
	q.push((Pos){s_x-1,s_y-1,stepl,stepr});
	int ans = 0;
	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		if (vis[cur.x][cur.y]) continue;
		for (int x= cur.x ; x<n && g[x][cur.y] == '.';x++) {
			vis[x][cur.y] = true;
			ans ++;
			for (int i=0;i<2;i++) {
				int y = cur.y + dy[i];
				int nsl = cur.reml - (i == 1);
				int nsr = cur.remr - (i == 0);
				if ( y < 0 || y >= m || nsl < 0 || nsr < 0 || vis[x][y] || g[x][y] != '.') continue;
				q.push((Pos){x,y,nsl,nsr});
			}
		}
		for (int x=cur.x-1;x>=0 && g[x][cur.y] == '.';x--) {
			vis[x][cur.y] = true;
			ans ++;
			for (int i=0;i<2;i++) {
				int y = cur.y + dy[i];
				int nsl = cur.reml - (i == 1);
				int nsr = cur.remr - (i == 0);
				if ( y < 0 || y >= m || nsl < 0 || nsr < 0 || vis[x][y] || g[x][y] != '.') continue;
				q.push((Pos){x,y,nsl,nsr});
			}
		}
	}
	/*
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) printf("%d",vis[i][j]);
		printf("\n");
	}
	*/
	printf("%d\n",ans);
	return 0;
}
