#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
	scanf("%s",s);
	int len = strlen(s);
	int cur = 1;
	for (int i=1;i<len;i++) {
		cur *= 2;
		cur %= 1000000007;
	}
	int ans = 0;
	for (int i=len-1;i>=0;i--) {
		if (s[i] == '1') {
			ans += cur;
			ans %= 1000000007;
		}
		cur *= 2;
		cur %= 1000000007;
	}
	printf("%d\n",ans);
	return 0;
}
