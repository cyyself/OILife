
#include <bits/stdc++.h>
using namespace std;
int ans[105];
int n;
bool check(int x) {
	int rem = n - x;
	if (rem < 0) return false;
	int all = 1;
	for (int i=x-1;i>=1;i--) {
		int need = min(all,rem / i);
		all += need;
		rem -= need * i;
		ans[i] = need;
	}
	return rem == 0;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		bool ok = false;
		for (int i=2;i<=100;i++) {
			if (check(i)) {
				ok = true;
				printf("%d\n",i-1);
				for (int j=i-1;j>=1;j--) printf("%d ",ans[j]);
				printf("\n");
				break;
			}
		}
		if (!ok) printf("-1\n");
	}
	return 0;
}
