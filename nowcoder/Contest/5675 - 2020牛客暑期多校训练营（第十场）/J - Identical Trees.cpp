#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const long long mo = 998244353;
const long long inf = 0x3f3f3f3f;
vector <int> g1[maxn],g2[maxn];
map <int,vector<int> > ch_hash1[maxn],ch_hash2[maxn];
long long h1[maxn],h2[maxn];
int rt1,rt2;
int sz1[maxn],sz2[maxn];
long long qpow(long long a,long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mo;
		}
		b >>= 1;
		a *= a;
		a %= mo;
	}
	return res;
}
void dfs1(int u) {
	sz1[u] = 1;
	for (auto v:g1[u]) {
		dfs1(v);
		sz1[u] += sz1[v];
		ch_hash1[u][h1[v]].push_back(v);
	}
	long long cur_hash = 1;
	for (auto &x:ch_hash1[u]) {
		for (auto &y:x.second) {
			cur_hash = ((cur_hash * qpow(2,sz1[y]*2) % mo) + x.first) % mo;
		}
	}
	cur_hash = (cur_hash * 2) % mo;
	h1[u] = cur_hash;
}
void dfs2(int u) {
	sz2[u] = 1;
	for (auto v:g2[u]) {
		dfs2(v);
		sz2[u] += sz2[v];
		ch_hash2[u][h2[v]].push_back(v);
	}
	long long cur_hash = 1;
	for (auto &x:ch_hash2[u]) {
		for (auto &y:x.second) {
			cur_hash = ((cur_hash * qpow(2,sz2[y]*2) % mo) + x.first) % mo;
		}
	}
	cur_hash = (cur_hash * 2) % mo;
	h2[u] = cur_hash;
}
int w[maxn][maxn];
struct Matrix {
	int n;
	long long a[505][505];
};
struct KM:Matrix {
	long long hl[maxn],hr[maxn],slk[maxn];
	int fl[maxn],fr[maxn],pre[maxn];
	bool vl[maxn],vr[maxn];
	queue <int> q;
	bool check(int i) {
		vl[i] = 1;
		if (fl[i] != -1) {
			q.push(fl[i]);
			vr[fl[i]] = true;
			return true;
		}
		while (i != -1) {
			fl[i] = pre[i];
			swap(i,fr[fl[i]]);
		}
		return 0;
	}
	void bfs(int s) {
		for (int i=0;i<n;i++) {
			slk[i] = 0x3f3f3f3f;
			vl[i] = 0;
			vr[i] = 0;
		}
		while (!q.empty()) q.pop();
		q.push(s);
		vr[s] = true;
		while (true) {
			long long d;
			while (!q.empty()) {
				for (int i=0,j=q.front();i<n;i++) {
					d = hl[i] + hr[j] - a[i][j];
					if (!vl[i] && slk[i] >= d) {
						pre[i] = j;
						if (d) slk[i] = d;
						else if (!check(i)) return;
					}
				}
				q.pop();
			}
			d = inf;
			for (int i=0;i<n;i++) 
				if (!vl[i] && d > slk[i]) d = slk[i];
			for (int i=0;i<n;i++) {
				if (vl[i]) hl[i] += d;
				else slk[i] -= d;
				if (vr[i]) hr[i] -= d;
			}
			for (int i=0;i<n;i++) 
				if (!vl[i] && slk[i] == 0 && !check(i)) return;
		}
	}
	void ask() {
		for (int i=0;i<n;i++) {
			pre[i] = -1;
			fl[i] = -1;
			fr[i] = -1;
			hl[i] = 0;
			hr[i] = 0;
		}
		for (int i=0;i<n;i++) 
			for (int j=0;j<n;j++) hl[i] = max(hl[i],a[i][j]);
		for (int i=0;i<n;i++) bfs(i);
	}
}km;
void dfs3(int u,int v) {
	long long ans = 0;
	if (u != v) ans ++;
	for (auto &each:ch_hash1[u]) {
		for (auto x:ch_hash1[u][each.first]) for (auto y:ch_hash2[v][each.first]) {
			dfs3(x,y);
		}
		km.n = ch_hash1[u][each.first].size();
		for (int i=0;i<km.n;i++) for (int j=0;j<km.n;j++) {
			km.a[i][j] = -w[ch_hash1[u][each.first][i]][ch_hash2[v][each.first][j]];
		}
		km.ask();
		for (int i=0;i<km.n;i++) if (km.fl[i] != -1) ans += -km.a[i][km.fl[i]];
	}
	w[u][v] = ans;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int p;
		scanf("%d",&p);
		if (p == 0) rt1 = i;
		else g1[p].push_back(i);
	}
	for (int i=1;i<=n;i++) {
		int p;
		scanf("%d",&p);
		if (p == 0) rt2 = i;
		else g2[p].push_back(i);
	}
	dfs1(rt1);
	dfs2(rt2);
	dfs3(rt1,rt2);
	printf("%d\n",w[rt1][rt2]);
	return 0;
}
