#include <bits/stdc++.h>
using namespace std;
bool h[1005];
int main() {
	int n,r;
	scanf("%d%d",&n,&r);
	for (int i=0;i<n;i++) {
		char c;
		scanf(" %c",&c);
		h[i] = (c == '1');
	}
	int last = -1;//上次覆盖的最右端点
	int hpos = -1;
	int i = 0;
	bool ok = true;
	int ans = 0;
	while (i < n) {
		if (h[i] == 1) hpos = i;
		if (i - last == r) {
			if (hpos > last - r + 1 && hpos != -1) {
				ans ++;
				last = hpos + r - 1;
			}
			else {
				ok = false;
				break;
			}
		}
		i ++;
	}
	if (last < n - 1) {
		if (hpos + r - 1 >= n - 1 && hpos != -1) ans ++;
		else ok = false;
	}
	if (!ok) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
