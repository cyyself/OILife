#include <bits/stdc++.h>
using namespace std;
long long cal(long long n,long long m) {
	if (n > m) swap(n,m);
	if (n < 2) return 0;
	if (n == 2) {
		return (m*(m-1))/2 - (m)/2;
	}
	if (n >= 3) {
		if (m == 3) return 28;
		else return (n*m)*(n*m-1)/2;
	}
	return 0;
}
int main() {
	long long n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",cal(n,m));
	return 0;
}
/*
#include <bits/stdc++.h>
bool vis[105][105];
struct Pos{
	int x,y;
};
const int dx[] = {-2,-2,-1,-1, 1,1, 2,2};
const int dy[] = {-1, 1,-2, 2,-2,2,-1,1};
int n,m;
int bfs(int x,int y) {
	int cnt = 0;
	queue <Pos> q;
	q.push((Pos){x,y});
	vis[x][y] = true;
	while (!q.empty()) {
		Pos c = q.front();
		q.pop();
		cnt ++;
		for (int i=0;i<8;i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = true;
			q.push((Pos){nx,ny});
		}
	}
	return cnt;
}
int db[10][10];
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				if (!vis[i][j]) {
					int t = bfs(i,j);
					ans += t*(t-1)/2;
				}
			}
		printf("ans=%d\n",ans);
	}
	return 0;
}
*/
