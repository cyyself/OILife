#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int num[505];
bool vis[505];
int n;
void dfs(int cur,int root,bool first) {
	vis[cur] = true;
	if (!first && cur == root) return;
	dfs(num[cur],root,false);
}
int main() {
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i=0;i<n;i++) {
			scanf("%d",&num[i]);
			num[i] --;
		}
		int ans = INF;
		int cnt;
		for (int d=0;d<n;d++) {
			int t = num[0];
			for (int i=0;i<n-1;i++) num[i] = num[i+1];
			num[n-1] = t;
			memset(vis,false,sizeof(vis));
			cnt = 0;
			for (int i=0;i<n;i++) {
				if (!vis[i]) {
					cnt ++;
					dfs(i,i,true);
				}
			}
			ans = min(ans,n-cnt);
		}
		reverse(num,num+n);
		for (int d=0;d<n;d++) {
			int t = num[0];
			for (int i=0;i<n-1;i++) num[i] = num[i+1];
			num[n-1] = t;
			memset(vis,false,sizeof(vis));
			cnt = 0;
			for (int i=0;i<n;i++) {
				if (!vis[i]) {
					cnt ++;
					dfs(i,i,true);
				}
			}
			ans = min(ans,n-cnt);
		}
		ans = min(ans,n-cnt);
		printf("%d\n",ans);
	}
	return 0;
}
