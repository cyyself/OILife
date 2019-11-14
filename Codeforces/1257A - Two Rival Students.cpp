#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,x,a,b;
		scanf("%d%d%d%d",&n,&x,&a,&b);
		if (a > b) swap(a,b);
		int curdis = b - a;
		int mxdelta = a - 1 + n - b;
		printf("%d\n",curdis + min(mxdelta,x));
	}
	return 0;
}
