#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int g[15];
int s[4005];
int f[15][4005];
inline bool judge_col(int x) {//同一行不能相邻
	return x & (x << 1);//可以返回false,不可以返回true
}
inline bool judge_row(int x,int y) {//相邻两行不能有同一列，以及一行中0的位置不能放
	return (x & y);//可以返回false,不可以返回true
}
int main() {
	int stot = 0;
	for (int i=0;i<(1<<12);i++) if (!judge_col(i)) s[stot++] = i;
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				int t;
				scanf("%d",&t);
				if (!t) g[i] |= (1 << j);//把输入为0的位置存为1，当做是障碍
			}
		int scnt = upper_bound(s,s+stot,(1<<m)-1) - s;
		for (int j=0;j<scnt;j++) if (!judge_row(s[j],g[0])) f[0][j] = 1;
		for (int i=1;i<n;i++) {
			for (int j=0;j<scnt;j++) {
				if (judge_row(s[j],g[i])) continue;
				for (int k=0;k<scnt;k++) {
					if (judge_row(s[j],s[k])) continue;
					f[i][j] += f[i-1][k];
					f[i][j] %= 100000000;
				}
			}
		}
		int ans = 0;
		for (int j=0;j<scnt;j++) {
			ans += f[n-1][j];
			ans %= 100000000;
		}
		printf("%d\n",ans);
	}
	return 0;
}
