#include <cstdio>
int f[1000005];
int main() {
	int n;
	scanf("%d",&n);
	f[0] = 1;
	for (register int k=1;k<=n;k<<=1) for (register int j=k;j<=n;j++) {
		f[j] += f[j-k];
		f[j] %= 1000000000;
	}
	printf("%d\n",f[n]);
	return 0;
}
