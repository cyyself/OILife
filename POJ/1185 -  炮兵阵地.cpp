#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int tstat;
inline bool judge(int x) {
	return !( (x & (x << 1)) | (x & (x << 2)));
}
int stat[65];
int f[105][65][65];
int scnt;
int g[105];
void cal() {
	for (int m=1;m<=10;m++) {
		int cnt = 0;
		for (int i=0;i<(1<<m);i++) if (judge(i)) cnt ++;
		printf("%d\n",cnt);
	}
}
int main() {
	//cal();
	scanf("%d%d",&n,&m);
	tstat = (1 << m) - 1;
	for (int i=0;i<(1<<m);i++) if (judge(i)) stat[scnt ++] = i;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			char c;
			scanf(" %c",&c);
			if (c == 'H') g[i] |= (1 << j);
		}
	}
	for (int i=0;i<n;i++) for (int j=0;j<scnt;j++) {
		if (stat[j] & g[i]) continue;
		int cnt =  __builtin_popcount(stat[j]);
		if (i == 0) f[i][j][0] = cnt;
		else for (int k=0;k<scnt;k++) {
			if (stat[j] & stat[k]) continue;
			for (int l=0;l<scnt;l++) {
				if (stat[j] & stat[l]) continue;
				f[i][j][k] = max(f[i][j][k],f[i-1][k][l]+cnt);
			}
		}
	}
	int ans = 0;
	for (int i=0;i<scnt;i++) for (int j=0;j<scnt;j++) ans = max(ans,f[n-1][i][j]);
	printf("%d\n",ans);
	return 0;
}
