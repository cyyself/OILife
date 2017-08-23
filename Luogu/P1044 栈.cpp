#include <cstdio>
unsigned long long h[20];
int main() {
	int n;
	scanf("%d",&n);
	h[0] = 1;
	h[1] = 1;
	for (int i=2;i<=n;i++) h[i] = (h[i-1] * 2 * (2 * i - 1)) / (i + 1);
	printf("%llu\n",h[n]);
	return 0;
}