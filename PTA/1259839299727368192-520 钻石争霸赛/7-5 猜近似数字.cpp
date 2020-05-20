#include <bits/stdc++.h>
using namespace std;
char s[1005];
int slen;
char t[100005];
int main() {
	scanf("%s",s);
	slen = strlen(s);
	while (scanf("%s",t) == 1) {
		if (t[0] == '-') break;
		int len = strlen(t);
		if (len == slen) {
			int dcnt = 0;
			for (int i=0;i<slen;i++) if (s[i] != t[i]) {
				if (abs(s[i]-t[i]) <= 1) dcnt ++;
				else {
					dcnt = 2;
					break;
				}
			}
			if (dcnt <= 1) printf("Yes\n");
			else printf("No\n");
		}
		else printf("No\n");
	}
	return 0;
}
