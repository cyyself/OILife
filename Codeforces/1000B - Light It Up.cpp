#include <bits/stdc++.h>
using namespace std;
int a[100005];
int preon[100005];//在此之前开灯的时间
int preoff[100005];//在此之前关灯的时间
int nxt[100005];//在此之后关灯的时间
int n;
int main() {
	int m;
	scanf("%d%d",&n,&m);
	a[0] = 0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1] = m;
	bool stat = true;
	for (int i=1;i<=n+1;i++) {
		if (stat) {
			preon[i] = preon[i-1] + a[i] - a[i-1];
			preoff[i] = preoff[i-1];
		}
		else {
			preoff[i] = preoff[i-1] + a[i] - a[i-1];
			preon[i] = preon[i-1];
		}
		stat = !stat;
	}
	int ans = preon[n+1];
	for (int i=0;i<=n+1;i++) {
		if (i == 0) {
			if (a[1] == 1) continue;
		}
		else {
			if (i == n + 1) {
				if (a[n] == m - 1) continue;
			}
			else {
				//i属于[1,n]
				if (a[i-1] == a[i] - 1 && a[i+1] == a[i] + 1) continue;
			}
		}
		ans = max(ans,preon[i]+preoff[n+1]-preoff[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}