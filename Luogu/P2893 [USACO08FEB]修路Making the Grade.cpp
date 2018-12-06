#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[2000];
int ls[2000];
int cnt;
int f[2000];
int n;
int cal() {
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++) {
		int pre = INF;
		for (int j=0;j<cnt;j++) {
			pre = min(pre,f[j]);
			f[j] = pre + abs(a[i]-ls[j]);
		}
	}
	int ans = INF;
	for (int i=0;i<cnt;i++) ans = min(ans,f[i]);
	return ans;
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		ls[i] = a[i];
	}
	sort(ls,ls+n);
	cnt = unique(ls,ls+n) - ls;
	int ans = cal();
	reverse(a,a+n);
	ans = min(ans,cal());
	printf("%d\n",ans);
	return 0;
}
