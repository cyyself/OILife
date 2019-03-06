#include <bits/stdc++.h>
using namespace std;
int tr[5005];
int sum[4][5005];
int n,q;
int lowbit(int x) {
	return x & (-x);
}
void add(int x,int d) {
	for (int i=x;i<=n+1;i+=lowbit(i)) tr[i] += d;
}
int tr_sum(int x) {
	int ret = 0;
	for (int i=x;i>=1;i-=lowbit(i)) ret += tr[i];
	return ret;
}
pair<int,int> in[5005];
int query(int cnt,int l,int r) {
	if (r < l) return 0;
	return sum[cnt][r] - sum[cnt][l-1];
}
int main() {
	scanf("%d%d",&n,&q);
	for (int i=0;i<q;i++) {
		scanf("%d%d",&in[i].first,&in[i].second);
		add(in[i].first,1);
		add(in[i].second+1,-1);
	}
	for (int i=1;i<=n;i++) {
		int s = tr_sum(i);
		sum[1][i] = sum[1][i-1];
		sum[2][i] = sum[2][i-1];
		sum[3][i] = sum[3][i-1];
		if (s >= 1) sum[1][i] ++;
		if (s >= 2) sum[2][i] ++;
		if (s >= 3) sum[3][i] ++;
	}
	int tot = sum[1][n];
	int ans = 0;
	for (int i=0;i<q;i++) {
		for (int j=i+1;j<q;j++) {
			int l = max(in[i].first,in[j].first);
			int r = min(in[i].second,in[j].second);
			if (r < l) {
				ans = max(ans,tot-(query(1,in[i].first,in[i].second)-query(2,in[i].first,in[i].second)) - (query(1,in[j].first,in[j].second)-query(2,in[j].first,in[j].second)));
			}
			else {
				int _l = min(in[i].first,in[j].first);
				int _r = max(in[i].second,in[j].second);
				ans = max(ans,tot-(query(1,l,r)-query(3,l,r))-(query(1,_l,l-1)-query(2,_l,l-1))-(query(1,r+1,_r)-query(2,r+1,_r)));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
