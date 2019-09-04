#include <bits/stdc++.h>
using namespace std;
int main() {
	int b,g,n;
	scanf("%d%d%d",&b,&g,&n);
	int ans = 0;
	for (int i=0;i<=n;i++) {
		int j = n - i;
		if (i > b || j > g) continue;
		ans ++;
	}
	printf("%d\n",ans);
	return 0;
}
