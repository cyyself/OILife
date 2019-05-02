#include <bits/stdc++.h>
using namespace std;
struct edge {
	int u,v;
	int next;
	bool vis;
}e[2][400005];
int head[2][200005];
int blk[200005][2];
long long blksize[400005];//这个blk中有多少个点
int blkcnt;
int ecnt[2];
vector <pair<int,int> > mem;
inline void _addedge(int u,int v,int c) {
	e[c][ecnt[c]].u = u;
	e[c][ecnt[c]].v = v;
	e[c][ecnt[c]].next = head[c][u];
	head[c][u] = ecnt[c];
	ecnt[c] ++;
}
inline void addedge(int u,int v,int c) {
	_addedge(u,v,c);
	_addedge(v,u,c);
}
void bfs(int se,int c) {
	blkcnt ++;
	queue <int> q;
	q.push(se);
	e[c][se].vis = true;
	unordered_set <int> s;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		s.insert(e[c][u].u);
		s.insert(e[c][u].v);
		if (!blk[e[c][u].u][c]) {
			for (int i=head[c][e[c][u].u];~i;i=e[c][i].next) {
				if (e[c][i].vis) continue;
				q.push(i);
				e[c][i].vis = true;
			}
		}
		blk[e[c][u].u][c] = blkcnt;
		if (!blk[e[c][u].v][c]) {
			for (int i=head[c][e[c][u].v];~i;i=e[c][i].next) {
				if (e[c][i].vis) continue;
				q.push(i);
				e[c][i].vis = true;
			}
		}
		blk[e[c][u].v][c] = blkcnt;
	}
	blksize[blkcnt] = s.size();
}
int main() {
	int n;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		addedge(u,v,c&1);
	}
	for (int i=0;i<ecnt[0];i++) if (!e[0][i].vis) bfs(i,0);
	for (int i=0;i<ecnt[1];i++) if (!e[1][i].vis) bfs(i,1);
	long long ans = 0;
	for (int i=1;i<=blkcnt;i++) ans += blksize[i] * (blksize[i]-1LL);
	for (int i=1;i<=n;i++) if (blk[i][0] && blk[i][1]) {
		int x = blk[i][0];
		int y = blk[i][1];
		if (x > y) swap(x,y);
		mem.push_back(make_pair(x,y));
	}
	sort(mem.begin(),mem.end());
	mem.erase(unique(mem.begin(),mem.end()),mem.end());
	for (auto x:mem) ans += (blksize[x.first]-1) * (blksize[x.second] - 1);
	printf("%lld\n",ans);
	return 0;
}
