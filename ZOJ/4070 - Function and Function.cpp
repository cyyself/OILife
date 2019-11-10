#include <bits/stdc++.h>
using namespace std;
int biao[10] = {1,0,0,0,1,0,1,0,2,1};
int f(int x) {
	if (x == 0) return 1;
	int res = 0;
	while (x) {
		res += biao[x%10];
		x /= 10;
	}
	return res;
}
int g[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		g[0] = n;
		for (int i=1;i<=100;i++) g[i] = f(g[i-1]);
		if (k <= 100) printf("%d\n",g[k]);
		else {
			if (k & 1) printf("%d\n",g[99]);
			else printf("%d\n",g[100]);
		}
	}
	return 0;
}
