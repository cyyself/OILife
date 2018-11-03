#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge {
	int v;
	int next;
}e[20005];
int ecnt;
int head[10005];
void add(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int f[10005];
int n;
int dfs(int u) {
	f[u] = 0;
	int maxch = 0;
	int sum = 1;
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		if (f[v] != -1) continue;
		int cur = dfs(v);
		sum += cur;
		maxch = max(maxch,cur);
	}
	f[u] = max(n-sum,maxch);
	return sum;
}
int main() {
	while (scanf("%d",&n) == 1) {
		memset(f,-1,sizeof(f));
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		bool flag = false;
		for (int i=1;i<=n;i++) {
			if (2 * f[i] <= n) {
				printf("%d\n",i);
				flag = true;
			}
		}
		if (!flag) printf("NONE\n");
	}
	return 0;
}
