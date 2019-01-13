#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		int m = 0x3f3f3f3f;
		for (int i=0;i<n;i++) {
			int x;
			scanf("%d",&x);
			m = min(m,x);
		}
		printf("%d\n",m*(n-1));
	}
	return 0;
}
