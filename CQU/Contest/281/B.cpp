#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		bool exist = false;
		while (n) {
			if (n % 10 == 0 && !exist) {
				n /= 10;
				continue;
			}
			printf("%d",n%10);
			exist = true;
			n /= 10;
		}
		if (!exist) printf("0");
		printf("\n");
	}
	return 0;
}
