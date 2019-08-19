#include <bits/stdc++.h>
using namespace std;
bool ans[105][105];
bool query(int x1,int y1,int x2,int y2) {//能构成回文返回false
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int ret;
	fflush(stdin);
	scanf("%d",&ret);
	return ret == 0;
}
bool getcell(int x,int y,int color) {
	if ((x + y) & 1) return ans[x][y] ^ color;
	else return ans[x][y];
}
bool check(int x1,int y1,int x2,int y2,int color) {//在这种颜色下，这个矩形存不存在回文路径
	if (x2 - x1 == 1 && y2 - y1 == 2) {
		return getcell(x1,y1,color) == getcell(x2,y2,color) &&
		 (getcell(x2,y1,color) == getcell(x2,y1+1,color) ||
		  getcell(x1,y1+1,color) == getcell(x1,y2,color) ||
		  getcell(x1,y1+1,color) == getcell(x2,y1+1,color));
	}
	else if (x2 - x1 == 2 && y2 - y1 == 1) {
		return getcell(x1,y1,color) == getcell(x2,y2,color) &&
		 (getcell(x1+1,y1,color) == getcell(x2,y1,color) ||
		  getcell(x1+1,y1,color) == getcell(x1+1,y2,color) ||
		  getcell(x1,y2,color) == getcell(x1+1,y2,color));
	}
	else {
		assert(false);
	}
}
int main() {
	ans[1][1] = 1;
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i+=2) {
		if (i != 1) ans[i][1] = ans[i-2][1] ^ query(i-2,1,i,1);
		for (int j=3;j<=n;j+=2) ans[i][j] = ans[i][j-2] ^ query(i,j-2,i,j);
	}
	for (int i=2;i<=n;i+=2) {
		if (i == 2) ans[2][2] = ans[1][1] ^ query(1,1,2,2);
		else ans[i][2] = ans[i-2][2] ^ query(i-2,2,i,2);
		for (int j=4;j<=n;j+=2) ans[i][j] = ans[i][j-2] ^ query(i,j-2,i,j);
	}
	//询问完了所有已经确定的格子，所有不确定的格子是(x+y)%2 == 1的地方
	for (int i=1;i<=n;i++) {
		if (i & 1) {
			if (i != 1) ans[i][2] = ans[i-1][1] ^ query(i-1,1,i,2);
			for (int j=4;j<=n;j+=2) ans[i][j] = ans[i][j-2] ^ query(i,j-2,i,j);
		}
		else {
			ans[i][n] = ans[i-1][n-1] ^ query(i-1,n-1,i,n);
			for (int j=n-2;j>=1;j-=2) ans[i][j] = ans[i][j+2] ^ query(i,j,i,j+2);
		}
	}
	int ansc = -1;
	for (int i=1;i<=n && ansc == -1;i++) for (int j=1;j<=n && ansc == -1;j++) {
		int d = i + 2;
		int r = j + 1;
		if (d <= n && r <= n) {
			bool c[2] = {check(i,j,d,r,0),check(i,j,d,r,1)};
			if (c[0] ^ c[1]) {
				int curc = c[0]?0:1;
				if (!query(i,j,d,r)) ansc = curc;
				else ansc = curc ^ 1;
			}
		}
		d = i + 1;
		r = j + 2;
		if (d <= n && r <= n && ansc == -1) {
			bool c[2] = {check(i,j,d,r,0),check(i,j,d,r,1)};
			if (c[0] ^ c[1]) {
				int curc = c[0]?0:1;
				if (!query(i,j,d,r)) ansc = curc;
				else ansc = curc ^ 1;
			}
		}
	}
	if (ansc == -1) {
		assert(false);
	}
	else {
		printf("!\n");
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) printf("%d",getcell(i,j,ansc));
			printf("\n");
		}
		fflush(stdout);
	}
	return 0;
}
