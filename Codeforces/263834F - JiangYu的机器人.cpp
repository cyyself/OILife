#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k,x,y;
		scanf("%d%d%d%d",&n,&k,&x,&y);
		int dis1 = abs(x - y);
		int dis2 = y - 1;
		int dis3 = n - y;
		if (dis1 % k == 0 || dis2 % k == 0 || dis3 % k == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
