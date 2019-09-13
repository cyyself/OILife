#include <bits/stdc++.h>
using namespace std;
#define node ((l + r) | (l != r))
#define mid ((l+r)>>1)
#define lson ((l+mid) | (l != mid))
#define rson ((mid+1+r) | (mid+1 != r))
const int maxn = 1e5+5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long ninf = -inf;
pair <long long,int> xpy[maxn];//x+y
pair <long long,int> xsy[maxn];//x-y
struct Seg {
	pair<long long,int> MIN[maxn<<1][2],MAX[maxn<<1][2];
	void clear(int l,int r) {
		MIN[node][0] = {inf,inf};
		MIN[node][1] = {inf,inf};
		MAX[node][0] = {ninf,ninf};
		MAX[node][1] = {ninf,ninf};
	}
	void push_up(int l,int r) {
		clear(l,r);
		pair <long long,int> hx[4] = {MIN[lson][0],MIN[lson][1],MIN[rson][0],MIN[rson][1]};
		for (int i=0;i<4;i++) MIN[node][0] = min(MIN[node][0],hx[i]);
		for (int i=0;i<4;i++) if (hx[i].second != MIN[node][0].second) MIN[node][1] = min(MIN[node][1],hx[i]);
		pair <long long,int> hx2[4] = {MAX[lson][0],MAX[lson][1],MAX[rson][0],MAX[rson][1]};
		for (int i=0;i<4;i++) MAX[node][0] = max(MAX[node][0],hx2[i]);
		for (int i=0;i<4;i++) if (hx2[i].second != MAX[node][0].second) MAX[node][1] = max(MAX[node][1],hx2[i]);
	}
	pair <pair<long long,int>,pair<long long,int> > query_min(int l,int r,int L,int R) {
		if (l == L && r == R) {
			return {MIN[node][0],MIN[node][1]};
		}
		else {
			if (R <= mid) return query_min(l,mid,L,R);
			else if (L > mid) return query_min(mid+1,r,L,R);
			else {
				auto resl = query_min(l,mid,L,mid);
				auto resr = query_min(mid+1,r,mid+1,R);
				pair <long long,int> hx[4] = {resl.first,resl.second,resr.first,resr.second};
				pair <pair<long long,int>,pair<long long,int> > res = {{inf,inf},{inf,inf}};
				for (int i=0;i<4;i++) res.first = min(res.first,hx[i]);
				for (int i=0;i<4;i++) if (hx[i].second != res.first.second) res.second = min(res.second,hx[i]);
				return res;
			}
		}
	}
	pair <pair<long long,int>,pair<long long,int> > query_max(int l,int r,int L,int R) {
		if (l == L && r == R) {
			return {MAX[node][0],MAX[node][1]};
		}
		else {
			if (R <= mid) return query_max(l,mid,L,R);
			else if (L > mid) return query_max(mid+1,r,L,R);
			else {
				auto resl = query_max(l,mid,L,mid);
				auto resr = query_max(mid+1,r,mid+1,R);
				pair <long long,int> hx[4] = {resl.first,resl.second,resr.first,resr.second};
				pair <pair<long long,int>,pair<long long,int> > res = {{ninf,ninf},{ninf,ninf}};
				for (int i=0;i<4;i++) res.first = max(res.first,hx[i]);
				for (int i=0;i<4;i++) if (hx[i].second != res.first.second) res.second = max(res.second,hx[i]);
				return res;
			}
		}
	}
	void build(int l,int r,pair<long long,int> *arr) {
		if (l == r) {
			clear(l,r);
			MIN[node][0] = arr[l];
			MAX[node][0] = arr[l];
		}
		else {
			build(l,mid,arr);
			build(mid+1,r,arr);
			push_up(l,r);
		}
	}
	void update(int l,int r,int pos,pair<long long,int> *arr) {
		if (l == r) {
			clear(l,r);
			MIN[node][0] = arr[l];
			MAX[node][0] = arr[l];
		}
		else {
			if (pos <= mid) update(l,mid,pos,arr);
			else update(mid+1,r,pos,arr);
			push_up(l,r);
		}
	}
}seg[2];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		printf("Case #%d:\n",cas);
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			xpy[i] = {x+y,c};
			xsy[i] = {x-y,c};
		}
		seg[0].build(1,n,xpy);
		seg[1].build(1,n,xsy);
		for (int i=0;i<m;i++) {
			int o;
			scanf("%d",&o);
			if (o == 1) {
				int k,x,y;
				scanf("%d%d%d",&k,&x,&y);
				xpy[k].first += x + y;
				xsy[k].first += x - y;
				seg[0].update(1,n,k,xpy);
				seg[1].update(1,n,k,xsy);
			}
			else if (o == 2) {
				int k,c;
				scanf("%d%d",&k,&c);
				xpy[k].second = c;
				xsy[k].second = c;
				seg[0].update(1,n,k,xpy);
				seg[1].update(1,n,k,xsy);
			}
			else {
				int l,r;
				scanf("%d%d",&l,&r);
				auto min0 = seg[0].query_min(1,n,l,r);
				/*
				if (min0.second.first == inf) {
					printf("0\n");
					continue;
				}
				*/
				auto max0 = seg[0].query_max(1,n,l,r);
				long long ans = 0;
				if (min0.first.second != max0.first.second) ans = max(ans,max0.first.first-min0.first.first);
				else {
					ans = max(ans,max0.second.first-min0.first.first);
					ans = max(ans,max0.first.first-min0.second.first);
				}
				auto min1 = seg[1].query_min(1,n,l,r);
				auto max1 = seg[1].query_max(1,n,l,r);
				if (min1.first.second != max1.first.second) ans = max(ans,max1.first.first-min1.first.first);
				else {
					ans = max(ans,max1.second.first-min1.first.first);
					ans = max(ans,max1.first.first-min1.second.first);
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
