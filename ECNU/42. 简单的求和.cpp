#include <bits/stdc++.h>
int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	if (a + b > __INT_MAX__) printf("-1\n");
	else printf("%lld\n",a+b);
	return 0;
}
