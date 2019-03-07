#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,b,k;
int st_min[251][251][9][9];
int st_max[251][251][9][9];
void init() {
	int zs = log2(n);
	for (int i=0;i<=zs;i++)
		for (int j=0;j<=zs;j++) {
			if (i == 0 && j == 0) continue;
			for (int x=1;x<=n;x++) for (int y=1;y<=n;y++) {
				int rangex = x + (1 << i) - 1;
				int rangey = y + (1 << j) - 1;
				if (rangex > n || rangey > n) continue;
				if (i == 0) {
					st_min[x][y][i][j] = min(st_min[x][y][i][j-1],st_min[x][y+(1<<(j-1))][i][j-1]);
					st_max[x][y][i][j] = max(st_max[x][y][i][j-1],st_max[x][y+(1<<(j-1))][i][j-1]);
				}
				else {
					st_min[x][y][i][j] = min(st_min[x][y][i-1][j],st_min[x+(1<<(i-1))][y][i-1][j]);
					st_max[x][y][i][j] = max(st_max[x][y][i-1][j],st_max[x+(1<<(i-1))][y][i-1][j]);
				}
			}
		}
}
int query_min(int x1,int x2,int y1,int y2) {
	int k1 = log2(x2-x1+1);
	int k2 = log2(y2-y1+1);
	int m1 = min(st_min[x1][y1][k1][k2],st_min[x2-(1<<k1)+1][y1][k1][k2]);
	int m2 = min(st_min[x1][y2-(1<<k2)+1][k1][k2],st_min[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]);
	return min(m1,m2);
}
int query_max(int x1,int x2,int y1,int y2) {
	int k1 = log2(x2-x1+1);
	int k2 = log2(y2-y1+1);
	int m1 = max(st_max[x1][y1][k1][k2],st_max[x2-(1<<k1)+1][y1][k1][k2]);
	int m2 = max(st_max[x1][y2-(1<<k2)+1][k1][k2],st_max[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]);
	return max(m1,m2);
}
int main() {
	scanf("%d%d%d",&n,&b,&k);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		scanf("%d",&st_min[i][j][0][0]);
		st_max[i][j][0][0] = st_min[i][j][0][0];
	}
	init();
	while (k --) {
		int x1,y1;
		scanf("%d%d",&x1,&y1);
		printf("%d\n",query_max(x1,x1+b-1,y1,y1+b-1) - query_min(x1,x1+b-1,y1,y1+b-1));
	}
	return 0;
}
