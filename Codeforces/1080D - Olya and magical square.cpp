/*
一个长度为pow2(n)的方块最大切割次数=(pow4(n)-1)/3

比赛的时候想到了可以枚举ans然后去判断是否在范围内
但苦于n很大，1e3*1e9=1e12显然过不了
后来发现其实k<1e18就可以推出n>=32时一定可切为长度为n-1的路径

	log2(1e18) < 60
	(pow4(31)-1)/3 约等于 1.53e18 > 1e18

然后只要判断n<32时k是否在范围内就行了
*/
#include <bits/stdc++.h>
using namespace std;
inline long long pow2(long long x) {
	return 1LL << x;
}
inline long long pow4(long long x) {
	return 1LL << (x * 2LL);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,k;
		scanf("%lld%lld",&n,&k);
		if (n >= 32) printf("YES %lld\n",n-1);
		else {
			//1,3,7,15,31,...,2**n-1
			//sigma = 2**(n+1)-2-n
			int ans = -1;
			int step = 1;
			for (long long i=n-1,step=1;i>=0 && ans == -1;i--,step++) {
				long long lower = pow2(step+1) - 2LL - step;//要切成路径为i的路至少要切的次数
				//上界=一共可以切的次数-路径上的方块数*该长度的方块可以切的次数
				long long upper = (pow4(n) - 1LL) / 3 - (pow2(step+1) - 1) * ((pow4(i) - 1) / 3);
				if (k >= lower && k <= upper) ans = i;
			}
			if (ans == -1) printf("NO\n");
			else printf("YES %d\n",ans);
		}
	}
	return 0;
}
