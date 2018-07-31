//相当于做完全背包，背包容量为N，3中物品重量均为1，价值分别为1、2、3，求方案数
#include <bits/stdc++.h>
long long f[32768];
int main() {
	f[0] = 1;
	for (int i=1;i<=3;i++) {
		for (int j=i;j<32768;j++) f[j] += f[j-i];
	}
	int n;
	while (scanf("%d",&n) == 1) {
		printf("%lld\n",f[n]);
	}
	return 0;
}
