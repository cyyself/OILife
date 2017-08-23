#include <cstdio>
int main() {
	int k;
	scanf("%d",&k);
	double sn = 0;
	int i = 0;
	while(++i) {
		sn += 1.0/i;
		if (sn > k) break;
	}
	printf("%d\n",i);
	return 0;
}