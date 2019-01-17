#include <bits/stdc++.h>
using namespace std;
int a[2];
int b[2];
int main() {
	scanf("%d%d%d%d",&a[0],&a[1],&b[0],&b[1]);
	if (b[0] >= a[1] - 1 && b[0] < 2 * a[1] + 3) {
		printf("YES\n");
		return 0;
	}
	if (b[1] >= a[0] - 1 && b[1] < 2 * a[0] + 3) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}
