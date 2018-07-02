#include <bits/stdc++.h>
int main() {
	int a,b,c,n;
	scanf("%d%d%d%d",&a,&b,&c,&n);
	a -= c;
	b -= c;
	if (a < 0 || b < 0) {
		printf("-1\n");
		return 0;
	}
	if (a + b + c >= n) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n",n-a-b-c);
	return 0;
}