#include <bits/stdc++.h>
using namespace std;
vector <int> x;
vector <int> y;
struct DATA {
	int x1,y1,x2,y2;
	void read() {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1 *= 2;
		y1 *= 2;
		x2 *= 2;
		x2 --;
		y2 *= 2;
		y2 --;
	}
}a[1000];
bool g[4000][4000];
int w,h;
void dfs(int cx,int cy) {
	g[cx][cy] = true;
	const int dx[4] = {1,-1,0,0};
	const int dy[4] = {0,0,1,-1};
	for (int i=0;i<4;i++) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
		if (g[nx][ny]) continue;
		dfs(nx,ny);
	}
}
int main() {
	while (scanf("%d%d",&w,&h) == 2 && w && h) {
		w *= 2;
		h *= 2;
		memset(g,false,sizeof(g));
		x.clear();
		y.clear();
		x.push_back(0);
		y.push_back(0);
		x.push_back(w);
		y.push_back(h);
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			a[i].read();
			x.push_back(a[i].x1);
			x.push_back(a[i].x2);
			x.push_back(a[i].x2+1);
			y.push_back(a[i].y1);
			y.push_back(a[i].y2);
			y.push_back(a[i].y2+1);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		x.erase(unique(x.begin(),x.end()),x.end());
		y.erase(unique(y.begin(),y.end()),y.end());
		w = lower_bound(x.begin(),x.end(),w) - x.begin();
		h = lower_bound(y.begin(),y.end(),h) - y.begin();
		for (int i=0;i<n;i++) {
			a[i].x1 = lower_bound(x.begin(),x.end(),a[i].x1) - x.begin();
			a[i].x2 = lower_bound(x.begin(),x.end(),a[i].x2) - x.begin();
			a[i].y1 = lower_bound(y.begin(),y.end(),a[i].y1) - y.begin();
			a[i].y2 = lower_bound(y.begin(),y.end(),a[i].y2) - y.begin();
			for (int x=a[i].x1;x<=a[i].x2;x++) for (int y=a[i].y1;y<=a[i].y2;y++) g[x][y] = true;
		}
		int ans = 0;
		for (int i=0;i<w;i++) for (int j=0;j<h;j++) {
			if (g[i][j]) continue;
			dfs(i,j);
			ans ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
