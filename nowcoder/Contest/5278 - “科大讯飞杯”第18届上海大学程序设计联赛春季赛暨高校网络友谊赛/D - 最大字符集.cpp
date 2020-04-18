#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	if (n == 1) printf("1\n1\n");
	else if (n == 2) printf("2\n0\n11\n");
	else {
		printf("%d\n",n-1);
		for (int i=2;i<=n;i++) {
			printf("1");
			for (int j=0;j<i-2;j++) printf("0");
			printf("1\n");
		}
	}
	return 0;
}
