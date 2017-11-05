#include <bits/stdc++.h>
using namespace std;
int n;

int a[100005];
int f[100005];
int g[100005];
int main() {
	int tmp;
	while (scanf("%d",&a[++n]) == 1);
	n --;
	f[1] = a[1];
	g[1] = a[1];
	int ans1 = 1;
	int ans2 = 1;
	for (int i=2;i<=n;i++) {
		int p;
		for (p=1;f[p] >= a[i]  && p <= ans1;p++);
		f[p] = a[i];
		ans1 = max(ans1,p);
		int q;
		for (q=1;g[q] < a[i] && q <= ans2;q++);
		g[q] = a[i];
		ans2 = max(ans2,q);
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
