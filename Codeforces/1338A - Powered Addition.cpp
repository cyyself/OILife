#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long arr[maxn];
int main() {
	arr[0] = -0x8000000000000000;
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		long long ans = 0;
		for (int i=1;i<=n;i++) {
			scanf("%lld",&arr[i]);
			if (arr[i] < arr[i-1]) {
				ans = max(ans,arr[i-1]-arr[i]);
				arr[i] = arr[i-1];
			}
		}
		int aans = 0;
		while (ans) {
			ans >>= 1;
			aans ++;
		}
		printf("%d\n",aans);
	}
	return 0;
}
