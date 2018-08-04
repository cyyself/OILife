#include <bits/stdc++.h>
char s[2005];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",&s[1]);
	int ans = 0;
	int len = strlen(&s[1]);
	for (int j=1;j<=len;j++) {
		if (j % n == 1)
			if (j >= 4 && s[j-1] == s[j-2] && s[j-2] == s[j-3]) ans ++;
	}
	printf("%d\n",ans);
	return 0;
}
