#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[10][10];
bool vis[10];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		memset(f,0x3f,sizeof(f));
		for (int i=0;i<=9;i++) f[i][i] = 0;
		memset(vis,false,sizeof(vis));
		while (n --) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			vis[a] = true;
			vis[b] = true;
			f[b][a] = f[a][b] = min(f[a][b],c);
		}
		for (int k=0;k<=9;k++) {
			if (!vis[k]) continue;
			for (int i=0;i<=9;i++) {
				if (!vis[i]) continue;
				for (int j=0;j<=9;j++) {
					if (!vis[j]) continue;
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int ans_city = 0;
		int ans_dis = INF;
		for (int i=0;i<=9;i++) {
			if (!vis[i]) continue;
			int cur = 0;
			for (int j=0;j<=9;j++) if (vis[j]) cur += f[i][j];
			if (cur < ans_dis) {
				ans_dis = cur;
				ans_city = i;
			}
		}
		printf("%d %d\n",ans_city,ans_dis);
	}
	return 0;
}
