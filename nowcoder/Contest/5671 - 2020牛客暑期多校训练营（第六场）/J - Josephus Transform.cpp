#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct bin_seg {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
	int sum[maxn<<1];
	void init(int l,int r) {
		if (l != r) {
			init(l,mid);
			init(mid+1,r);
			sum[node] = sum[lson] + sum[rson];
		}
		else sum[node] = 1;
	}
	int getpos(int k,int l,int r) {
		if (l == r) return l;
		else {
			if (k <= sum[lson]) return getpos(k,l,mid);
			else return getpos(k-sum[lson],mid+1,r);
		}
	}
	void delnode(int pos,int l,int r) {
		if (l == r) sum[node] = 0;
		else {
			if (pos <= mid) delnode(pos,l,mid);
			else delnode(pos,mid+1,r);
			sum[node] = sum[lson] + sum[rson];
		}
	}
#undef node
#undef mid
#undef lson
#undef rson
} seg;
void Transform(int *a,int n,int k,int *ans) {
	seg.init(1,n);
	int pos = n;
	for (int i=1;i<=n;i++) {
		pos = 1 + (pos - 1 + k) % (n - i + 1);
		int actpos = seg.getpos(pos,1,n);
		ans[i] = a[actpos];
		seg.delnode(actpos,1,n);
		if (pos == 1) pos = n - i;
		else pos --;
	}
}
void per_power(int *in,int *out,int n,int k) {
	k --;
	static bool vis[maxn];
	for (int i=1;i<=n;i++) vis[i] = false;
	vector <vector<int> > cycle;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		vector <int> cur;
		cur.push_back(i);
		vis[i] = true;
		int x = in[i];
		while (!vis[x]) {
			cur.push_back(x);
			vis[x] = true;
			x = in[x];
		}
		cycle.push_back(cur);
	}
	for (auto &x:cycle) {
		int sz = x.size();
		for (int i=0;i<sz;i++) out[x[i]] = in[x[(i+k)%sz]];
	}
}
void do_per(int *per,int *in,int *out,int n) {
	for (int i=1;i<=n;i++) {
		out[i] = in[per[i]];
	}
}
int raw[maxn],per_1[maxn],per_k[maxn];
bool vis[maxn];
int ans1[maxn],ans2[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		raw[i] = i;
		ans1[i] = i;
	}
	bool cur = true;
	while (m --) {
		int k,x;
		scanf("%d%d",&k,&x);
		Transform(raw,n,k,per_1);
		per_power(per_1,per_k,n,x);
		if (cur) {
			do_per(per_k,ans1,ans2,n);
		}
		else {
			do_per(per_k,ans2,ans1,n);
		}
		cur ^= 1;
	}
	if (cur) {
		for (int i=1;i<=n;i++) printf("%d%c",ans1[i],i==n?'\n':' ');
	}
	else {
		for (int i=1;i<=n;i++) printf("%d%c",ans2[i],i==n?'\n':' ');
	}
	return 0;
}
