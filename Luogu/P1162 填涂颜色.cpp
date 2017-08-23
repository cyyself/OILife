#include <cstdio>
using namespace std;
int g[35][35];
int n;
const int dx[4] = {1,0,-1,0};//向量
const int dy[4] = {0,1,0,-1};
void fill(int x,int y,int v,int u){
	g[x][y] = u;//填充起点
	for (int i=0;i<4;i++){
		int nx = x + dx[i];//新x坐标
		int ny = y + dy[i];//新y坐标
		if (nx < 0 || ny < 0 || nx > n+1 || ny > n+1) continue;//越界continue，也就是直接i++进入下一次for
		if (g[nx][ny] == v) fill(nx,ny,v,u);//找到了继续填充
	}
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",&g[i][j]);
	fill(0,0,0,3);//从外圈开始把背景的0填充为3
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (g[i][j] == 0) g[i][j] = 2;//剩下的0就是被1包围的，就更改为2
	fill(0,0,3,0);//再把外圈背景的3填为0
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) printf("%d ",g[i][j]);//输出每一行
		printf("\n");
	}
	return 0;
}