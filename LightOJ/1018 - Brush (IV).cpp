#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
struct pos {
	int x,y;
}p[20];
int f[1<<16];
int l[20][20];
int dfs(int stat) {
	if (f[stat] < INF) return f[stat];
	if (__builtin_popcount(stat) <= 2) f[stat] = 1;
	else {
		int i = 0;
		while (!(stat & (1 << i))) i++;
		for (int j=i+1;j<n;j++) {
			if (stat & (1 << j)) {
				f[stat] = min(f[stat],dfs(stat&(~l[i][j]))+1);
			}
		}
	}
	return f[stat];
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(f,0x3f,sizeof(f));
		memset(l,0,sizeof(l));
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++) {
				l[i][j] = (1 << i) | (1 << j);
				int dx = p[i].x - p[j].x;
				int dy = p[i].y - p[j].y;
				for (int k=j+1;k<n;k++) {
					int _dx = p[i].x - p[k].x;
					int _dy = p[i].y - p[k].y;
					if (_dx * dy == _dy * dx) l[i][j] |= (1 << k);
				}
			}
		f[0] = 0;
		printf("Case %d: %d\n",c,dfs( (1 << n) - 1));
	}
	return 0;
}
