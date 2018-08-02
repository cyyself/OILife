//保证字典序最小只要从后往前推状态就行了
//垃圾题目，2年前写过今天再写调了一小时
#include <bits/stdc++.h>
using namespace std;
int mt[15][105];
int pre[15][105];
int n,m;
const int dx[] = {-1,0,1};
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		memset(pre,-1,sizeof(pre));
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) scanf("%d",&mt[i][j]);
		for (int y=m-2;y>=0;y--)
			for (int x=0;x<n;x++) {
				int delta = 0x7fffffff;
				for (int k=0;k<3;k++) {
					if (mt[(x+dx[k]+n)%n][y+1] < delta || (mt[(x+dx[k]+n)%n][y+1] == delta && ((x+dx[k]+n)%n) < pre[x][y]) ) {
						delta = mt[(x+dx[k]+n)%n][y+1];
						pre[x][y] = (x+dx[k]+n)%n;
					}
				}
				mt[x][y] += delta;
			}
		int ans = 0x7fffffff;
		int ans_pos = -1;
		for (int x=0;x<n;x++) {
			if (mt[x][0] < ans) {
				ans = mt[x][0];
				ans_pos = x;
			}
		}
		printf("%d",ans_pos+1);
		for (int y=0;y<=m-2;y++) {
			ans_pos = pre[ans_pos][y];
			printf(" %d",ans_pos+1);
		}
		printf("\n%d\n",ans);
	}
	return 0;
}
