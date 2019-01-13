#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		int ans = n;
		for (int i=0;i<n;i++) {
			long long sum = a[i];
			long long mul = a[i];
			for (int j=i+1;j<n;j++) {
				sum += a[j];
				mul *= a[j];
				if (mul > 1e31) break;
				if (sum == mul) ans ++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
