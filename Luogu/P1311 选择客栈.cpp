#include <bits/stdc++.h>
using namespace std;
int last[200005];
int cnt[200005];
int sum[200005];
int main() {
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	int ans = 0;
	int cafe = -1;
	for (int i=0;i<n;i++) {
		int c,pi;
		scanf("%d%d",&c,&pi);
		if (pi <= p) cafe = i;
		if (cafe >= last[c]) sum[c] = cnt[c];
		cnt[c] ++;
		ans += sum[c];
		last[c] = i;
	}
	printf("%d\n",ans);
	return 0;
}
