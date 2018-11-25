#include <bits/stdc++.h>
using namespace std;
long long getsum(int x) {
	long long ret = x / 2;
	if (x & 1) ret += -x;
	return ret;
}
int main() {
	int q;
	scanf("%d",&q);
	while (q --) {
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",getsum(r)-getsum(l-1));
	}
	return 0;
}
