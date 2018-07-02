#include <bits/stdc++.h>
using namespace std;
map <int,bool> mem;
int main() {
	int n;
	scanf("%d",&n);
	int ans = 0;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		if (t != 0) {
			if (!mem[t]) {
				mem[t] = true;
				ans ++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}