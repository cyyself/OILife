#include <bits/stdc++.h>
using namespace std;
char a[200005];
char b[200005];
int pre[200005];//b的前缀的1的个数
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",a,b);
	pre[0] = (b[0] == '1');
	for (int i=1;i<m;i++) pre[i] = pre[i-1] + (b[i] == '1');
	long long xs = 1;
	long long ans = 0;
	for (int i=n-1,j=m-1;i>=0 && j >= 0;i--,j--) {
		if (a[i] == '1') ans += xs * pre[j];
		ans %= 998244353;
		xs <<= 1;
		xs %= 998244353;
	}
	printf("%lld\n",ans);
	return 0;
}
