#include <bits/stdc++.h>
int main() {
	int n;
	bool ans = false;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		if (t) ans = true;
	}
	if (!ans) printf("EASY\n");
	else printf("HARD\n");
	return 0;
}
