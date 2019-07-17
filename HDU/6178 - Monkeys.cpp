#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
	#define BUF_SIZE 100000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline int read() {
		int x = 0;
		char ch;
		while(blank(ch = nc()));
		if(IOerror) return -1;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
		return x;
	}
	#undef BUF_SIZE
};
using fastIO::read;
int n,k;
int f[100005][2];
vector <int> g[100005];
void dfs(int u,int rt) {
	f[u][0] = 0;
	f[u][1] = 0;
	int maxch = 0;
	int mt = -1;
	for (auto v:g[u]) {
		if (v == rt) continue;
		if (f[v][0] == -1) dfs(v,u);
		f[u][0] += max(f[v][0],f[v][1]);
	}
	for (auto v:g[u]) {
		if (v == rt) continue;
		f[u][1] = max(f[u][1],f[u][0] - max(f[v][0],f[v][1]) + f[v][0] + 2);
	}
}
int main() {
	int T = read();
	while (T --) {
		n = read();
		k = read();
		for (int i=1;i<=n;i++) {
			g[i].clear();
			f[i][0] = f[i][1] = -1;
		}
		for (int i=2;i<=n;i++) {
			int a;
			a = read();
			g[i].push_back(a);
			g[a].push_back(i);
		}
		dfs(1,-1);
		int ans = max(f[1][0],f[1][1]);
		if (ans >= k) printf("%d\n",(k+1)/2);
		else printf("%d\n",ans/2+(k-ans));
	}
	return 0;
}
