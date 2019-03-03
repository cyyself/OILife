#include <bits/stdc++.h>
using namespace std;
int main() {
	int r,h;
	scanf("%d%d",&r,&h);
	int ans = (h / r) * 2;
	double rem = r + h % r;
	if (rem >= sqrt(3) * 0.5 * r + r) ans += 3;
	else if (rem >= 1.5 * r) ans += 2;
	else ans += 1;
	printf("%d\n",ans);
	return 0;
}
