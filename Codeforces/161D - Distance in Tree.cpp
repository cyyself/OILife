#include <bits/stdc++.h>
using namespace std;
int n,k;
vector <int> g[50005];
int f[50005][505];//f[i][j]表示在第i个节点上，有多少个子节点与它距离为j
long long ans;
void dfs(int u,int pre) {
	f[u][0] = 1;
	for (auto v:g[u]) {
		if (v != pre) {
			dfs(v,u);
			//计算有多少个子节点到u距离为1~k
			for (int i=1;i<=k;i++) f[u][i] += f[v][i-1];
		}
	}
	ans += f[u][k];
	long long pair_sum = 0;
	for (auto v:g[u]) {
		if (v != pre) {
			//计算以u为根的子树内有多少对点可以匹配（最后要除以2）
			for (int i=1;i<k;i++) pair_sum += f[v][i-1] * (f[u][k-i]-f[v][k-i-1]);
		}
	}
	ans += pair_sum/2;
}
int main() {
	cin >> n >> k;
	for (int i=1;i<n;i++) {
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);	
	}
	dfs(1,-1);
	cout << ans << endl;
	return 0;
}
