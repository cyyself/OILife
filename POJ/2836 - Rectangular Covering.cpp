#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[1<<15];
int n;
struct pos {
	int x,y;
}p[15];
struct rec {
	int s;
	int stat;
}r[15][15];
int dfs(int cur) {
	if (f[cur] != INF) return f[cur];
	for (int i=0;i<n;i++) {
		if ( (cur & (1 << i)) == 0) {
			for (int j=0;j<n;j++) {
				if (j == i) continue;
				f[cur] = min(f[cur],r[i][j].s + dfs(cur|r[i][j].stat) );
			}
		}
	}
	return f[cur];
}
int main() {
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		memset(f,0x3f,sizeof(f));
		memset(r,0,sizeof(r));
		f[(1<<n)-1] = 0;
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (j == i) continue;
				int dx = max(abs(p[i].x - p[j].x),1);//大坑
				int dy = max(abs(p[i].y - p[j].y),1);
				r[i][j].s = dx*dy;//dx和dy可能等于0，我最开始的做法是在这里取max(1,dx*dy)，但是会WA
				for (int k=0;k<n;k++) {
					if (p[k].x >= min(p[i].x,p[j].x) && p[k].x <= max(p[i].x,p[j].x) && p[k].y >= min(p[i].y,p[j].y) && p[k].y <= max(p[i].y,p[j].y)) {
						r[i][j].stat |= (1 << k);
					}
				}
			}
		}
		printf("%d\n",dfs(0));
	}
	return 0;
}
