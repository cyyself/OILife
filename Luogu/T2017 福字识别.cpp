#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int h,w;
char g[500][501];
int ans = 0;
struct pos{
	int x,y;
};
void fillzero(int x,int y) {
	queue <pos> q;
	q.push((pos){0,0});
	g[x][y] = '2';
	while(!q.empty()) {
		pos curr = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];
			if (nx < 0 || ny < 0 || nx > h+1 || ny > h+1) continue;
			if (g[nx][ny] == '0') {
				g[nx][ny] = '2';
				q.push((pos){nx,ny});
			}
		}
	}
}
bool check(int x,int y) {
	queue <pos> q;
	q.push((pos){x,y});
	g[x][y] = '2';
	int cnt = 0;
	while(!q.empty()) {
		pos curr = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];
			if (nx < 0 || ny < 0 || nx > h+1 || ny > h+1) continue;
			if (g[nx][ny] == '0') {
				fillzero(nx,ny);
				cnt ++;
			}
			if (g[nx][ny] == '1') {
				g[nx][ny] = '2';
				q.push((pos){nx,ny});
			}
		}
	}
	if (cnt == 5) return true;
	else return false;
}
int main() {
	scanf("%d%d",&h,&w);
	memset(g,'0',sizeof(g));
	for (int i=1;i<=h;i++) scanf(" %s",&g[i][1]);
	fillzero(0,0);
	for (int i=1;i<=h;i++) for (int j=1;j<=w;j++) ans += check(i,j);
	printf("%d\n",ans);
	return 0;
}