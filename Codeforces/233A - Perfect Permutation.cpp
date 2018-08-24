#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	if (n & 1) {
		printf("-1\n");
		return 0;
	}
	else {
		for (int i=2;i<=n;i+=2) printf("%d %d ",i,i-1);
		printf("\n");
		return 0;
	}
	return 0;
}
