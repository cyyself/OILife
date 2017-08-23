//用数组存联通块数量版
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
struct Pos{
	int x,y;
	Pos(int _x,int _y):x(_x),y(_y){}
	Pos():x(0),y(0){}
};
int n,m;
char map[1005][1005];
int judge[1005][1005];
int result[100005];
int sp = 0;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
void search(int x,int y){
	int spnow = ++sp;
	queue <Pos> q;
	q.push(Pos(x,y));
	int cnt = 0;
	judge[x][y] = spnow;
	while(!q.empty()){
		cnt ++;
		Pos now = q.front();
		q.pop();
		for (int i=0;i<4;i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (judge[nx][ny] == 0 && map[now.x][now.y] != map[nx][ny]) {
				judge[nx][ny] = spnow;
				q.push(Pos(nx,ny));
			}
		}
	}
	result[spnow] = cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",&map[i][1]);
	for (int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (judge[x][y] == 0) search(x,y);
		printf("%d\n",result[judge[x][y]]);
	}
	return 0;
}
/*
指针版：
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
struct Pos{
	int x,y;
	Pos(int _x,int _y):x(_x),y(_y){}
	Pos():x(0),y(0){}
};
int n,m;
char map[1005][1005];
int *judge[1005][1005];
int sp = 0;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
void search(int x,int y){
	int spnow = ++sp;
	queue <Pos> q;
	q.push(Pos(x,y));
	int *cnt = new int;
	*cnt = 0;
	judge[x][y] = cnt;
	while(!q.empty()){
		(*cnt)++;
		Pos now = q.front();
		q.pop();
		for (int i=0;i<4;i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (judge[nx][ny] == 0 && map[now.x][now.y] != map[nx][ny]) {
				judge[nx][ny] = cnt;
				q.push(Pos(nx,ny));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",&map[i][1]);
	for (int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (judge[x][y] == 0) search(x,y);
		printf("%d\n",*judge[x][y]);
	}
	return 0;
}
*/