#include <bits/stdc++.h>
using namespace std;
struct UnionSet {//离散并查集
	unordered_map <int,int> f;
	int find(int x) {
		if (f.find(x) == f.end()) f[x] = x;
		if (f[x] != x) f[x] = find(f[x]);
		return f[x];
	}
	void uni(int x,int y) {
		if (x > y) swap(x,y);
		f[find(x)] = find(y);
	}
	bool query(int x,int y) {
		if (f.find(x) == f.end() || f.find(y) == f.end()) return false;
		return find(x) == find(y);
	}
}s[100005];
unordered_map <int,int> ans[100005];
unordered_set <int> ins[100005];//维护每个节点所属的并查集
int read() {
	int ret = 0;
	int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}
int main() {
	int n,m;
	n = read();
	m = read();
	while (m --) {
		int a,b,c;
		a = read();
		b = read();
		c = read();
		s[c].uni(a,b);
		ins[a].insert(c);
		ins[b].insert(c);
	}
	int q;
	q = read();
	while (q --) {
		int u,v;
		u = read();
		v = read();
		if (ins[u].size() > ins[v].size()) swap(u,v);
		if (ans[u].find(v) == ans[u].end()) {
			int cnt = 0;
			for (auto x:ins[u]) if (s[x].query(u,v)) cnt ++;
			ans[u][v] = cnt;
		}
		printf("%d\n",ans[u][v]);
	}
	return 0;
}
