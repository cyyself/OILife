#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int maxn = 1e5+5;
const int maxm = 2e5+5;
bool vis[maxn];
bool vis_p[maxm];
int have[maxn];
int need[maxn];
vector <int> belong[maxn];
vector <int> ans;
pair <int,int> like[maxm];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&have[i]);
	for (int i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		like[i] = make_pair(a,b);
		need[a] ++;
		need[b] ++;
		belong[a].push_back(i);
		belong[b].push_back(i);
	}
	queue <int> q;
	for (int i=1;i<=n;i++) if (have[i] >= need[i]) {
		q.push(i);
		vis[i] = true;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto x:belong[u]) {
			if (vis_p[x]) continue;
			ans.push_back(x);
			if (like[x].first == u) {
				int v = like[x].second;
				need[v] --;
				if (have[v] >= need[v] && !vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
			else {
				int v = like[x].first;
				need[v] --;
				if (have[v] >= need[v] && !vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
			vis_p[x] = true;
		}
	}
	if (ans.size() == m) {
		printf("ALIVE\n");
		reverse(ans.begin(),ans.end());
		for (int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
	}
	else printf("DEAD\n");
	return 0;
}
