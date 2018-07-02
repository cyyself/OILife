#include <bits/stdc++.h>
char s[2005];
char g[2005][2005];
int unknown_cnt[2005];
char known_value[2005];
char first_char[2005];
int main() {
	int n,p;
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	bool flag = true;
	for (int i=0;i<p;i++) {
		for (int j=i;j<n;j+=p) {
			g[i][(j-i)/p] = s[j];
			if (s[j] == '.') unknown_cnt[i] ++;
			else {
				if (known_value[i] != '\0' && known_value[i] != s[j]) flag = false;
				known_value[i] = s[j];
			}
		}
	}
	for (int i=0;i<p;i++) {
		if (known_value[i] == '\0') {
			if (unknown_cnt[i] > 1) {
				flag = false;
				int cur = 0;
				for (int j=0;g[i][j] != '\0';j++) {
					if (g[i][j] == '.') {
						g[i][j] = cur + 48;
						cur = (cur + 1) % 2;
					}
				}
			}
		}
		else {
			if (unknown_cnt[i] >= 1) {
				flag = false;
				for (int j=0;g[i][j] != '\0';j++) {
					if (g[i][j] == '.') g[i][j] = 48 + (known_value[i] - 48 + 1) % 2;
				}
			}
		}
	}
	if (flag) {
		printf("No\n");
	}
	else {
		int i = 0;
		int j = 0;
		while (true) {
			while (true) {
				if (g[i][j] == '.') g[i][j] = '0';
				printf("%c",g[i][j]);
				i ++;
				if (g[i][j] == '\0') break;
			}
			i = 0;
			j++;
			if (g[i][j] == '\0') break;
		}
	}
	return 0;
}