#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int g[10][10];
double e[10][10];
pair <int,int> nxt2(int x,int y,int d) {
	for (int i=0;i<d;i++) {
			if (x & 1) {
				y ++;
				if (y == 10) {
					x --;
					y = 9;
				}
			}
			else {
				y --;
				if (y == -1) {
					x --;
					y = 0;
				}
			}
		if (x < 0 || y < 0 || x > 9 || y > 9) return make_pair(-1,-1);
	}
	return make_pair(x,y);
}

int main() {
	for (int i=0;i<=9;i++) for (int j=0;j<=9;j++) scanf("%d",&g[i][j]);
	e[0][0] = 0;
	for (int x=0;x<=9;x++) {
		for (int y=(x&1?9:(x==0?1:0));(x&1?y>=0:y<=9);(x&1?y--:y++)) {
			vector < pair<int,int> > all;
			for (int k=1;k<=6;k++) {
				auto nxtpos = nxt2(x,y,k);
				if (nxtpos.x == -1 && nxtpos.y == -1) continue;
				all.push_back(nxtpos);
			}
			for (auto pos:all) {
				e[x][y] += min(e[pos.x][pos.y],e[pos.x-g[pos.x][pos.y]][pos.y]) + 1;
			}
			e[x][y] += 6 - all.size();
			e[x][y] /= 6;
			e[x][y] /= (double)all.size() / 6;
		}
	}
	printf("%0.10lf\n",e[9][0]);
	return 0;
}
