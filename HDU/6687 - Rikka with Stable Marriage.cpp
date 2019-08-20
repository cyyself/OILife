#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
struct Node {
	int sum;
	int ch[2];
}t[100005*30*2];
int cnt;
void insert(int node,int dep,int val) {
	t[node].sum ++;
	if (dep > 0) {
		if (!t[node].ch[(val >> (dep-1))&1]) {
			t[node].ch[(val >> (dep-1))&1] = ++cnt;
			t[t[node].ch[(val >> (dep-1))&1]].ch[0] = t[t[node].ch[(val >> (dep-1))&1]].ch[1] = 0;
		}
		insert(t[node].ch[(val >> (dep-1))&1],dep-1,val);
	}
}
int query(int a,int b,int dep) {
	t[a].sum --;
	t[b].sum --;
	if (dep == 0) return 0;
	else {
		if (t[t[a].ch[0]].sum && t[t[b].ch[1]].sum) return 1 << (dep - 1) | query(t[a].ch[0],t[b].ch[1],dep-1);
		else if (t[t[a].ch[1]].sum && t[t[b].ch[0]].sum) return 1 << (dep - 1) | query(t[a].ch[1],t[b].ch[0],dep-1);
		else if (t[t[a].ch[1]].sum && t[t[b].ch[1]].sum) return query(t[a].ch[1],t[b].ch[1],dep-1);
		else if (t[t[a].ch[0]].sum && t[t[b].ch[0]].sum) return query(t[a].ch[0],t[b].ch[0],dep-1);
		else {
			assert(false);
			return 0;
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		cnt = 2;
		t[1].ch[0] = t[1].ch[1] = t[2].ch[0] = t[2].ch[1] = 0;
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			insert(1,30,a[i]);
		}
		for (int i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			insert(2,30,b[i]);
		}
		long long ans = 0;
		for (int i=1;i<=n;i++) ans += query(1,2,30);
		printf("%lld\n",ans);
	}
	return 0;
}
