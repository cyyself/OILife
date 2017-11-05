//到https://daniu.luogu.org 交题，有O2加成
#include <bits/stdc++.h>
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long ret = exgcd(b,a%b,y,x);
		y -= x*(a/b);
		return ret;
	}
}
int main() {
	int n,p;
	scanf("%d%d",&n,&p);
	long long x,y;
	for (int i=1;i<=n;i++) {
		exgcd(i,p,x,y);
		x = (x + p) % p;
		printf("%lld\n",x);
	}
	return 0;
}
