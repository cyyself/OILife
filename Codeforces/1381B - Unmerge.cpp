#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
int arr[maxn];
bool f[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=2*n;i++) {
			scanf("%d",&arr[i]);
			f[i] = 0;
		}
		int last = 1;
		vector <int> all;
		for (int i=2;i<=2*n;i++) {
			if (arr[i] > arr[last]) {
				all.push_back(i - last);
				last = i;
			}
		}
		all.push_back(2*n+1-last);
		f[0] = 1;
		for (auto x:all) {
			for (int j=n;j>=x;j--) f[j] |= f[j-x];
		}
		if (f[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
