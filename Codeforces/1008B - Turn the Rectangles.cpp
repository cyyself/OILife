#include <bits/stdc++.h>
int main() {
	int n;
	scanf("%d",&n);
	int last = 0x3fffffff;
	bool ans = true;
	while (n--) {
		int w,h;
		scanf("%d%d",&w,&h);
		if (w > h) std::swap(w,h);
		if (h <= last) last = h;
		else {
			if (w <= last) last = w;
			else {
				ans = false;
				break;
			}
		}
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}
