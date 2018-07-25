#include <bits/stdc++.h>
using namespace std;
int n;
int g[105][105];

int dis[105];
bool inq[105];
int pre[105];
void spfa(int s) {
	queue <int> q;
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	memset(inq,false,sizeof(inq));
	q.push(s);
	dis[s] = 0;
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=1;i<=n;i++) {
			if (g[u][i] != 0 && dis[u] + g[u][i] < dis[i]) {
				dis[i] = dis[u] + g[u][i];
				pre[i] = u;
				if (!inq[i]) {
					q.push(i);
					inq[i] = true;
				}
			}
		}
	}
}
int main() {
	int s,t;
	scanf("%d%d",&s,&t);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%d",&g[i][j]);
	spfa(s);
	if (dis[t] == 0x3f3f3f3f) {
		printf("NO\n");
	}
	else {
		stack <int> ans;
		ans.push(t);
		for (int i=pre[t];i != -1;i=pre[i]) ans.push(i);
		while (!ans.empty()) {
			printf("%d\n",ans.top());
			ans.pop();
		}
	}
	return 0;
}
