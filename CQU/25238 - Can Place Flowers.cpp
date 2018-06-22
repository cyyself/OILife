#include <bits/stdc++.h>
bool s[20005];
int len = 0;
bool get() {
	char c = getchar();
	if (c == EOF) return false;
	while (c != '[') {
		c = getchar();
		if (c == EOF) return false;
	}
	c = getchar();
	while (c != ']') {
		if (c == ',') {
			c = getchar();
			continue;
		}
		s[len++] = c-'0';
		c = getchar();
	}
	return true;
}
int main() {
	while (get()) {
		int n;
		scanf("%d",&n);
		int avail = 0;
		if (!s[0] && !s[1]) {
			s[0] = true;
			avail ++;
		}
		for (int i=1;i<=len-2;i++) if (!s[i] && !s[i-1] && !s[i+1]) {
			s[i] = true;
			avail ++;
		}
		if (!s[len-1] && !s[len-2]) {
			s[len-1] = true;
			avail ++;
		}
		if (avail >= n) puts("true");
		else puts("false");
		len = 0;
	}
	return 0;
}
