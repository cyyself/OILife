#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		bool flag = false;
		for (int i=1;i<=n;i++) {
			int t;
			scanf("%d",&t);
			if (t == i) {
				if (flag) printf(" ");
				printf("%d",i);
				flag = true;
			}
		}
		if (!flag) printf("No Mistake");
		printf("\n");
	}
	return 0;
}
