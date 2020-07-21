#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define rd(n) FastIO::read(n)

namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;

        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
const int maxn = 1e5+5;
vector <int> g[maxn],g2[maxn];
int a[maxn];
int id[maxn];
int n,m;
int blk;
struct value_block {
	int blk_sum[1000];
	int cnt[maxn];
	void clear() {
		for (int i=0;i<n;i++) cnt[i] = 0;
		for (int i=0;i<blk+1;i++) blk_sum[i] = 0;
	}
	value_block() {
		clear();
	}
	void add(int x) {
		if (x >= n) return;
		if (cnt[x] == 0) {
			blk_sum[x/blk] ++;
		}
		cnt[x] ++;
	}
	void del(int x) {
		if (x >= n) return;
		if (cnt[x] == 1) {
			blk_sum[x/blk] --;
		}
		cnt[x] --;
	}
	int mex() {
		for (int i=0;i<blk+1;i++) if (blk_sum[i] != blk) {
			for (int j=blk*i;j<blk*i+blk;j++) if (!cnt[j]) {
				return j;
			}
		}
		return -1;//inf
	}
};
vector <value_block> b;
value_block tmp;
int query(int u) {
	if (g[u].size() <= blk) {
		for (auto v:g[u]) tmp.add(a[v]);
		int res = tmp.mex();
		for (auto v:g[u]) tmp.del(a[v]);
		return res;
	}
	else {
		vector <int> op;
		for (auto v:g2[u]) op.push_back(a[v]);
		for (auto val:op) b[id[u]].add(val);
		int ans = b[id[u]].mex();
		for (auto val:op) b[id[u]].del(val);
		return ans;
	}
}
void modify(int u,int val) {
	if (g[u].size() > blk) {
		a[u] = val;
	}
	else {
		for (auto v:g[u]) if (g[v].size() > blk) {
			b[id[v]].del(a[u]);
			b[id[v]].add(val);
		}
		a[u] = val;
	}
}
int main() {
	int T;
	rd(T);
	//scanf("%d",&T);
	while (T --) {
		rd(n);
		rd(m);
		//scanf("%d%d",&n,&m);
		blk = sqrt(n);
		tmp.clear();
		b.clear();
		for (int i=1;i<=n;i++) {
			rd(a[i]);
			//scanf("%d",&a[i]);
			g[i].clear();
			g2[i].clear();
		}
		for (int i=0;i<m;i++) {
			int u,v;
			rd(u);
			rd(v);
			//scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i=1;i<=n;i++) if (g[i].size() > blk) {
			id[i] = b.size();
			b.push_back(value_block());
			for (auto v:g[i]) {
				if (g[v].size() <= blk) {
					b[id[i]].add(a[v]);
				}
				else {
					g2[i].push_back(v);
				}
			}
		}
		int q;
		rd(q);
		//scanf("%d",&q);
		while (q --) {
			int op;
			rd(op);
			//scanf("%d",&op);
			if (op == 1) {
				int u,val;
				rd(u);
				rd(val);
				//scanf("%d%d",&u,&val);
				modify(u,val);
			}
			else {
				int u;
				rd(u);
				//scanf("%d",&u);
				int ans = query(u);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
