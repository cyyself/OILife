#include <cstdio>
#include <queue>
#include <cstring> 
using namespace std;

bool vis[100][100];
char map[100][100];
int cnt = 0;
int m,n;
struct Pos{
	int x;
	int y;
};
Pos NewPos(int x,int y){
	Pos t;
	t.x = x;
	t.y = y;
	return t;
}
void check(Pos p){
	const int nx[] = {-1,0,1,0,1,1,-1,-1};
	const int ny[] = {0,-1,0,1,-1,1,1,-1};
	if (vis[p.x][p.y]) return;
	queue <Pos> q;
	q.push(p);
	while(!q.empty()){
		Pos now = q.front();
		q.pop();
		vis[now.x][now.y] = true;
		for (int i=0;i<8;i++){
			int x = now.x + nx[i];
			int y = now.y + ny[i];
			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (!vis[x][y] && map[x][y] == '@') q.push(NewPos(x,y));
		}
	}
	cnt ++;
}
int main(){
	while(true){
		memset(vis,0,sizeof(vis));
		memset(map,0,sizeof(map));
		scanf("%d%d",&m,&n);
		cnt = 0;
		if (m == 0) break;
		for (int i=0;i<m;i++) scanf("%s",&map[i][0]);
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++) 
				if (map[i][j] == '@') check(NewPos(i,j));
		printf("%d\n",cnt);
	}
	return 0;
}
