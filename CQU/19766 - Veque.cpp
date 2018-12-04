#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int f[2][100005];//0=>lds 1=>lis
/*
	f[0][i]表示以i为后缀，以a[i]为最大值，lds的长度
	f[1][i]表示以i为后缀，以a[i]为最小值，lis的长度
*/
int same[2][100005];
int tmp[100005];
void work(int type) {
	memset(tmp,0x3f,sizeof(tmp));
	for (int i=n-1;i>=0;i--) {
		int pos = upper_bound(tmp,tmp+n,a[i]) - tmp;
		tmp[pos] = a[i];
		f[type][i] = pos+1;
		auto lr = equal_range(tmp,tmp+n,a[i]);
		same[type][i] = lr.second - lr.first;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		work(0);
		for (int i=0;i<n;i++) a[i] = -a[i];
		work(1);
		int ans = 0;
		for (int i=0;i<n;i++) ans = max(ans,f[0][i] + f[1][i] - min(same[0][i],same[1][i]));
		printf("%d\n",ans);
	}
	return 0;
}
