#include <bits/stdc++.h>
char s1[200005];
char s2[100005];
int nxt[100005];
int n,m;
void getnext() {
	nxt[0] = -1;
	int k = -1;
	for (int i=1;i<m;i++) {
		while (k != -1 && s2[k+1] != s2[i]) k = nxt[k];
		if (s2[k+1] == s2[i]) k++;
		nxt[i] = k;
	}
}
int main() {
	while (scanf("%s%s",s1,s2) == 2) {
		n = strlen(s1);
		m = strlen(s2);
		for (int i=0;i<n;i++) s1[n+i] = s1[i];
		n *= 2;
		getnext();
		int k = -1;
		bool ans = false;
		for (int i=0;i<n;i++) {
			while (k != -1 && s2[k+1] != s1[i]) k = nxt[k];
			if (s2[k+1] == s1[i]) k++;
			if (k == m - 1) {
				ans = true;
				break;
			}
		}
		if (ans) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
