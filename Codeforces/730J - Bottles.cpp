#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int a,b;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.b > b.b;
	}
}d[101];
int f[101][100*100];
int main() {
	int n;
	scanf("%d",&n);
	int sum = 0;
	int sumb = 0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&d[i].a);
		sum += d[i].a;
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&d[i].b);
		sumb += d[i].b;
	}
	sort(d+1,d+1+n);
	int k = 0;
	int cur = 0;
	while (cur < sum) cur += d[++k].b;
	memset(f,0x80,sizeof(f));
	for (int i=0;i<=k;i++) f[i][0] = 0;
	for (int i=1;i<=n;i++) {
		for (int j=k;j>=1;j--) 
			for (int k=sumb;k>=d[i].b;k--) 
				f[j][k] = max(f[j][k],f[j-1][k-d[i].b]+d[i].a);
	}
	int ans = 0x80000000;
	for (int i=sum;i<=sumb;i++) ans = max(ans,f[k][i]);
	printf("%d %d\n",k,sum-ans);
	return 0;
}
