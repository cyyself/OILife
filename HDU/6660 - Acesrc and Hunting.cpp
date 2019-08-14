#include <bits/stdc++.h>
using namespace std;
pair <int,int> m23[5] = {{1,1},{-1,1},{1,-2},{-1,1},{1,1}};
pair <int,int> m24[7] = {{1,2},{-1,1},{0,-2},{1,-1},{-1,2},{1,-1},{0,2}};
pair <int,int> m25[9] = {{1,1},{-1,2},{0,-2},{1,-1},{-1,2},{1,1},{-1,1},{1,-2},{0,2}};
pair <int,int> m32l[5] = {{1,1},{1,-1},{-2,1},{1,-1},{1,1}};
pair <int,int> m33l[8] = {{1,1},{1,-1},{-2,1},{1,1},{1,-1},{-1,-1},{-1,2},{2,0}};
pair <int,int> m32r[5] = {{-1,-1},{2,1},{-1,-1},{-1,1},{2,-1}};
pair <int,int> m33r[8] = {{-1,-1},{2,0},{-1,-1},{1,2},{-1,-1},{-1,1},{0,-2},{2,0}};
/*
void test() {
	int x = 1, y = 2;
	bool mtx[3][3];
	memset(mtx,false,sizeof(mtx));
	for (int i=0;i<8;i++) {
		mtx[x][y] = true;
		printf("-----BEGIN-----\n");
		for (int j=0;j<3;j++) {
			for (int k=0;k<3;k++) printf("%d",mtx[j][k]);
			printf("\n");
		}
		printf("----- END -----\n");
		x += m33r[i].first;
		y += m33r[i].second;
	}
	mtx[x][y] = true;
	printf("-----BEGIN-----\n");
	for (int j=0;j<3;j++) {
		for (int k=0;k<3;k++) printf("%d",mtx[j][k]);
		printf("\n");
	}
	printf("----- END -----\n");
}
*/
int x,y;
bool rev_xy;
bool vis[105][105];
int cnt;
void pr(int x,int y) {
	if (vis[x][y]) assert(false);
	vis[x][y] = true;
	cnt ++;
	if (rev_xy) printf("%d %d\n",y,x); else printf("%d %d\n",x,y);
}
void work23(bool rev) {
	for (int i=0;i<5;i++) {
		x += m23[i].first * (rev?-1:1);
		y += m23[i].second * (rev?-1:1);
		pr(x,y);
	}
}
void work24(bool rev) {
	for (int i=0;i<7;i++) {
		x += m24[i].first * (rev?-1:1);
		y += m24[i].second * (rev?-1:1);
		pr(x,y);
	}
}
void work25(bool rev) {
	for (int i=0;i<9;i++) {
		x += m25[i].first * (rev?-1:1);
		y += m25[i].second * (rev?-1:1);
		pr(x,y);
	}
}
void work32r() {
	for (int i=0;i<5;i++) {
		x += m32r[i].first;
		y += m32r[i].second;
		pr(x,y);
	}
}
void work33r() {
	for (int i=0;i<8;i++) {
		x += m33r[i].first;
		y += m33r[i].second;
		pr(x,y);
	}
}
void work32l() {
	for (int i=0;i<5;i++) {
		x += m32l[i].first;
		y += m32l[i].second;
		pr(x,y);
	}
}
void work33l() {
	for (int i=0;i<8;i++) {
		x += m33l[i].first;
		y += m33l[i].second;
		pr(x,y);
	}
}
int main() {
	//test();
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		if (n == 1 && m == 1) {
			printf("YES\n1 1\n");
			continue;
		}
		rev_xy = false;
		if (n > m) {
			swap(n,m);
			rev_xy = true;
		}
		if (n >= 2 && m >= 3) {
			cnt = 0;
			for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) vis[i][j] = false;
			printf("YES\n");
			x = 1;
			y = 1;
			bool rev = false;
			if (n & 1) {
				for (int i=0;i<(n-3)/2;i++) {
					pr(x,y);
					while ( (rev?y>1:y<m) ) {
						int dis = rev?y:m-y+1;
						if (dis == 5) work25(rev);
						else if (dis == 4) work24(rev);
						else work23(rev);
						if (rev?y==1:y==m) x += 2;
						else {
							x -= 1 * (rev?-1:1);
							y += 1 * (rev?-1:1);
							pr(x,y);
						}
					}
					rev ^= 1;
				}
				if (rev) {
					while (y > 1) {
						pr(x,y);
						if (y == 3) work33r();
						else work32r();
						x --;
						y --;
					}
				}
				else {
					while (y < m) {
						pr(x,y);
						if (m - y + 1 == 3) work33l();
						else work32l();
						x -= 2;
						y ++;
					}
				}
			}
			else {
				for (int i=0;i<n/2;i++) {
					pr(x,y);
					while ( (rev?y>1:y<m) ) {
						int dis = rev?y:m-y+1;
						if (dis == 5) work25(rev);
						else if (dis == 4) work24(rev);
						else work23(rev);
						if (rev?y==1:y==m) x += 2;
						else {
							x -= 1 * (rev?-1:1);
							y += 1 * (rev?-1:1);
							pr(x,y);
						}
					}
					rev ^= 1;
				}
			}
			assert(cnt == n * m);
		}
		else printf("NO\n");
	}
	return 0;
}
