#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int dx[8] = {-2,-2,-1,-1,1,1,2,2};
const int dy[8] = {-1,1,2,-2,-2,2,-1,1};
struct Pos {
	int x,y,path;
	Pos(int _x,int _y,int _path):x(_x),y(_y),path(_path){}
};
int map[205][205];
int n,m;
int GetNumberLength(int n) {
	if (n == 0) return 1;
	int r = 1 + (log(abs(n)) / log(10));
	if (n < 0) r ++;
	return r;
}
void BFS(int x,int y,int path){
	queue <Pos> q;
	q.push(Pos(x,y,path));
	map[x][y] = path;
	while(!q.empty()) {
		Pos now = q.front();
		q.pop();
		for (int i=0;i<8;i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (map[nx][ny] == -1) {
				q.push(Pos(nx,ny,now.path+1));
				map[nx][ny] = now.path+1;
			}
		}
	}
}
int main(){
	memset(map,-1,sizeof(map));
	int x,y;
	cin >> n >> m >> x >> y;
	BFS(x,y,0);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cout << map[i][j];
			for (int k=5;k>GetNumberLength(map[i][j]);k--) cout << " ";
		}
		cout << endl;
	}
	return 0;
}