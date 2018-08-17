#include <bits/stdc++.h>
using namespace std;
char s[200005];
char t[200005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	int wildpos = -1;
	int slen = strlen(s);
	int tlen = strlen(t);
	for (int i=0;i<slen;i++) {
		if (s[i] == '*') {
			wildpos = i;
			break;
		}
	}
	bool ans = true;
	if (wildpos == -1) {
		if (slen != tlen) ans = false;
		else {
			for (int i=0;i<slen;i++) {
				if (s[i] != t[i]) ans = false;
				break;
			}
		}
	}
	for (int i=0;i<wildpos;i++) {
		if (s[i] != t[i]) {
			ans = false;
			break;
		}
		else t[i] = '\0';
	}
	int j = tlen -1;
	for (int i=slen-1;i>wildpos;i--) {
		if (j < 0) {
			ans = false;
			break;
		}
		if (s[i] != t[j]) {
			ans = false;
			break;
		}
		j--;
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}
