#include <bits/stdc++.h>
char s[100005];
int main() {
	scanf("%s",s);
	int len = strlen(s);
	int len2 = len;
	for (int i=0;i<len;i++) if (s[i] == '2') {
		len2 = i;
		break;
	}

	int cnt_0 = 0;
	int cnt_1 = 0;
	for (int i=0;i<len2;i++) if (s[i] == '0') cnt_0 ++;
	for (int i=0;i<len;i++) if (s[i] == '1') cnt_1 ++;
	for (int i=1;i<=cnt_0;i++) printf("0");
	for (int i=1;i<=cnt_1;i++) printf("1");

	for (int i=len2;i<len;i++) {
		if (s[i] == '1') continue;
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}
