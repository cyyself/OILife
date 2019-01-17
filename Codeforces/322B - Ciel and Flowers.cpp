#include <bits/stdc++.h>
using namespace std;
int main() {
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	int t = min(r,min(g,b));
	int ans = 0;
	for (int i=0;i<=min(2,t);i++) {
		int cur = i + (r - i) / 3 + (g - i) / 3 + (b - i) / 3;
		ans = max(cur,ans);
	}
	printf("%d\n",ans);
	return 0;
}
