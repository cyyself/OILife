#include <bits/stdc++.h>
char s[105];
bool color[105][3];
int main() {
	scanf("%s",s);
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		if (s[i] != '.') {
			color[i][s[i]-'A'] = true;//left
			color[i+1][s[i]-'A'] = true;
			color[i+2][s[i]-'A'] = true;//right
		}
	}
	for (int i=1;i<=len;i++) {
		if (color[i][0] && color[i][1] && color[i][2]) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}