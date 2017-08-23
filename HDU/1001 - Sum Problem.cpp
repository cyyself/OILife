#include <cstdio>
long long sum(int n) {
	return (long long)n*(n+1)/2;
}
int main() {
	int n;
	while (scanf("%d",&n) == 1) printf("%lld\n\n",sum(n));
	return 0;
}