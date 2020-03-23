#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
bool visl[maxn],visr[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			visl[i] = visr[i] = false;
		}
		int mt = 0;
		for (int i=1;i<=n;i++) {
			int k;
			scanf("%d",&k);
			for (int j=0;j<k;j++) {
				int t;
				scanf("%d",&t);
				if (!visr[t] && !visl[i]) {
					visr[t] = true;
					visl[i] = true;
					mt ++;
				}
			}
		}
		if (mt == n) printf("OPTIMAL\n");
		else {
			printf("IMPROVE\n");
			int l = n , r = n;
			while (visl[l]) l --;
			while (visr[r]) r --;
			printf("%d %d\n",l,r);
		}
	}
	return 0;
}
