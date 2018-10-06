#include <bits/stdc++.h>
using namespace std;
char g[1005][1005];
bool b[1005][1005];
int dx[8] = { 0, 0, 0, 1, 1, 2, 2, 2};
int dy[8] = { 0, 1, 2, 0, 2, 0, 1, 2};
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt = 0;
	for (int i=0;i<n;i++) {
		scanf("%s",&g[i][0]);
		for (int j=0;j<m;j++) if (g[i][j] == '#') {
			cnt ++;
			b[i][j] = true;
		}
	}
	for (int i=0;i<n-2;i++)
		for (int j=0;j<m-2;j++) {
			bool flag = true;
			for (int k=0;k<8 && flag;k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (g[x][y] != '#') flag = false;
			}
			if (flag) {
				for (int k=0;k<8;k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (b[x][y]) {
						cnt --;
						b[x][y] = false;
					}
				}
			}
		}
	if (cnt) printf("NO\n");
	else printf("YES\n");
	return 0;
}
