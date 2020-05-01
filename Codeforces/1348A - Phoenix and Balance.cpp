
#include <bits/stdc++.h>
using namespace std;
long long ans[]={2,6,14,30,62,126,254,510,1022,2046,4094,8190,16382,32766,65534};
int main() {
	int t;
	scanf("%d",&t);
	while (t --) {
		int n;
		scanf("%d",&n);
		printf("%lld\n",ans[(n-2)/2]);
	}
	return 0;
}
