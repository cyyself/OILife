#include <bits/stdc++.h>
using namespace std;
vector <int> g[200005];
int q[200005];
bool vis[200005];
int head;
int tail;
int ansq[200005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=0;i<n;i++) scanf("%d",&ansq[i]);
	bool ans = (ansq[0] == 1);
	q[tail++] = 1;
	vis[1] = true;
	while (head < tail && ans) {
		int u = q[head];
		head ++;
		map <int,bool> exist;
		for (auto v:g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				exist[v] = true;
			}
		}
		for (int i=0;i<exist.size();i++) {
			q[tail] = ansq[tail];
			if (!exist[ansq[tail]]) {
				ans = false;
			}
			exist[ansq[tail]] = false;
			tail ++;
		}
		exist.clear();
	}
	if (ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}
