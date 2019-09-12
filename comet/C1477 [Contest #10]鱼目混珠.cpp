#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
	int ans = 0;
	int n;
	scanf("%d",&n);
	while (n --) {
		scanf("%s",s);
		int len = strlen(s);
		if (len >= 5) {
			if (s[len-1] == 'y' && s[len-2] == 't' && s[len-3] == 'p' && s[len-4] == 'c' && s[len-5] == 'a') {
				ans ++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
