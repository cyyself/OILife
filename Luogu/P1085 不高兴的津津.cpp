#include <cstdio>
int main() {
	int max=0,maxd=0;
	for (int i=1;i<=7;++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (a + b > max) {
			max = a + b;
			maxd = i;
		}
	}
	printf("%d",maxd);
	return 0;
}