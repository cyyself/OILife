#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char aa[maxn],bb[maxn];
int a[maxn],b[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		scanf("%s%s",aa+1,bb+1);
		for (int i=1;i<=n;i++) {
			a[i] = aa[i] - '0';
			b[i] = bb[i] - '0';
		}
		vector <int> ans;
		int l = 1, r = n;
		bool rev = false;
		for (int i=n;i>=2;i--) {
			int cur = a[rev?l:r] ^ rev;
			if (cur != b[i]) {
				int fi = a[rev?r:l] ^ rev;
				if (fi == b[i]) ans.push_back(1);
				ans.push_back(i);
				if (rev) r --;
				else l ++;
				rev ^= 1;
			}
			else {
				if (rev) l ++;
				else r --;
			}
		}
		if ((a[rev?r:l] ^ rev) != b[1]) {
			ans.push_back(1);
		}
		printf("%d",(int)ans.size());
		for (auto x:ans) printf(" %d",x);
		printf("\n");
	}
	return 0;
}
