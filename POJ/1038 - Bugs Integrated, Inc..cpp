#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p3[11];
int n,m;
int f[2][59049];
bool g[150][10];
int readstat(int stat,int y) {
	return (stat / p3[y]) % 3;
}
void setstat(int &stat,int y,int val) {
	stat += p3[y] * val;
}
int ans;
void dfs(int x,int stat,int nxt_stat,int start_y,int val) {//将这一行的状态转移到下一行
	int cur = x & 1;
	int nxt = cur ^ 1;
	f[nxt][nxt_stat] = max(f[nxt][nxt_stat],val);
	ans = max(ans,val);
	for (int y=start_y;y<m;y++) {
		if (y + 1 < m && x + 2 < n) {
			//考虑3行2列
			if (
				readstat(    stat,y) == 0 && readstat(    stat,y+1) == 0 &&
				readstat(nxt_stat,y) == 0 && readstat(nxt_stat,y+1) == 0
				) {
				int d = 0;
				setstat(d,y  ,2);
				setstat(d,y+1,2);
				bool ok = true;
				for (int i=x;i<=x+2;i++) 
					for (int j=y;j<=y+1;j++) 
						if (g[i][j]) ok = false;
				if (ok) dfs(x,stat,nxt_stat+d,y+1,val+1);
			}
		}
		if (y + 2 < m && x + 1 < n) {
			//考虑2行3列
			if (
				readstat(    stat,y) == 0 && readstat(    stat,y+1) == 0 && readstat(    stat,y+2) == 0 &&
				readstat(nxt_stat,y) == 0 && readstat(nxt_stat,y+1) == 0 && readstat(nxt_stat,y+2) == 0
				) {
				int d = 0;
				setstat(d,y  ,1);
				setstat(d,y+1,1);
				setstat(d,y+2,1);
				bool ok = true;
				for (int i=x;i<=x+1;i++) 
					for (int j=y;j<=y+2;j++) 
						if (g[i][j]) ok = false;
				if (ok) dfs(x,stat,nxt_stat+d,y+1,val+1);
			}
		}
	}
}
int main() {
	p3[0] = 1;
	for (int i=1;i<=10;i++) p3[i] = p3[i-1]*3;
	int T;
	scanf("%d",&T);
	while (T --) {
		memset(g,false,sizeof(g));
		memset(f,-1,sizeof(f));
		int k;
		scanf("%d%d%d",&n,&m,&k);
		while (k --) {
			int x,y;
			scanf("%d%d",&x,&y);
			x --;
			y --;
			g[x][y] = true;
		}
		ans = 0;
		f[0][0] = 0;
		for (int i=0;i<n-1;i++) {
			int cur = i & 1;
			int nxt = cur ^ 1;
			memset(&f[nxt][0],-1,sizeof(int)*p3[m]);
			for (int stat=0;stat<p3[m];stat++) {
				if (f[cur][stat] == -1) continue;
				int nxt_stat = 0;
				for (int i=0;i<m;i++) setstat(nxt_stat,i,max(readstat(stat,i)-1,0));
				dfs(i,stat,nxt_stat,0,f[cur][stat]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
