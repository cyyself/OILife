#include <bits/stdc++.h>
using namespace std;
int n;
int v[105];
int t[105];
queue <int> q[2];
int main() {
	while (scanf("%d",&n) == 1) {
		while (!q[0].empty()) q[0].pop();
		while (!q[1].empty()) q[1].pop();
		for (int i=0;i<n;i++) scanf("%d",&v[i]);
		for (int i=0;i<n;i++) scanf("%d",&t[i]);
		for (int i=0;i<n;i++) {
			int ans = 0;
			if (t[i] >= v[i]) {
				ans += v[i];
			}
			else {//t[i] < v[i]
				ans += t[i];
				q[i%2].push(v[i]-t[i]);
			}
			while (!q[(i+1)%2].empty()) {
				int cur = q[(i+1)%2].front();
				q[(i+1)%2].pop();
				if (t[i] >= cur) {
					ans += cur;
				}
				else {//t[i] < cur
					ans += t[i];
					q[i%2].push(cur-t[i]);
				}
			}
			if (i != 0) printf(" ");
			printf("%d",ans);
		}
		printf("\n");
	}
	return 0;
}
