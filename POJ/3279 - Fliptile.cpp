#include <cstdio>
#include <cstring>
bool g[17][17];
bool cur[17][17];
bool d[17][17];
bool ans[17][17];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int t;
			scanf("%d",&t);
			g[i][j] = t;
		}
	}
	int ans_cnt = 0x3f3f3f3f;
	for (int first=0;first<(1<<m);first++) {
		int cnt = 0;
		memcpy(cur,g,sizeof(cur));
		memset(d,0,sizeof(d));
		for (int j=1;j<=m;j++) if ((first>>(j-1))&1) {
			cnt ++;
			d[1][j] = 1;
			cur[1][j-1] ^= 1;
			cur[1][j]   ^= 1;
			cur[1][j+1] ^= 1;
			cur[2][j] ^= 1;
		}
		for (int i=2;i<=n;i++) {
			for (int j=1;j<=m;j++) if (cur[i-1][j]) {
				d[i][j] = 1;
				cnt ++;
				cur[i][j-1] ^= 1;
				cur[i][j]   ^= 1;
				cur[i][j+1] ^= 1;
				cur[i+1][j] ^= 1;
			}
		}
		bool flag = true;
		for (int j=1;j<=m;j++) if (cur[n][j]) flag = false;
		if (flag && cnt < ans_cnt) {
			ans_cnt = cnt;
			memcpy(ans,d,sizeof(ans));
		}
	}
	if (ans_cnt == 0x3f3f3f3f) printf("IMPOSSIBLE\n");
	else {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (j != 1) printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
