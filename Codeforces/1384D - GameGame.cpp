#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int cnt[31][2];
int a[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int j=0;j<=30;j++) cnt[j][0] = cnt[j][1] = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			for (int j=0;j<=30;j++) cnt[j][(a[i]>>j)&1] ++;
		}
		int high_bit = -1;
		for (int i=30;i>=0;i--) if(cnt[i][1] & 1) {
			high_bit = i;
			break;
		}
		if (high_bit == -1) printf("DRAW\n");
		else {
			if (cnt[high_bit][1] % 4 == 3 && cnt[high_bit][0] % 2 == 0) printf("LOSE\n");
			else printf("WIN\n");
		}
	}
	return 0;
}
