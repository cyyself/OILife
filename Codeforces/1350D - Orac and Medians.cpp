#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int arr[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		bool exist_0 = false;
		for (int i=1;i<=n;i++) {
			scanf("%d",&arr[i]);
			if (arr[i] < k) arr[i] = -1;
			else if (arr[i] > k) arr[i] = 1;
			else {
				arr[i] = 0;
				exist_0 = true;
			}
		}
		if (n == 1) {
			if (exist_0) printf("yes\n");
			else printf("no\n");
		}
		else {
			if (!exist_0) printf("no\n");
			else {
				bool ok = false;
				for (int i=1;i<=n;i++) if (arr[i] >= 0)
					for (int j=i+1;j<=min(i+2,n);j++) if (arr[j] >= 0) ok = true;
				if (ok) printf("yes\n");
				else printf("no\n");
			}
		}
	}
	return 0;
}
