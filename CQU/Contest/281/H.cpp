#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		int ans = 1 << n;
		printf("%d\n",ans);
	}
	return 0;
}
