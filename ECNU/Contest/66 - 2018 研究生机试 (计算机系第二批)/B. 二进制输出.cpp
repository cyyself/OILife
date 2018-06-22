#include <bits/stdc++.h>
int main() {
	int n;
	scanf("%d",&n);
	for (int i=7;i>=0;i--) {
		printf("%d",n & (1 << i)?1:0);
	}
	return 0;
}