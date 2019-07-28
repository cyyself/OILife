#include <bits/stdc++.h>
using namespace std;
int L[3000005],R[3000005];
int a[3000005];
long long pre[3000005];
int n;
void work_R() {
	stack <int> s;
	for (int i=2;i<=n+1;i++) {
		while (!s.empty()) {
			if (a[s.top()] > a[i]) {
				R[s.top()] = i - 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		R[s.top()] = n+1;
		s.pop();
	}
}
void work_L() {
	stack <int> s;
	for (int i=n+1;i>=2;i--) {
		while (!s.empty()) {
			if (a[s.top()] > a[i]) {
				L[s.top()] = i + 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		L[s.top()] = 2;
		s.pop();
	}
}
struct Seg {
	#define node (l+r) | (l!=r)
	#define mid (l+r)/2
	#define lson (l+mid) | (l != mid)
	#define rson (mid+1+r) | (mid+1 != r)
	long long MAX[3000005*2],MIN[3000005*2];
	void build(int l,int r) {
		if (l == r) MAX[node] = MIN[node] = pre[l];
		else {
			build(l,mid);
			build(mid+1,r);
			MIN[node] = min(MIN[lson],MIN[rson]);
			MAX[node] = max(MAX[lson],MAX[rson]);
		}
	}
	long long query_min(int l,int r,int L,int R) {
		if (l == L && r == R) return MIN[node];
		else {
			long long ret = 0x7fffffffffffffff;
			if (L <= mid) ret = min(ret,query_min(l,mid,L,min(R,mid)));
			if (R > mid) ret = min(ret,query_min(mid+1,r,max(L,mid+1),R));
			return ret;
		}
	}
	long long query_max(int l,int r,int L,int R) {
		if (l == L && r == R) return MAX[node];
		else {
			long long ret = 0x8000000000000000;
			if (L <= mid) ret = max(ret,query_max(l,mid,L,min(R,mid)));
			if (R > mid) ret = max(ret,query_max(mid+1,r,max(L,mid+1),R));
			return ret;
		}
	}
	#undef node
	#undef mid
	#undef lson
	#undef rson
}seg;

int main() {
	scanf("%d",&n);
	for (int i=2;i<=n+1;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n+1;i++) {
		long long x;
		scanf("%lld",&x);
		pre[i] = pre[i-1] + x;
	}
	work_R();
	work_L();
	seg.build(1,n+1);
	long long ans = 0x8000000000000000;
	for (int i=2;i<=n+1;i++) {
		if (a[i] >= 0) ans=max(ans,a[i]*(seg.query_max(1,n+1,i,R[i])-seg.query_min(1,n+1,L[i]-1,i-1)));
		else ans=max(ans,a[i]*(seg.query_min(1,n+1,i,R[i])-seg.query_max(1,n+1,L[i]-1,i-1)));
	}
	printf("%lld\n",ans);
	return 0;
}
