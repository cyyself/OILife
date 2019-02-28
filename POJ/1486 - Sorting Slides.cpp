#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct DATA {
	int x1,x2,y1,y2;
	void read() {
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
	}
}r[26];
vector <int> g[26];
int pre[26];
int pre_no_blind[26];
bool vis[26];
int n;
bool dfs(int u,int blind_u,int blind_v) {
	for (vector<int>::iterator it=g[u].begin();it != g[u].end();it ++) {
		int v = *it;
		if (u == blind_u && v == blind_v) continue;
		if (vis[v]) continue;
		vis[v] = true;
		if (pre[v] == -1 || dfs(pre[v],blind_u,blind_v)) {
			pre[v] = u;
			return true;
		}
	}
	return false;
}
int match(int blind_u,int blind_v) {
	memset(pre,-1,sizeof(pre));
	int cnt = 0;
	for (int i=0;i<n;i++) {
		memset(vis,false,sizeof(vis));
		cnt += dfs(i,blind_u,blind_v);
	}
	return cnt;
}
int ans[26];
int main() {
	int cas = 0;
	while (scanf("%d",&n) == 1 && n) {
		for (int i=0;i<n;i++) g[i].clear();
		for (int i=0;i<n;i++) r[i].read();
		for (int i=0;i<n;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			for (int j=0;j<n;j++) {
				if (x >= r[j].x1 && x <= r[j].x2 && y >= r[j].y1 && y <= r[j].y2) {
					g[j].push_back(i);
				}
			}
		}
		bool ok = match(-1,-1) == n;
		if (ok) {
			memcpy(pre_no_blind,pre,sizeof(pre));
			memset(ans,-1,sizeof(ans));
			ok = false;
			for (int i=0;i<n;i++) {
				if (match(pre_no_blind[i],i) != n) {
					ans[pre_no_blind[i]] = i;
					ok = true;
				}
			}
		}
		printf("Heap %d\n",++cas);
		if (!ok) printf("none\n\n");
		else {
			bool first = true;
			for (int i=0;i<n;i++) {
				if (ans[i] != -1) {
					if (!first) printf(" ");
					printf("(%c,%d)",'A'+i,ans[i]+1);
					first = false;
				}
			}
			printf("\n\n");
		}
	}
	return 0;
}
