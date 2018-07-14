#include <bits/stdc++.h>
bool jud[256];
char s[105];
int main() {
	jud['a'] = 1;
	jud['e'] = 1;
	jud['i'] = 1;
	jud['o'] = 1;
	jud['u'] = 1;
	scanf("%s",s);
	int len =strlen(s);
	bool ans = true;
	for (int i=0;i<len;i++)
		if (!jud[s[i]] && s[i] != 'n' && !jud[s[i+1]])
			ans = false;

	/*
	for (int i=0;i<len;i++) {
		printf("%c %d\n",s[i],jud[s[i]]);
	}
	*/
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}
