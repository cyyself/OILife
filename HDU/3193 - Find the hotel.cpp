#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
struct segtree {
	int min;
}tr[20005];
int a[10005];
void build_tree(int l,int r) {
	if (l == r) {
		tr[node].min = a[l];
	}
	else {
		build_tree(l,mid);
		build_tree(mid+1,r);
		tr[node].min = min(tr[lson].min,tr[rson].min);
	}
}
int query_min(int l,int r,int L,int R) {
	if (R < L) return INF;
	if (l == L && r == R) {
		return tr[node].min;
	}
	else {
		if (L > mid) return query_min(mid+1,r,L,R);
		if (R <= mid) return query_min(l,mid,L,R);
		return min(query_min(l,mid,L,mid),query_min(mid+1,r,mid+1,R));
	}
}
pair <int,int> p[10005];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		memset(a,0x3f,sizeof(a));
		for (int i=0;i<n;i++) {
			scanf("%d%d",&p[i].first,&p[i].second);
			p[i].first ++;//可能取到0，这种写法的线段树必须从1开始，因此+1
			a[p[i].first] = min(a[p[i].first],p[i].second);
		}
		build_tree(1,10000);
		vector <pair<int,int> > ans;
		for (int i=0;i<n;i++) {
			int lmin = query_min(1,10000,1,p[i].first-1);
			if (lmin >= p[i].second) {
				ans.push_back(make_pair(p[i].first-1,p[i].second));
			}
		}
		sort(ans.begin(),ans.end());
		cout << ans.size() << endl;
		for (auto x:ans) printf("%d %d\n",x.first,x.second);
	}
	return 0;
}
