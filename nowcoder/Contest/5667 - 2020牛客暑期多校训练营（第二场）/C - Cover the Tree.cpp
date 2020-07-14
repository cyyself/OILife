#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
vector <int> g[maxn];
int deg[maxn];
pair <int,int> up[maxn];//两个节点
vector <pair<int,int> > ans;
void dfs(int u,int f) {
	queue <int> q;
	int ch = 0;
	for (auto v:g[u]) {
		if (v == f) continue;
		ch ++;
		dfs(v,u);
		if (up[v].first && up[v].second) {
			//size = 2
			if (q.size()) {
				ans.push_back(make_pair(q.front(),up[v].first));
				q.pop();
				q.push(up[v].second);
			}
			else {
				q.push(up[v].first);
				q.push(up[v].second);
			}
			
		}
		else if (up[v].first) {
			if (q.size() >= 2) {
				ans.push_back(make_pair(q.front(),up[v].first));
				q.pop();
			}
			else q.push(up[v].first);
		}
	}
	if (ch == 0) up[u].first = u;
	else {
		//do match
		if (f == -1) {//root match all
			if (q.size() == 2) {
				int x = q.front();
				q.pop();
				int y = q.front();
				q.pop();
				ans.push_back(make_pair(x,y));
			}
			else ans.push_back(make_pair(u,q.front()));
		}
		else {
			if (q.size() == 2) {
				up[u].first = q.front();
				q.pop();
				up[u].second = q.front();
				q.pop();
			}
			else if (q.size() == 1) {
				up[u].first = q.front();
				q.pop();
			}
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	if (n == 1) printf("0\n");
	else if (n == 2) {
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n%d %d\n",1,u,v);
	}
	else {
		for (int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u] ++;
			deg[v] ++;
		}
		for (int i=1;i<=n;i++) if (deg[i] > 1) {
			dfs(i,-1);
			break;
		}
		printf("%d\n",(int)ans.size());
		for (auto x:ans) {
			printf("%d %d\n",x.first,x.second);
		}
	}
	return 0;
}
