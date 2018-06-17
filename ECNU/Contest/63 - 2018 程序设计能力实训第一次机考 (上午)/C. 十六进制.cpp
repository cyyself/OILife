#include <bits/stdc++.h>
char s[100005];
bool judge_hex(char c) {
	return ( (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'));
}
unsigned int to10(char c) {
	if (c <= '9') return c-'0';
	return 10+c-'a';
}
int main() {
	scanf("%s",s);
	int len = strlen(s);
	unsigned int tmp = 0;
	bool read = false;
	bool exist = false;
	for (int i=0;i<len;i++) {
		if (!judge_hex(s[i])) {
			if (read) {
				printf("%u ",tmp);
				exist = true;
				read = false;
			}
		}
		else {
			if (read) {
				tmp *= 16;
				tmp += to10(s[i]);
			}
			else {
				if (s[i] == '0' && s[i+1] == 'x' && judge_hex(s[i+2])) {
					i += 1;
					if (read) {
						printf("%u ",tmp);
						exist = true;
					}
					read = true;
					tmp = 0;
				}
			}
		}
	}
	if (read) {
		printf("%u",tmp);
		exist = true;
	}
	if (!exist) printf("-1");
	printf("\n");
	return 0;
}
