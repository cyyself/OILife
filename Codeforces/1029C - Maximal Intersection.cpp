#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int NINF = 0x80000000;
int l[300005];
int r[300005];
int prel[300005];
int prer[300005];
int sufl[300005];
int sufr[300005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	prel[0] = 0;
	prer[0] = INF;
	for (int i=1;i<=n;i++) {
		prel[i] = max(l[i],prel[i-1]);
		prer[i] = min(r[i],prer[i-1]);
	}
	sufl[n+1] = 0;
	sufr[n+1] = INF;
	for (int i=n;i>=1;i--) {
		sufl[i] = max(l[i],sufl[i+1]);
		sufr[i] = min(r[i],sufr[i+1]);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) {
		ans = max(ans,min(prer[i-1],sufr[i+1])-max(prel[i-1],sufl[i+1]));
	}
	printf("%d\n",ans);
	return 0;
}
