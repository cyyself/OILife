#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int s[10];
int n,m,p;
char g[1005][1005];
struct DATA {
	int x,y,step;
};
queue <DATA> q[10];
int cnt[10];
bool act[10];
int tot;
bool bfs(int x,int goal) {
	act[x] = false;
	while (!q[x].empty()) {
		DATA cur = q[x].front();
		if (cur.step >= goal) break;
		q[x].pop();
		for (int i=0;i<4;i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (g[nx][ny] == '.') {
				act[x] = true;
				g[nx][ny] = '0' + x;
				q[x].push((DATA){nx,ny,cur.step+1});
				cnt[x] ++;
				tot --;
			}
		}
	}
	return act[x];
}
int main() {
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=p;i++) scanf("%d",&s[i]);
	tot = n * m;
	for (int i=0;i<n;i++) {
		scanf("%s",&g[i][0]);
		for (int j=0;j<m;j++) {
			if (g[i][j] >= '0' && g[i][j] <= '9') {
				q[g[i][j]-'0'].push((DATA){i,j,0});
				cnt[g[i][j]-'0'] ++;
				tot --;
				act[g[i][j]-'0'] = true;
			}
			else if (g[i][j] == '#') tot --;
		}
	}
	int t = 0;
	int c = p;
	while (c > 0) {
		t ++;
		c = 0;
		for (int i=1;i<=p;i++) if (act[i]) c += bfs(i,t * s[i]);
	}
	for (int i=1;i<=p;i++) printf("%d ",cnt[i]);
	puts("");
	return 0;
}
