#include <cstdio>
int main() {
	int n;
	int m[3];
	int p[3];
	scanf("%d",&n);
	for (int i=0;i<3;i++) scanf("%d%d",&m[i],&p[i]);
	int ans = 0x7fffffff;
	for (int i=0;i<3;i++) {
		int k = n / m[i];
		if (n % m[i] != 0) k++;
		if (k * p[i] < ans) ans = k * p[i];
	}
	printf("%d\n",ans);
	return 0;
}