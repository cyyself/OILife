#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector <pair<int,int> > op[18];
int n,m;
struct UnionSet {
	int f[maxn];
	void init() {
		for (int i=1;i<=n;i++) f[i] = i ;
	}
	int find(int x) {
		if (f[x] == x) return x;
		else return f[x] = find(f[x]);
	}
	void uni(int x,int y) {
		f[find(x)] = find(y);
	}
}us[2];
const long long mo = 1e9+7;
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
int main() {
	scanf("%d%d",&n,&m);
	n ++;
	for (int i=0;i<m;i++) {
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		if ((len & 1) == 1) len ++;
		int k = 0;
		while ((1 << (k + 1)) <= len) k ++;
		op[k].emplace_back(x,y);
		int d = len - (1 << k);
		op[k].emplace_back(x+d,y+d);
	}
	us[1].init();
	for (int i=17;i>=0;i--) {
		int u = i & 1;
		int v = u ^ 1;
		for (auto x:op[i]) us[u].uni(x.first,x.second);
		if (i == 0) break;
		us[v].init();
		for (int j=1;j<=n;j++) if (us[u].find(j) != j) {
			us[v].uni(j,us[u].find(j));
			if (i > 1) us[v].uni(j+(1<<(i-1)),us[u].find(j)+(1<<(i-1)));
		}
	}
	int cnt = 0;
	for (int i=1;i<=n-1;i++) if (us[0].find(i) == i) cnt ++;
	printf("%lld\n",qpow(26,cnt));
	return 0;
}
