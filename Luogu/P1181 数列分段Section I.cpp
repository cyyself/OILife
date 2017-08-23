#include <cstdio>
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int ans = 0;
	int curr = 0;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		curr += t;
		if (curr > m) {
			ans ++;
			curr = t;
		}
	}
	if (curr > 0) ans++;
	printf("%d\n",ans);
	return 0;
}