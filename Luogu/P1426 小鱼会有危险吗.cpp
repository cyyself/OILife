#include <cstdio>
int main() {
	int s,x;
	scanf("%d%d",&s,&x);
	double d = 7;
	int pos = 0;
	while (pos < s - x) {
		pos += d;
		d *= 0.98;
	}
	if (pos + d > s + x) printf("n\n");
	else printf("y\n");
	return 0;
}