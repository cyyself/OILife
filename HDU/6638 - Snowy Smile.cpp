#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int x,y;
	long long w;
}p[2005];
struct Node {
	long long pre,sum,suf,ans;
}t[2005*2];
#define node ((l+r)|(l!=r))
#define mid ((l + r) >> 1)
#define lson ((l+mid)|(l!=mid))
#define rson ((mid+1+r)|(mid+1!=r))
void push_up(int l,int r) {
	t[node].pre = max(t[lson].pre,t[lson].sum+t[rson].pre);
	t[node].suf = max(t[rson].suf,t[lson].suf+t[rson].sum);
	t[node].sum = t[lson].sum + t[rson].sum;
	t[node].ans = max(t[lson].ans,max(t[rson].ans,t[lson].suf+t[rson].pre));
}
void update(int l,int r,int x,long long d) {
	if (l == x && r == x) {
		t[node].sum += d;
		t[node].pre = t[node].suf = t[node].ans = t[node].sum;
	}
	else {
		if (x <= mid) update(l,mid,x,d);
		else update(mid+1,r,x,d);
		push_up(l,r);
	}
}
#undef node
#undef mid
#undef lson
#undef rson
vector <pair<int,long long> > x[2005];
vector <int> lsx,lsy;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		lsx.clear();
		lsy.clear();
		for (int i=1;i<=n;i++) {
			scanf("%d%d%lld",&p[i].x,&p[i].y,&p[i].w);
			lsx.push_back(p[i].x);
			lsy.push_back(p[i].y);
		}
		sort(lsx.begin(),lsx.end());
		sort(lsy.begin(),lsy.end());
		lsx.erase(unique(lsx.begin(),lsx.end()),lsx.end());
		lsy.erase(unique(lsy.begin(),lsy.end()),lsy.end());
		for (int i=1;i<=lsx.size();i++) x[i].clear();
		for (int i=1;i<=n;i++) {
			p[i].x = lower_bound(lsx.begin(),lsx.end(),p[i].x) - lsx.begin() + 1;
			p[i].y = lower_bound(lsy.begin(),lsy.end(),p[i].y) - lsy.begin() + 1;
			x[p[i].x].push_back({p[i].y,p[i].w});
		}
		long long ans = 0;
		for (int i=1;i<=lsx.size();i++) {
			for (int j=2;j<=2*lsy.size()+1;j++) memset(&t[j],0,sizeof(Node));
			for (int j=i;j<=lsx.size();j++) {
				for (auto p:x[j]) update(1,lsy.size(),p.first,p.second);
				ans = max(ans,t[(1+lsy.size())|(1!=lsy.size())].ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
