#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	long long ans = n;
	for (int i=2;i<=n;i++) ans = ((ans-1) * i) % 998244353;
	printf("%lld\n",(ans+998244353)%998244353);
	return 0;
}
