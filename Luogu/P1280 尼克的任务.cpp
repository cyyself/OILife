#include <bits/stdc++.h>
using namespace std;
struct task{
	int s,t;
	friend bool operator < (const task &a,const task &b) {
		if (a.s > b.s) return true;
		else return false;
	}
}t[10005];
int cnt[10005];
int f[10005];
int n,k;
int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++) {
		scanf("%d%d",&t[i].s,&t[i].t);
		cnt[t[i].s]++;
	}
	sort(t+1,t+1+n);
	f[n+1] = 0;
	for (int i=n;i>=1;i--) {
		if (cnt[i]) {
			for (int j=1;j<=k;j++) {
				if (t[j].s == i) f[i] = max(f[i],f[i+t[j].t]);
			}
		}
		else f[i] = f[i+1] + 1;
	}
	printf("%d\n",f[1]);
	return 0;
}
