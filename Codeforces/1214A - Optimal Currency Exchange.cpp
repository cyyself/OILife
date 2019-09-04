#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,d,e;
	scanf("%d%d%d",&n,&d,&e);
	e *= 5;
	int ans = n;
	for (int i=0;i<=(n/d);i++) {
		int j = (n - i * d) / e;
		ans = min(ans,n - i * d - e * j);
	}
	printf("%d\n",ans);
	return 0;
}
