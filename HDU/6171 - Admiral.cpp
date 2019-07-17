#include <bits/stdc++.h>
using namespace std;
int arr[6][6];
int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,0,0,1};
bool check() {
	for (int i=0;i<6;i++) for (int j=0;j<=i;j++) if (arr[i][j] != i) return false;
	return true;
}
int ans = 21;
void dfs(int dep,int x,int y,int lastd) {
	if (check()) ans = min(ans,dep);
	else {
		if (dep + 1 >= ans) return;
		for (int i=0;i<4;i++) {
			if (i+lastd == 3) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > 5 || ny > nx) continue;
			swap(arr[x][y],arr[nx][ny]);
			dfs(dep+1,nx,ny,i);
			swap(arr[x][y],arr[nx][ny]);
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		ans = 21;
		int posx,posy;
		for (int i=0;i<6;i++) for (int j=0;j<=i;j++) {
			scanf("%d",&arr[i][j]);
			if (arr[i][j] == 0) {
				posx = i;
				posy = j;
			}
		}
		dfs(0,posx,posy,-1);
		if (ans == 21) printf("too difficult\n");
		else printf("%d\n",ans);
	}
	return 0;
}
