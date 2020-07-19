#include <bits/stdc++.h>
using namespace std;
char s[60];
char t[10];
char tmp[60];
int n;
bool check(int pos) {
	for (int i=0;i<n;i++) {
		tmp[i] = s[i];
		if (tmp[i] == '?') tmp[i] = 'z';
	}
	tmp[n] = '\0';
	for (int j=0;j<7;j++) tmp[pos+j] = t[j];
	int cnt = 0;
	for (int i=0;i+6<n;i++) {
		bool ok = true;
		for (int j=0;j<7;j++) if (tmp[i+j] != t[j]) ok = false;
		cnt += ok;
	}
	return cnt == 1;
}
int main() {
	t[0] = 'a';
	t[1] = 'b';
	t[2] = 'a';
	t[3] = 'c';
	t[4] = 'a';
	t[5] = 'b';
	t[6] = 'a';
	t[7] = '\0';
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		scanf("%s",s);
		bool ans = false;
		for (int i=0;i+6<n;i++) {
			int cnt = 0;
			for (int j=0;j<7;j++) if (s[i+j] == '?' || s[i+j] == t[j]) {
				cnt ++;
			}
			if (cnt == 7) {
				if (check(i)) {
					ans = true;
					printf("Yes\n");
					printf("%s\n",tmp);
					break;
				}
			}
		}
		if (!ans) printf("No\n");
	}
	return 0;
}
