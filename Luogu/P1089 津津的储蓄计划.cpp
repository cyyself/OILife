#include <cstdio>
int main() {
	int curr = 0;
	int mother = 0;
	for (int i=0;i<12;i++) {
		int t;
		scanf("%d",&t);
		curr += 300 - t;
		if (curr < 0) {
			printf("%d\n",-i-1);
			return 0;
		}
		else {
			int h = curr / 100;
			mother += 100 * h;
			curr -= h * 100;
		}
	}
	curr += mother * 1.2;
	printf("%d\n",curr);
	return 0;
}