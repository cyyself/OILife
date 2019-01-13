#include <bits/stdc++.h>
using namespace std;
bool exist[20005];
int pre[10005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		memset(exist,false,sizeof(exist));
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			pre[i] = pre[i-1] + (x == 2);
		}
		for (int i=1;i<=n;i++) 
			for (int j=i;j<=n;j++) {
				int cur = (j - i + 1) + pre[j] - pre[i-1];
				exist[cur] = true;
			}
		int ans = 0;
		for (int i=1;i<=2*n;i++) if (exist[i]) ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
