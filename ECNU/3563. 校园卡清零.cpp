#include <bits/stdc++.h>
using namespace std;
int f[101],pre[101];
int a[1005];
int cnt[101];
int avail[500];
int main() {
	memset(f,0x3f,sizeof(f));
	memset(pre,-1,sizeof(pre));
	int n,p;
	scanf("%d%d",&n,&p);
	f[0] = 0;
	for (int i=1;i<=n*2;i++) {
		scanf("%d",&a[i]);
		for (int k=0;k<100;k++) {
			for (int j=0;j<=100;j++) {
				if (f[(j-a[i]+100)%100] + 1 < f[j]) {
					f[j] = f[(j-a[i]+100)%100] + 1;
					pre[j] = (j-a[i]+100)%100;
				}
			}
		}
	}
	int cur = p;
	int last = pre[cur];
	int tot = 0;
	int all = 0;
	while (last != -1) {
		int cost = (cur-last+100)%100;
		if (cost == 0) cost = 100;
		tot += cost;
		cnt[cost] ++;
		all ++;
		cur = last;
		last = pre[cur];
	}
	int need = tot / 100 - (p == 100);
	while (all) {
		int sel = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&avail[i]);
			if (cnt[a[avail[i]]]) {
				sel = avail[i];
			}
		}
		if (sel != 0) {
			cnt[a[sel]] --;
			all --;
		}
		printf("%d %d\n",need,sel);
		fflush(stdout);
		need -= need;
	}
	return 0;
}
