#include <cstdio>
#include <cstring>
#include <algorithm>
using std::upper_bound;
int g[15];
int s[405];
int f[15][405];//已经提前算出不含相邻情况的状态数 
inline bool judgex(int s) {//是否有相邻的1,true:无 
	if (s & (s << 1)) return false;
	return true;
}
inline bool judgeg(int line,int status) {//判断当前状态是否可以放在这一行，true:可以 
	if (g[line] & status) return false;
	return true;
}
int main() {
	int n,m;
	int stot = 0;
	for (int i=0;i<(1<<12);i++) if (judgex(i)) s[stot++] = i;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		//memset(s,0,sizeof(s));
		for (int i=0;i<n;i++) 
			for (int j=0;j<m;j++) {
				int t;
				scanf("%d",&t);
				if (t == 0) g[i] += (1 << j);
			}
		int scnt = upper_bound(s,s+stot,(1<<m) - 1) - s;
		for (int i=0;i<scnt;i++) if (judgeg(0,s[i])) f[0][i] = 1;
		for (int i=1;i<n;i++) {
			for (int j=0;j<scnt;j++) {
				if (!judgeg(i,s[j])) continue;
				for (int k=0;k<scnt;k++) {
					if (!judgeg(i-1,s[k])) continue;
					if (!(s[j] & s[k])) f[i][j] = (f[i][j] + f[i-1][k]) % 100000000;
				}
			}
		}
		int ans = 0;
		for (int i=0;i<scnt;i++) {
			ans = (ans + f[n-1][i] ) % 100000000; 
		}
		printf("%d\n",ans);
	}
	return 0;
}
