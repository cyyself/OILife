#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,m;
int a[505][505];//高度
bool vis[505][505];
int ghcnt = 0;
void prepare() {//(1,p)
	queue <int> xq;
	queue <int> yq;
	for (int i=1;i<=m;i++) {
		vis[1][i] = true;
		xq.push(1);
		yq.push(i);
	}
	while (!xq.empty()) {
		int curx = xq.front(),cury = yq.front();
		xq.pop();
		yq.pop();
		if (curx == n) ghcnt ++;//有一个数据是n=1的，放在下面会WA
		for (int i=0;i<4;i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (vis[nx][ny] || nx == 0 || ny == 0 || nx == n + 1 || ny == m + 1 || a[nx][ny] >= a[curx][cury]) continue;
			vis[nx][ny] = true;
			xq.push(nx);
			yq.push(ny);
		}
	}
}
int lc[505];
int rc[505];
void findlc(int p) {//(n,p)
	queue <int> xq;
	queue <int> yq;
	vis[n][p] = true;
	xq.push(n);
	yq.push(p);
	while (!xq.empty()) {
		int curx = xq.front(),cury = yq.front();
		xq.pop();
		yq.pop();
		if (curx == 1) lc[cury] = p;//有一个数据是n=1的，放在下面会WA
		for (int i=0;i<4;i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (vis[nx][ny] || nx == 0 || ny == 0 || nx == n + 1 || ny == m + 1 || a[nx][ny] <= a[curx][cury]) continue;
			vis[nx][ny] = true;
			xq.push(nx);
			yq.push(ny);
		}
	}
}
void findrc(int p) {//(n,p)
	queue <int> xq;
	queue <int> yq;
	vis[n][p] = true;
	xq.push(n);
	yq.push(p);
	while (!xq.empty()) {
		int curx = xq.front(),cury = yq.front();
		xq.pop();
		yq.pop();
		if (curx == 1) rc[cury] = p;//有一个数据是n=1的，放在下面会WA
		for (int i=0;i<4;i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (vis[nx][ny] || nx == 0 || ny == 0 || nx == n + 1 || ny == m + 1 || a[nx][ny] <= a[curx][cury]) continue;
			vis[nx][ny] = true;
			xq.push(nx);
			yq.push(ny);
		}
	}
}
int f[505];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	prepare();
	if (ghcnt == m) {
		printf("1\n");
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=m;i++) if (!vis[n][i]) findlc(i);
		memset(vis,false,sizeof(vis));
		for (int i=m;i>=1;i--) if (!vis[n][i]) findrc(i);
		memset(f,0x3f,sizeof(f));
		f[0] = 0;
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++) 
				if (lc[j] <= i && rc[j] >= i) f[i] = min(f[i],f[lc[j]-1]+1);
		printf("%d\n",f[m]);
	}
	else {
		printf("0\n%d\n",m-ghcnt);
	}
	return 0;
}
