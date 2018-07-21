#include <cstdio>
int f[1000005];
int main() {
	int n;
	f[0] =  7 % 3;
	f[1] = 11 % 3;
	for (int i=2;i<1000000;i++) f[i] = (f[i-1] + f[i-2])%3;
	while (scanf("%d",&n) == 1) {
		if (f[n] == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}