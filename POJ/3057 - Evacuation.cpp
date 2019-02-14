//被一个数据坑了WA好久找不出原因
/*
12 12
XXXXXXXXXXDD
X..........X
X.XXXXXXXXXX
X..........X
XXXXXXXXXX.X
X..........X
X.XXXXXXXXXX
X..........X
XXXXXXXXXX.X
X..........X
X.X.X.X.X..X
XXXXXXXXXXXX
答案是60而不是55
门是不能穿过去的
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
const int INF = 0x3f3f3f3f;
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};
vector <pair<int,int> > d;
vector <pair<int,int> > e;
char s[12][13];
vector <int> g[145];
int dis[145][145];
bool inq[145];
void spfa(int s) {
	dis[s][s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (vector<int>::iterator it=g[u].begin();it != g[u].end();it ++) {
			int v = *it;
			if (dis[s][u] + 1 < dis[s][v]) {
				dis[s][v] = dis[s][u] + 1;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
}
vector <int> g2[90000];
int pre[145];
bool vis[145];
bool dfs(int u) {
	for (vector<int>::iterator it=g2[u].begin();it != g2[u].end();it ++) {
		int v = *it;
		if (!vis[v]) {
			vis[v] = true;
			if (!pre[v] || dfs(pre[v])) {
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int n,m;
inline int getnum(int x,int y) {
	return x * m + y + 1;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		d.clear();
		e.clear();
		memset(dis,0x3f,sizeof(dis));
		for (int i=0;i<145;i++) g[i].clear();
		for (int i=0;i<90000;i++) g2[i].clear();
		memset(pre,0,sizeof(pre));
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%s",s[i]);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
			if (s[i][j] == 'D') {
				d.push_back(make_pair(i,j));
				for (int k=0;k<4;k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (s[nx][ny] == '.') g[getnum(i,j)].push_back(getnum(nx,ny));
				}
			}
			if (s[i][j] == '.') {
				e.push_back(make_pair(i,j));
				for (int k=0;k<4;k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (s[nx][ny] != 'X') g[getnum(i,j)].push_back(getnum(nx,ny));
				}
			}
		}
		for (int i=0;i<d.size();i++) spfa(getnum(d[i].first,d[i].second));
		bool ok = true;
		for (int i=0;i<e.size();i++) {
			bool flag = false;
			for (int j=0;j<d.size();j++) {
				int t = dis[getnum(d[j].first,d[j].second)][getnum(e[i].first,e[i].second)];
				if (t != INF) {
					flag = true;
					for (int k=0;k<e.size();k++) {
						g2[(t+k)*d.size()+j].push_back(getnum(e[i].first,e[i].second));
					}
				}
			}
			if (!flag) ok = false;
		}
		if (!ok) printf("impossible\n");
		else {
			int cnt = 0;
			for (int t=0;t<90000;t++) {
				memset(vis,false,sizeof(vis));
				cnt += dfs(t);
				if (cnt == e.size()) {
					printf("%d\n",t/(int)d.size());
					break;
				}
			}
		}
	}
	return 0;
}
