#include <bits/stdc++.h>
using namespace std;
vector <int> g[100005];
int clr[100005];
bool bp;
int cnt[2];
void dfs(int u,int c) {
	clr[u] = c;
	cnt[c] ++;
	for (auto v:g[u]) {
		if (clr[v] == -1) dfs(v,c^1);
		else {
			if (clr[v] != (c ^ 1)) bp = false;
		}
	}
}
long long c_2(long long x) {
	return x * (x - 1) / 2;
}
long long c_3(long long x) {
	return (x * (x - 1) * (x - 2)) / (2 * 3);
}
int main() {
	memset(clr,-1,sizeof(clr));
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bp = true;
	vector <pair<int,int> > v;
	for (int i=1;i<=n;i++) if (clr[i] == -1) {
		memset(cnt,0,sizeof(cnt));
		dfs(i,0);
		v.push_back(make_pair(cnt[0],cnt[1]));
	}
	if (!bp) printf("0 1\n");
	else {
		long long cnt_3 = 0;
		for (auto x:v) cnt_3 += c_2(x.first) + c_2(x.second);
		if (cnt_3 == 0) {
			if (m != 0) printf("2 %lld\n",1ll*m*(n-2));
			else printf("3 %lld\n",c_3(n));
		}
		else printf("1 %lld\n",cnt_3);
	}
	return 0;
}
