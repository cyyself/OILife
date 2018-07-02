#include <bits/stdc++.h>
using namespace std;
int f[105];
int main() {
	int n;
	for (int i=0;i<2;i++) {
		string t;
		cin >> t;
		n = t.length();
		for (int i=1;i<=n;i++) f[i] += t[i-1]=='0'?1:0;
	}
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (f[i] == 2) {
			if (f[i-1]) {
				f[i-1] --;
				f[i] = 0;
				ans ++;
			}
			else if (f[i+1]) {
				f[i+1] --;
				f[i] = 0;
				ans ++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}