#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
	int n;
	scanf("%d%s",&n,s);
	if (n & 1) {
		puts("No");
	}
	else {
		int lcnt = 0;
		for (int i=0;s[i];i++) if (s[i] == '(') lcnt ++;
		if (lcnt != n / 2) puts("No");
		else {
			int err = 0;
			int cnt = 0;
			for (int i=0;s[i];i++) {
				if (s[i] == '(') {
					cnt ++;
				}
				else {
					cnt --;
					err = max(err,-cnt);
				}
			}
			if (err == 0 || err == 1) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
