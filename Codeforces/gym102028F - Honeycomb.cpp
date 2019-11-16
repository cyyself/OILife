#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define x first
#define y second
char s[4005][6005];
vector < pair<int,int> > g[1000][1000];
int dis[1000][1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T --) {
		int n,m;
		cin >> n >> m;
		int lines = 4 * n + 3;
		cin.getline(s[0],6005);
		for (int i=0;i<lines;i++) {
			cin.getline(s[i],6005);
		}
		pair<int,int> sp = {-1,-1}, tp = {-1,-1};
		for (int i=0;i<n;i++) 
			for (int j=0;j<m;j++) {
				g[i][j].clear();
				dis[i][j] = INF;
				int x = 1 + i * 4 + 2 * (j & 1);
				int y = 1 + j * 6;
				pair<int,int> cu = {x-1,y+4};
				pair<int,int> cd = {x+3,y+4};
				pair<int,int> lu = {x,y};
				pair<int,int> ld = {x+2,y};
				pair<int,int> ru = {x,y+6};
				pair<int,int> rd = {x+2,y+6};
				char c = s[x+1][y+3];
				if (c == 'S') sp = {i,j};
				if (c == 'T') tp = {i,j};
				if (s[cu.x][cu.y] == ' ') g[i][j].push_back({i-1,j});
				if (s[cd.x][cd.y] == ' ') g[i][j].push_back({i+1,j});
				if (j & 1) {
					if (s[lu.x][lu.y] == ' ') g[i][j].push_back({i,j-1});
					if (s[ru.x][ru.y] == ' ') g[i][j].push_back({i,j+1});
					if (s[ld.x][ld.y] == ' ') g[i][j].push_back({i+1,j-1});
					if (s[rd.x][rd.y] == ' ') g[i][j].push_back({i+1,j+1});
				}
				else {
					if (s[lu.x][lu.y] == ' ') g[i][j].push_back({i-1,j-1});
					if (s[ru.x][ru.y] == ' ') g[i][j].push_back({i-1,j+1});
					if (s[ld.x][ld.y] == ' ') g[i][j].push_back({i,j-1});
					if (s[rd.x][rd.y] == ' ') g[i][j].push_back({i,j+1});
				}
			}
		if (sp.x == -1 || tp.x == -1) {
			cout << "-1\n";
			continue;
		}
		queue <pair<int,int> > q;
		q.push(sp);
		dis[sp.x][sp.y] = 1;
		while (!q.empty() && dis[tp.x][tp.y] == INF) {
			auto cur = q.front();
			q.pop();
			for (auto x:g[cur.x][cur.y]) {
				if (dis[cur.x][cur.y] + 1 < dis[x.x][x.y]) {
					dis[x.x][x.y] = dis[cur.x][cur.y] + 1;
					q.push({x.x,x.y});
				}
			}
		}
		if (dis[tp.x][tp.y] == INF) cout << "-1\n";
		else cout << dis[tp.x][tp.y] << "\n";
	}
	return 0;
}
