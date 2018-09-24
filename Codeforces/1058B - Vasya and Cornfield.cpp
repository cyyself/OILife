#include <bits/stdc++.h>
using namespace std;
bool g[205][205];
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int n,d;
void printg() {
	for (int x=2*n;x>=0;x--) {
		for (int y=0;y<=2*n;y++) 
			if (g[x][y]) printf("x");
			else printf("_");
		printf("\n");
	}
}
int main() {
	scanf("%d%d",&n,&d);
	for (int x=0;x<=d*2;x++) {
		int y = d*2 - x;
		g[x][y] = true;
	}
	for (int x=0;x<=(n-d)*2;x++) {
		int y = x + d * 2;
		g[x][y] = true;
	}
	for (int x=(n-d)*2;x<=n*2;x++) {
		int y = n*2 - (x - (n-d)*2);
		g[x][y] = true;
	}
	for (int x=d*2;x<=n*2;x++) {
		int y = x - d*2;
		g[x][y] = true;
	}
	queue < pair<int,int> > q;
	q.push({d*2,1});
	g[d*2][1] = true;
	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int x = cur.first  + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || y < 0 || x > n * 2 || y > n * 2) continue;
			if (!g[x][y]) {
				g[x][y] = true;
				q.push({x,y});
			}
		}
	}
	//printg();
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (g[x*2][y*2]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
