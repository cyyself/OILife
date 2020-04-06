#include <bits/stdc++.h>
using namespace std;
bool r[55][55],c[55][55];
int n,k;
int mt[55][55];
bool ok;
void dfs(int x,int y,int sum) {
	if (x == n && y == n) {
		if (sum == k) ok = true;
	}
	else {
		int nx = x;
		int ny = y + 1;
		if (y == n) {
			nx = x + 1;
			ny = 1;
		}
		for (int i=1;i<=n && !ok;i++) {
			if (!r[nx][i] && !c[ny][i]) {
				r[nx][i] = true;
				c[ny][i] = true;
				mt[nx][ny] = i;
				dfs(nx,ny,sum+(nx==ny?i:0));
				r[nx][i] = false;
				c[ny][i] = false;
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		scanf("%d%d",&n,&k);
		ok = false;
		printf("Case #%d: ",cas);
		dfs(1,0,0);
		if (!ok) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) printf("%d%c",mt[i][j],j==n?'\n':' ');
		}
	}
	return 0;
}
