#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 205;
int n,m;
int ind[maxn];
vector <int> g[maxn];
int seq[maxn];
bool topo() {
	int cnt = 0;
	priority_queue <int> q;
	for (int i=1;i<=n;i++) if (ind[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.top();
		q.pop();
		seq[cnt++] = u;
		for (int i=0;i<g[u].size();i++) {
			int x = g[u][i];
			ind[x] --;
			if (ind[x] == 0) q.push(x);
			else if (ind[x] < 0) return false;
		}
	}
	return cnt == n;
}
int pos[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			g[i].clear();
			ind[i] = 0;
		}
		for (int i=0;i<m;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			ind[a] ++;
			g[b].push_back(a);
		}
		if (topo()) {
			for (int i=0;i<n;i++) pos[seq[i]] = n - i;
			for (int i=1;i<=n;i++) printf("%d%c",pos[i],i==n?'\n':' ');
		}
		else printf("-1\n");
	}
	return 0;
}
