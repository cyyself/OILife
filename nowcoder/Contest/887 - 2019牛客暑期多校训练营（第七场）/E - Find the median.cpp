#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int L[400005],R[400005];
int n;
vector <int> ls;
int lsr[1600005];
bool vir[1600005];//表示这个点是虚拟的点
void init() {
	static long long X[400005],Y[400005];
	long long A1,B1,C1,M1;
	scanf("%lld%lld%lld%lld%lld%lld",&X[1],&X[2],&A1,&B1,&C1,&M1);
	for (int i=3;i<=n;i++) X[i] = (A1 * X[i-1] + B1 * X[i-2] + C1) % M1;
	long long A2,B2,C2,M2;
	scanf("%lld%lld%lld%lld%lld%lld",&Y[1],&Y[2],&A2,&B2,&C2,&M2);
	for (int i=3;i<=n;i++) Y[i] = (A2 * Y[i-1] + B2 * Y[i-2] + C2) % M2;
	for (int i=1;i<=n;i++) {
		L[i] = min(X[i],Y[i]) + 1;
		R[i] = max(X[i],Y[i]) + 1;
		ls.push_back(L[i]);
		ls.push_back(R[i]);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	int precnt = 0;
	int lssize = ls.size();
	for (int i=1;i<lssize;i++) {
		if (ls[i]-ls[i-1] > 1) {
			ls.push_back(ls[i]-1);
			vir[i+precnt+1] = true;
			precnt ++;
		}
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	for (int i=0;i<ls.size();i++) lsr[i+1] = ls[i];
}
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
struct Node {
	long long sum,lazy;
}t[1600005*2];
void push_up(int l,int r) {
	t[node].sum = t[lson].sum + t[rson].sum;
}
void addlazy(int l,int r,long long lazy) {//add lazy to sum
	int rangeL = vir[l]?lsr[l-1]+1:lsr[l];
	int rangeR = vir[r]?lsr[r+1]-1:lsr[r];
	t[node].sum += (rangeR - rangeL + 1LL) * lazy;
}
void push_down(int l,int r) {
	if (t[node].lazy) {
		t[lson].lazy += t[node].lazy;
		addlazy(l,mid,t[node].lazy);
		t[rson].lazy += t[node].lazy;
		addlazy(mid+1,r,t[node].lazy);
		t[node].lazy = 0;
	}
}
void insert(int l,int r,int L,int R,int x) {
	if (l == L && r == R) {
		addlazy(l,r,x);
		t[node].lazy += x;
	}
	else {
		push_down(l,r);
		if (L <= mid) insert(l,mid,L,min(R,mid),x);
		if (R > mid) insert(mid+1,r,max(mid+1,L),R,x);
		push_up(l,r);
	}
}
int query(int l,int r,long long kth) {
	if (l == r) {
		if (vir[l]) return lsr[l-1] + (kth+t[node].lazy-1) / t[node].lazy;
		else return lsr[l];
	}
	else {
		push_down(l,r);
		long long lsum = t[lson].sum;
		if (kth <= lsum) return query(l,mid,kth);
		else return query(mid+1,r,kth-lsum);
	}
}
#undef node
#undef mid
#undef lson
#undef rson
int main() {
	scanf("%d",&n);
	init();
	long long cnt = 0;
	for (int i=1;i<=n;i++) {
		int lsL = lower_bound(ls.begin(),ls.end(),L[i]) - ls.begin() + 1;
		int lsR = lower_bound(ls.begin(),ls.end(),R[i]) - ls.begin() + 1;
		assert(lsL<=lsR);
		cnt += R[i] - L[i] + 1LL;
		//printf("dbg%lld\n",cnt);
		insert(1,ls.size(),lsL,lsR,1);
		printf("%d\n",query(1,ls.size(),(cnt+1)/2));
	}
	return 0;
}
