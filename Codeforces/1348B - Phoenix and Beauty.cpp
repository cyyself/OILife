#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		set <int> s;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		if (k == n) {
			printf("%d\n",n);
			for (int i=0;i<n;i++) printf("%d ",a[i]);
			printf("\n");
		}
		else {
			if (s.size() > k) {
				printf("-1\n");
			}
			else {
				for (int i=1;i<=n && s.size() < k;i++) {
					s.insert(i);
				}
				printf("%d\n",k*n);
				for (int i=1;i<=n;i++) {
					for (auto x:s) printf("%d ",x);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
