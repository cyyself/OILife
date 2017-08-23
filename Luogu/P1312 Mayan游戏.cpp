#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
inline bool check(int g[5][7]) {
	for (int j=0;j<7;j++) for (int i=0;i<5;i++) if (g[i][j]) return false;
	return true;
}
inline bool fallcheck(int l[7]) {
	bool exist = false;
	for (int i=6;i>=0;i--) {
		if (l[i]) exist = true;
		else if (exist) return false;
	}
	return true;
}
inline bool fall(int g[5][7]) {//让悬空的方块下落
	bool change = false;
	for (int i=0;i<5;i++) {
		while (!fallcheck(g[i])) {
			int space = 0;
			while (g[i][space]) space ++;
			for (int j=space+1;j<7;j++) {
				g[i][j-1] = g[i][j];
				g[i][j] = 0;
			}
		}
	}
	return change;
}
inline bool clear(int g[5][7]) {//清除可以消除的方块
	bool toclear[5][7];
	memset(toclear,false,sizeof(toclear));
	for (int i=0;i<5;i++)
		for (int j=0;j<5&&g[i][j];j++) 
			if (g[i][j] == g[i][j+1] && g[i][j+1] == g[i][j+2]) {
				toclear[i][j] = true;
				toclear[i][j+1] = true;
				toclear[i][j+2] = true;
			}
	
	for (int i=0;i<3;i++) 
		for (int j=0;g[i][j]&&j<7;j++)
			if (g[i][j] && g[i][j] == g[i+1][j] && g[i+1][j] == g[i+2][j]) {
				toclear[i][j] = true;
				toclear[i+1][j] = true;
				toclear[i+2][j] = true;
			}
	bool change = false;
	for (int i=0;i<5;i++)
		for (int j=0;j<7;j++) if (toclear[i][j]) {
			g[i][j] = 0;
			change = true;
		}
	return change;
}
inline void stepin(int x,int y,int d,int g[5][7]) {//d是题目中的g，g是游戏棋盘
	if (g[x+d][y]) swap(g[x][y],g[x+d][y]);
	else {
		g[x+d][y] = g[x][y];
		g[x][y] = 0;
	}
}
struct ope {
	int x,y;
	int type;
}m[5];
bool DFS(int depth,int last[5][7]) {
	int g[5][7];
	memcpy(g,last,sizeof(g));
	if (depth != n) {
		stepin(m[depth].x,m[depth].y,m[depth].type,g);
		fall(g);
		while(clear(g)) fall(g);
	}
	if (depth == 0) {
		if (check(g)) return true;
		return false;
	}
	for (int i=0;i<5;i++)
		for (int j=0;j<7;j++) {
			if (i < 4) {//右移
				if (g[i][j]) {
					if (g[i+1][j] != g[i][j]) {
						m[depth-1].type = 1;
						m[depth-1].x = i;
						m[depth-1].y = j;
						if (DFS(depth-1,g)) return true;
					}
				}
			}
			if (i > 0) {//左移
				if (g[i][j]) {
					if (g[i-1][j] == 0) {
						m[depth-1].type = -1;
						m[depth-1].x = i;
						m[depth-1].y = j;
						if (DFS(depth-1,g)) return true;
					}
				}
			}
		}
	return false;
}
int main() {
	scanf("%d",&n);
	int g[5][7];
	memset(g,0,sizeof(g));
	for (int i=0;i<5;i++) {
		int color;
		int j = 0;
		while (scanf("%d",&color) == 1 && color) {
			g[i][j] = color;
			j++;
		}
	}
	fall(g);
	while(clear(g)) fall(g);
	if (DFS(n,g)) {
		for (int i=n-1;i>=0;i--) printf("%d %d %d\n",m[i].x,m[i].y,m[i].type);
	}
	else printf("-1\n");
	return 0;
}