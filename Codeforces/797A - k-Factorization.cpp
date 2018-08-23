#include <bits/stdc++.h>
using namespace std;
vector <int> zys;
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int m = sqrt(n) + 0.5;
	for (int i=2;i<=n;i++) {
		while (n % i == 0) {
			zys.push_back(i);
			n /= i;
		}
	}
	if (n > 1) zys.push_back(n);
	if (zys.size() < k) printf("-1\n");
	else {
		int cnt = 0;
		int rem = 1;
		for (auto i:zys) {
			if (cnt < k - 1) {
				if (cnt != 0) printf(" ");
				printf("%d",i);
				cnt ++;
			}
			else rem *= i;
		}
		if (rem != 1) {
			if (cnt != 0) printf(" ");
			printf("%d",rem);
		}
		printf("\n");
	}
	return 0;
}
