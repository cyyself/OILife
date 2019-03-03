#include <bits/stdc++.h>
using namespace std;
int main() {
	int cnt[2] = {0,0};
	int n;
	scanf("%d",&n);
	bool ok = true;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		if (x == 25) {
			cnt[0] ++;
		}
		else if (x == 50) {
			if (cnt[0]) {
				cnt[0] --;
				cnt[1] ++;
			}
			else ok = false;
		}
		else if (x == 100) {
			if (cnt[0] && cnt[1]) {
				cnt[0] --;
				cnt[1] --;
			}
			else if (cnt[0] >= 3) {
				cnt[0] -= 3;
			}
			else ok = false;
		}
	}
	if (ok) puts("YES");
	else puts("NO");
	return 0;
}
