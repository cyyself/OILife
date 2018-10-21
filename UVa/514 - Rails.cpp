#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		while (scanf("%d",&a[0]) == 1) {
			if (a[0] == 0) break;
			for (int i=1;i<n;i++) scanf("%d",&a[i]);
			int cur = 1;
			stack <int> s;
			s.push(cur);
			cur ++;
			bool flag = true;
			for (int i=0;i<n && flag;i++) {
				while ( (s.empty() || s.top() != a[i]) && cur <= n) {
					s.push(cur);
					cur ++;
				}
				if (s.top() == a[i]) {
					s.pop();
				}
				else flag = false;
			}
			if (flag) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
